#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define BUFFER_SIZE 10
#define MAX_STR_LEN 256
#define MAX_CHILD 20
#define MAX_THREADS 100

struct Message {
    char type;
    unsigned short int hash;
    unsigned char size;
    char* data;
};

extern pthread_t prodIdMas[];
extern pthread_t consIdMas[];
extern volatile sig_atomic_t sigTermSignalFlag;
extern int sizeQueue;

unsigned char generateRandomSize();
char* generateMessageData(short int size);
void displayData(struct Message msg);
struct Message* generateNewMessage();

void handleSIGUSR1(__attribute__((unused)) int signum);
void setSignalHandlerSIGTERM();

typedef struct {
    struct Message* buffer;
    int head;
    int tail;
    int countAdd;
    int countGet;
    pthread_cond_t empty;
    pthread_cond_t full;
    int countMsg;
    pthread_mutex_t mutex;
} MessageQueue;

typedef struct {
    struct Message* deletedMessages[100];
    int top;
} Stack;

void cleanupHandler();
void initializeQueue();
int checkIfEmpty();
int checkIfFull();
void pushMessage(struct Message* msg);
struct Message* popMessage();
void* producerTask();
void createProducerThread(int prodCount);
void* consumerTask();
void createConsumerThread(int consCount);
bool stopThread(pthread_t* childIdMas, int idThread);
void increaseQueueSize();
void decreaseQueueSize();

volatile sig_atomic_t sigTermSignalFlag = 0;

pthread_t prodIdMas[MAX_CHILD];
pthread_t consIdMas[MAX_CHILD];

int sizeQueue = 10;

unsigned char generateRandomSize() {
    short int randSize;
    for (randSize = rand() % 257; randSize == 0; );
    if (randSize == 256)
        randSize = 0;
    return randSize;
}

char* generateMessageData(short int size) {
    if (size == 0)
        size = 256;
    char* newMsg = (char*)malloc(sizeof(char) * (((size + 3) / 4) * 4));
    for (int i = 0; i < ((size + 3) / 4) * 4; i++) {
        newMsg[i] = 33 + rand() % 93;
    }
    return newMsg;
}

void displayData(struct Message msg) {
    printf("\n");
    for (int i = 0; i < (msg.size != 0 ? ((msg.size + 3) / 4 * 4) : 256); i++) {
        printf("%c", msg.data[i]);
    }
    printf("\n");
}

struct Message* generateNewMessage() {
    srand(time(NULL));
    struct Message* newMessage = (struct Message*)malloc(sizeof(struct Message));
    newMessage->type = 'S';
    newMessage->size = generateRandomSize();
    newMessage->data = generateMessageData(newMessage->size);
    unsigned short int hash = newMessage->type + newMessage->size;
    for (int i = 0; i < (newMessage->size != 0 ? ((newMessage->size + 3) / 4 * 4) : 256); i++) {
        hash += newMessage->data[i];
    }
    newMessage->hash = hash;
    return newMessage;
}

void handleSIGUSR1(__attribute__((unused)) int signum) {
    sigTermSignalFlag = 1;
    printf("\nworkSignal\n");
}

void setSignalHandlerSIGTERM() {
    struct sigaction saSIGUSR1;
    saSIGUSR1.sa_handler = handleSIGUSR1;
    if (sigaction(SIGUSR1, &saSIGUSR1, NULL) == -1) {
        perror("sigaction SIGTUSR1");
        exit(EXIT_FAILURE);
    }
}

Stack stack;
MessageQueue queue;

void cleanupHandler() {
    pthread_mutex_unlock(&queue.mutex);
}

void initializeQueue() {
    queue.buffer = (struct Message*)malloc(sizeof(struct Message) * sizeQueue);
    queue.head = 0;
    queue.tail = 0;
    queue.countAdd = 0;
    queue.countGet = 0;
    queue.countMsg = 0;
    pthread_cond_init(&queue.empty, NULL);
    pthread_cond_init(&queue.full, NULL);
    pthread_mutex_init(&queue.mutex, NULL);

    stack.top = -1;
}

int checkIfEmpty() {
    return stack.top == -1;
}

int checkIfFull() {
    return stack.top == 99;
}

void pushMessage(struct Message* msg) {
    if (checkIfFull()) {
        printf("Error: stack is full\n");
        return;
    }

    struct Message* newMsg = (struct Message*)malloc(sizeof(struct Message));
    memcpy(newMsg, msg, sizeof(struct Message));
    stack.deletedMessages[++stack.top] = newMsg;
    printf("Element added to stack\n");
}

struct Message* popMessage() {
    if (checkIfEmpty()) {
        printf("Error: stack is empty\n");
        return NULL;
    }

    struct Message* msg = stack.deletedMessages[stack.top--];
    printf("Element removed from stack\n");
    return msg;
}

void* producerTask() {
    pthread_cleanup_push(cleanupHandler, NULL);
    while (1) {
        struct Message* msg = generateNewMessage();

        pthread_mutex_lock(&queue.mutex);

        while (queue.countMsg >= sizeQueue)
            pthread_cond_wait(&queue.empty, &queue.mutex);

        queue.countAdd++;
        memcpy((queue.buffer + queue.tail), msg, sizeof(struct Message));
        ++queue.tail;

        if (queue.tail == sizeQueue)
            queue.tail = 0;

        ++queue.countMsg;
        pthread_cond_signal(&queue.full);
        pthread_mutex_unlock(&queue.mutex);

        printf("\nMSG ADD: %d // %d", msg->hash, msg->size);
        displayData(*msg);
        printf("COUNTER ADD: %d\n", queue.countAdd);
        fflush(stdout);
        sleep(5);
    }
    pthread_cleanup_pop(1);
    return NULL;
}

