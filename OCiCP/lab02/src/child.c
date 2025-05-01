#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#define MAX_ENV_VARS 100

int main(int argc, char *argv[]) {
    fprintf(stdout, "Child process begins...\n");
    pid_t pid, ppid;
    setlocale(LC_COLLATE, "C");
    pid = getpid();
    ppid = getppid();
    printf("My name: %s\n", argv[0]);
    printf("My pid = %d, my ppid = %d\n", (int)pid, (int)ppid);

    char* env_vars[MAX_ENV_VARS + 1]; // +1 для NULL-терминатора
    FILE* file;
    char line[256];
    int var_count = 0;

    // Открытие файла param.txt для чтения
    file = fopen("param.txt", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    // Чтение названий переменных из файла
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0'; // Удаление символа новой строки
        env_vars[var_count] = getenv(line); // Получение значения переменной из среды
        printf("%s = %s\n", line, env_vars[var_count]);
        var_count++;
        if (var_count >= MAX_ENV_VARS) {
            printf("Превышено максимальное количество переменных окружения\n");
            break;
        }
    }
    env_vars[var_count] = NULL; // Установка NULL-терминатора для массива аргументов

    fclose(file);

    exit(0);
}
