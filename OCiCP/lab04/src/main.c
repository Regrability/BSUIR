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
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10
#define MAX_STR_LEN 256
#define MAX_CHILD 20

typedef struct {
    struct Message* buffer;
    int head;
    int tail;
    int producerCount;
    int consumerCount;
    sem_t emptySlots; // Семафор для пустых слотов
    sem_t filledSlots;  // Семафор для заполненных слотов
    pthread_mutex_t queueMutex; // Мьютекс для доступа к очереди
} MessageQueueStruct;

MessageQueueStruct messageQueueInstance;

struct Message{
    char type;
    unsigned short int hash;
    unsigned char size;
    char* data;
};

void cleanup_handler();
void initializeQueue();
void* produceMessage();
void createProducerThreads(int prodCount);
void* consumeMessage();
void createConsumerThreads(int consCount);
bool destroyThread(pthread_t* childIdMas, int idThread);
unsigned char generateRandSize();
char* generateDataMessage(short int size);
void readData(struct Message msg);
struct Message* generateMessage();
void handlerSIGUSR1(__attribute__((unused)) int signum);
void setHandlerSIGTERM();


volatile sig_atomic_t sigTERMsignalFlag = 0;
pthread_t prodIdMas[MAX_CHILD];
pthread_t consIdMas[MAX_CHILD];
int sizeQueue = 10;