void createProducerThread(int prodCount) {
    int flError = pthread_create(&prodIdMas[prodCount], NULL, producerTask, NULL);
    if (flError) {
        printf("Error creating thread\n");
    }
}

void* consumerTask() {
    pthread_cleanup_push(cleanupHandler, NULL);
    while (1) {
        struct Message* msg = (struct Message*)malloc(sizeof(struct Message));

        pthread_mutex_lock(&queue.mutex);
        while (queue.countMsg == 0)
            pthread_cond_wait(&queue.full, &queue.mutex);

        queue.countGet++;
        memcpy(msg, (queue.buffer + queue.head), sizeof(struct Message));
        memset(queue.buffer + queue.head, 0, sizeof(struct Message));
        ++queue.head;
                if (queue.head == sizeQueue)
            queue.head = 0;
        pthread_cond_signal(&queue.empty);

        --queue.countMsg;
        pthread_mutex_unlock(&queue.mutex);

        printf("\nMSG READ: %d // %d", msg->hash, msg->size);
        displayData(*msg);
        printf("\nCOUNTER GET: %d\n", queue.countGet);
        sleep(4);
        free(msg);
    }
    pthread_cleanup_pop(1);
    return NULL;
}

void createConsumerThread(int consCount) {
    int flError = pthread_create(&consIdMas[consCount], NULL, consumerTask, NULL);
    if (flError) {
        printf("Error creating thread\n");
    }
}

bool stopThread(pthread_t* childIdMas, int idThread) {
    if (idThread != -1) {
        pthread_cancel(childIdMas[idThread]);
        pthread_join(childIdMas[idThread], NULL);
        return true;
    } else {
        printf("No threads\n");
        return false;
    }
}

void increaseQueueSize() {
    pthread_mutex_lock(&queue.mutex);
    sizeQueue++;
    queue.buffer = realloc(queue.buffer, sizeQueue * sizeof(struct Message));
    if (!queue.buffer) {
        perror("Error realloc");
        exit(EXIT_FAILURE);
    }
    pthread_cond_signal(&queue.empty);
    if (!checkIfEmpty()) {
        struct Message* msg = popMessage();
        memcpy((queue.buffer + queue.tail), msg, sizeof(struct Message));
        ++queue.tail;

        if (queue.tail == sizeQueue)
            queue.tail = 0;

        ++queue.countMsg;
    }
    if (queue.head > queue.tail) {
        for (int i = sizeQueue - 1; i > queue.head; i--)
            queue.buffer[i] = queue.buffer[i - 1];
        ++queue.head;
    }
    pthread_mutex_unlock(&queue.mutex);
}

void decreaseQueueSize() {
    pthread_mutex_lock(&queue.mutex);
    bool flag = false;
    if (queue.countMsg == sizeQueue) {
        struct Message lastMsg;
        memcpy(&lastMsg, (queue.buffer + queue.head), sizeof(struct Message));
        flag = true;
        queue.countMsg--;
        pushMessage(&lastMsg);
    }
    if (queue.countMsg < sizeQueue || flag) {
        if (queue.head < queue.tail) {
            for (int i = 0; queue.tail - queue.head - i > 0; i++)
                queue.buffer[i] = queue.buffer[queue.head + i];
            queue.tail -= queue.head;
            queue.head = 0;
        } else if (queue.head == queue.tail) {
            queue.head = queue.tail = 0;
        } else if (queue.head > queue.tail) {
            for (int i = 0; queue.head + i < sizeQueue; i++) {
                queue.buffer[queue.head + i - 1] = queue.buffer[queue.head + i];
            }
            queue.head--;
        }
        queue.buffer = realloc(queue.buffer, --sizeQueue * sizeof(struct Message));
        if (!queue.buffer) {
            perror("Error realloc");
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_unlock(&queue.mutex);
}

int main() {
    srand(time(NULL));
    initializeQueue();
    int prodCount = -1;
    int consCount = -1;
    char symbols[20];
    while (1) {
        printf("'p+' - create producer\n'p-' - destroy producer\n'c+' - create consumer\n'c-' - destroy consumer\n's+' - increase queue\n's-' - decrease queue\n'i' - info\n'q' - end\n");
        fgets(symbols, 20, stdin);
        switch (symbols[0]) {
            case 'p':
                if (symbols[1] == '+') {
                    ++prodCount;
                    createProducerThread(prodCount);
                } else if (symbols[1] == '-') {
                    if (stopThread(prodIdMas, prodCount))
                        --prodCount;
                }
                break;
            case 'c':
                if (symbols[1] == '+') {
                    ++consCount;
                    createConsumerThread(consCount);
                } else if (symbols[1] == '-') {
                    if (stopThread(consIdMas, consCount))
                        --consCount;
                }
                break;
            case 's':
                if (symbols[1] == '+')
                    increaseQueueSize();
                else if (symbols[1] == '-')
                    decreaseQueueSize();
                break;
            case 'i':
                printf("\nNumber of producers: %d", prodCount + 1);
                printf("\nNumber of consumers: %d", consCount + 1);
                printf("\nQueue size: %d", sizeQueue);
                printf("\nCount messages: %d\n", queue.countMsg);
                break;
        }
        if (symbols[0] == 'q')
            break;
    }
    return 0;
}

