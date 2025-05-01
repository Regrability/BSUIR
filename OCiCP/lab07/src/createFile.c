#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

// Структура записи
struct record_s {
    char name[80];      // Ф.И.О. студента
    char address[80];   // адрес проживания
    uint8_t semester;   // семестр
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("ARGS: %s <file_name> <elements_numbers>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int num_records = atoi(argv[2]);
    
    // Создаем бинарный файл для записи
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("ERROR OPEN");
        return 1;
    }

    // Записываем данные в файл
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < num_records; i++) {
        struct record_s record;
        
        // Генерируем случайные данные для имени и адреса
        for (int j = 0; j < 30; j++) {
            record.name[j] = 'A' + rand() % 26;
            record.address[j] = 'a' + rand() % 26;
        }

        record.name[30] = '\n';
        record.address[30] = '\n';
        record.name[31] = '\0';
        record.address[31] = '\0';
        
        // Генерируем случайное значение для семестра
        record.semester = rand() % 10 + 1;

        // Записываем структуру в файл
        fwrite(&record, sizeof(struct record_s), 1, file);
    }

    // Закрываем файл
    fclose(file);
    printf("Бинарный файл \"%s\" успешно создан.\n", filename);

    return 0;
}
