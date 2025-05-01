#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    char name[80];
    char address[80];
    uint8_t semester;
} record_s;

void printAllFile(int file){
    record_s record;
    int i = 0;
    struct flock lock;
    lock.l_type = F_RDLCK; // Тип блокировки (запись)
    lock.l_whence = SEEK_SET; // Относительное положение для блокировки (начало файла)
    lock.l_start = 0; // Начало блокировки с начала файла
    lock.l_len = 0; // Длина блокировки (0 - весь файл)
    if (fcntl(file, F_GETLK, &lock) == -1) {
        perror("fcntl");
        return;
    }
    if (lock.l_type != F_UNLCK) {
        if (lock.l_type == F_RDLCK) {
            printf("Close for read\n");
            return;
        }
    }
    printf("Read start");
    lseek(file, 0, SEEK_SET);
    while (read(file, &record, sizeof(record_s)) > 0){
        printf("Record number: %d\nName: %sAddress: %sSemester: %d\n\n", i, record.name, record.address, record.semester);
        i++;
    }
}

void getRecordNumb(int file, int numb, record_s *record){
    lseek(file, numb * sizeof(record_s), SEEK_SET);
    struct flock lock;
    lock.l_type = F_RDLCK; // Тип блокировки (запись)
    lock.l_whence = SEEK_CUR; // Относительное положение для блокировки (начало файла)
    lock.l_start = 0; // Начало блокировки с начала файла
    lock.l_len = sizeof(record_s); // Длина блокировки (0 - весь файл)
    if (fcntl(file, F_GETLK, &lock) == -1) {
        perror("fcntl");
        return;
    }
    if (lock.l_type != F_UNLCK) {
        if (lock.l_type == F_RDLCK) {
            printf("Close for read\n");
            return;
        }
    }

    read(file, record, sizeof(record_s));
    printf("Record number: %d\nName: %sAddress: %sSemester: %d\n\n", numb, record->name, record->address, record->semester);
}

void modifyRecord(record_s *record){
    printf("Enter name: ");
    fgets(record->name, 80, stdin);
    printf("Enter address: ");
    fgets(record->address, 80, stdin);
    printf("Enter semester: ");
    scanf("%hhu", &record->semester);
    fflush(stdin); // Очищаем поток ввода
}

void saveRecord(int file, int numb, record_s *record, record_s *oldRecord){
    lseek(file, numb * sizeof(record_s), SEEK_SET);
    struct flock lock;
    lock.l_type = F_WRLCK; // Тип блокировки (запись)
    lock.l_whence = SEEK_CUR; // Относительное положение для блокировки (начало файла)
    lock.l_start = 0; // Начало блокировки с начала файла
    lock.l_len = sizeof(record_s); // Длина блокировки (0 - весь файл)
    if (fcntl(file, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return;
    }
    record_s tmpRecord;
    read(file, &tmpRecord, sizeof(record_s));

    if (strcmp(tmpRecord.name, oldRecord->name) != 0 ||
        strcmp(tmpRecord.address, oldRecord->address) != 0 ||
        tmpRecord.semester != oldRecord->semester) {
             printf("You object was changed after that");
        }
        else{
        printf("Semester was changed\n");
        printf("Name: %sAddress: %sSemester: %d\n\n", tmpRecord.name, tmpRecord.address, tmpRecord.semester);
        printf("if you want to save changes enter 'y'\nElse enter 'n'\n");
        char symbol;
        scanf("%c", &symbol);
        if (symbol == 'n'){
            *oldRecord = *record = tmpRecord;
            return;
        }
    }
    lseek(file, numb * sizeof(record_s), SEEK_SET);
    write(file, record, sizeof(record_s));
    lseek(file, numb * sizeof(record_s), SEEK_SET);
    lock.l_type = F_UNLCK; // Тип блокировки (разблокировка)
    lock.l_whence = SEEK_CUR; // Относительное положение для блокировки (начало файла)
    lock.l_start = 0; // Начало блокировки с начала файла
    lock.l_len = sizeof(record_s); // Длина блокировки (0 - весь файл)
    if (fcntl(file, F_SETLKW, &lock) == -1) {
        perror("fcntl");
        return;
    }
}

int main(int argc, char *argv[]){
    if (argc != 2) {
        printf("ARGS: %s <file_name>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    int file = open(filename, O_RDWR);
    if (file == -1) {
        perror("ERROR OPEN");
        return 1;
    }
    int size = lseek(file, 0, SEEK_END) / sizeof(record_s);
    char symbols[20];
    record_s record;
    record_s newRecord;
    int currentRecord = 0;
    while (1){
        printf("'p' - Print all file\n'g' - Get record with number\n'r' - Rewrite current record\n's' - Save current record\nq-End\n");
        fgets(symbols, 20, stdin);
        switch (symbols[0])
        {
        case 'p':
            printAllFile(file);
            break;
        case 'g':
            printf("Enter the record number to find: ");
            fgets(symbols, 20, stdin);
            currentRecord = atoi(symbols);
            if (currentRecord >= size || currentRecord < 0) {
                printf("Invalid record number\n");
                break;
            }
            getRecordNumb(file, currentRecord, &record);
            break;

        case 'r':
            printf("Enter the record number to modify: ");
            fgets(symbols, 20, stdin);
            currentRecord = atoi(symbols);
            if (currentRecord >= size || currentRecord < 0) {
                printf("Invalid record number\n");
                break;
            }
            getRecordNumb(file, currentRecord, &record);
            newRecord = record;
            modifyRecord(&newRecord);

            getchar(); // Добавляем вызов getchar() для удаления символа новой строки из потока ввода
            break;

        case 's':
            saveRecord(file, currentRecord, &newRecord, &record);
            getchar();

            break;
        }
        if (symbols[0] == 'q')
            break;
    }
    return 0;
}

