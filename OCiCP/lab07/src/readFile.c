#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Структура записи
struct record_s {
    char name[80];      // Ф.И.О. студента
    char address[80];   // адрес проживания
    uint8_t semester;   // семестр
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("ARGS: %s <file_name>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Открываем бинарный файл для чтения
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("ERROR OPEN");
        return 1;
    }

    // Читаем данные из файла
    struct record_s record;
    while (fread(&record, sizeof(struct record_s), 1, file)) {
        // Выводим данные на экран
        printf("Имя: %s", record.name);
        printf("Адрес: %s", record.address);
        printf("Семестр: %d", record.semester);
        printf("\n\n");
    }

    // Закрываем файл
    fclose(file);

    return 0;
}