int main() {
    srand(time(NULL));
    initializeQueue();
    int prodCount = -1;
    int consCount = -1;
    char symbol;
    while (1) {
        printf("[1] - add producer\n[2] - delete producer\n[3] - add consumer\n[4] - delete consumer\n[5]-info\n[q]-end\n");
        if (scanf("%c", &symbol) != 1) {
            printf("Error reading input\n");
            continue;
        }
        getchar(); // clear newline character
        switch (symbol) {
        case '1':
            ++prodCount;
            createProducerThreads(prodCount);
            break;
        case '2':
            if (destroyThread(prodIdMas, prodCount))
                --prodCount;
            break;
        case '3':
            ++consCount;
            createConsumerThreads(consCount);
            break;
        case '4':
            if (destroyThread(consIdMas, consCount))
                --consCount;
            break;
        case '5':
            printf("\nNumber of producers: %d", messageQueueInstance.producerCount);
            printf("\nNumber of consumers: %d", messageQueueInstance.consumerCount);
            printf("\nQueue size: %d", sizeQueue);
            int fullValue;
            int emptyValue;
            sem_getvalue(&messageQueueInstance.filledSlots, &fullValue);
            sem_getvalue(&messageQueueInstance.emptySlots, &emptyValue);
            printf("\nFilled slots: %d", fullValue);
            printf("\nEmpty slots: %d", emptyValue);
            break;
        case 'q':
            printf("exiting program...\n");
            return 0;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return 0;
}

void cleanup_handler() {
    pthread_mutex_unlock(&messageQueueInstance.queueMutex);
}

void initializeQueue() {
    messageQueueInstance.buffer = (struct Message*)malloc(sizeof(struct Message) * sizeQueue);
    messageQueueInstance.head = 0;
    messageQueueInstance.tail = 0;
    messageQueueInstance.producerCount = 0;
    messageQueueInstance.consumerCount = 0;
    sem_init(&messageQueueInstance.emptySlots, 1, sizeQueue);
    sem_init(&messageQueueInstance.filledSlots, 1, 0);
    pthread_mutex_init(&messageQueueInstance.queueMutex, NULL);
}

void* produceMessage(){
    pthread_cleanup_push(cleanup_handler, NULL);
    while(1){
        struct Message* msg = generateMessage();

        sem_wait(&messageQueueInstance.emptySlots);

        pthread_mutex_lock(&messageQueueInstance.queueMutex);
        messageQueueInstance.producerCount++;
        memcpy((messageQueueInstance.buffer + messageQueueInstance.tail), msg, sizeof(struct Message));
        ++messageQueueInstance.tail;

        if (messageQueueInstance.tail == sizeQueue)
            messageQueueInstance.tail = 0;

        sem_post(&messageQueueInstance.filledSlots);
        pthread_mutex_unlock(&messageQueueInstance.queueMutex);

        printf("\nMSG ADD: %d // %d",msg->hash ,msg->size);
        readData(*msg);
        printf("PRODUCER COUNT: %d\n", messageQueueInstance.producerCount);
        fflush(stdout);
        sleep(5);
    }
    pthread_cleanup_pop(1);
}

void createProducerThreads(int prodCount){
    int flError = pthread_create(prodIdMas + prodCount, NULL, produceMessage, NULL);
    if (flError) {
        printf("Error creating thread \n");
    }
}

void* consumeMessage(){
    pthread_cleanup_push(cleanup_handler, NULL);
    while(1){
        struct Message* msg = (struct Message*)malloc(sizeof(struct Message));
        printf("\nBEFORE SEM\n");
        fflush(stdout);

        sem_wait(&messageQueueInstance.filledSlots);
        printf("\nAFTER SEM\n");
        fflush(stdout);

        pthread_mutex_lock(&messageQueueInstance.queueMutex);

        messageQueueInstance.consumerCount++;
        memcpy(msg, (messageQueueInstance.buffer + messageQueueInstance.head), sizeof(struct Message));
        memset(messageQueueInstance.buffer + messageQueueInstance.head, 0, sizeof(struct Message));
        ++messageQueueInstance.head;

        if (messageQueueInstance.head == sizeQueue)
            messageQueueInstance.head = 0;

        sem_post(&messageQueueInstance.emptySlots);
        pthread_mutex_unlock(&messageQueueInstance.queueMutex);

        printf("\nMSG READ: %d // %d",msg->hash,msg->size);
        readData(*msg);
        printf("\nCONSUMER COUNT: %d\n", messageQueueInstance.consumerCount);
        sleep(4);
    }
    pthread_cleanup_pop(1); // 1 указывает, что нужно выполнить функцию очистки
}

void createConsumerThreads(int consCount){
    int flError = pthread_create(consIdMas + consCount, NULL, consumeMessage, NULL);
    if (flError) {
        printf("Error creating thread \n");
    }
}

bool destroyThread(pthread_t* childIdMas, int idThread){
    if (idThread != -1){
        pthread_cancel(childIdMas[idThread]);
        pthread_join(childIdMas[idThread], NULL);
        return true;
    }
    else {
        printf("There are no child processes\n");
        return false;
    }
}

unsigned char generateRandSize(){
    short int randSize;
    for(randSize = rand() % 257; randSize == 0; );
    if (randSize == 256)
        randSize = 0;
    return randSize;
}

char* generateDataMessage(short int size){
    if (size == 0)
        size = 256;
    char* newMsg = (char*)malloc(sizeof(char) * (((size + 3)/4) * 4));
    for(int i = 0; i < ((size + 3)/4) * 4; i++){
        newMsg[i] = 33 + rand() % 93;
    }
    return newMsg;
}

void readData(struct Message msg){
    printf("\n");
    for (int i = 0; i < (msg.size != 0 ? ((msg.size + 3) / 4 * 4) : 256); i++){
        printf("%c", msg.data[i]);
    }
    printf("\n");
}

struct Message* generateMessage(){
    srand(time(NULL));
    struct Message* newMessage = (struct Message*)malloc(sizeof(struct Message*));
    newMessage->type = 'S';
    newMessage->size = generateRandSize();
    newMessage->data = generateDataMessage(newMessage->size);
    unsigned short int hash = newMessage->type + newMessage->size;
    for (int i = 0; i < (newMessage->size != 0 ? ((newMessage->size + 3) / 4 * 4) : 256); i++){
        hash += newMessage->data[i];
    }
    newMessage->hash = hash;
    return newMessage;
}



void handlerSIGUSR1(__attribute__((unused)) int signum) {
    sigTERMsignalFlag = 1;
    printf("\nworkSIgnal\n");
}

void setHandlerSIGTERM(){
    struct sigaction saSIGUSR1;
    saSIGUSR1.sa_handler = handlerSIGUSR1;
    if (sigaction(SIGUSR1, &saSIGUSR1, NULL) == -1) {
        perror("sigaction SIGTUSR1");
        exit(EXIT_FAILURE);
    }
}
