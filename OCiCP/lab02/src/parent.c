#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>
#include <locale.h>
#define MAX_ENV_VARS 100

int compare_strings(const void* str1, const void* str2);
void sort_and_print_env_vars();
char* do_child_number(int number);
char* strdup(const char* str);
extern char** environ;

int main(int argc, char* argv[], char* envp[]) {
setlocale(LC_COLLATE, "C");
const char* childPath = NULL;//./build/debug/child"
int child_status, i;
int child_number = 0;
char choice = 'a';


sort_and_print_env_vars();


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
        char* env_var = getenv(line); // Получение значения переменной из среды
        if (env_var != NULL) {
            char* key_value = strdup(line);
            strcat(key_value, "=");
            strcat(key_value, env_var);
            env_vars[var_count] = key_value;
            var_count++;
        } else {
            printf("Переменная окружения %s не найдена\n", line);
        }

        if (var_count >= MAX_ENV_VARS) {
            printf("Превышено максимальное количество переменных окружения\n");
            break;
        }
    }
    env_vars[var_count] = NULL; // Установка NULL-терминатора для массива аргументов

    fclose(file);




while(choice != 'q')
{
    child_number++;
    printf("Your choice:\n[+]\n[*]\n[&]\n[q]\n");
    choice = getchar();
     // Очистка буфера ввода
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    switch(choice){
        case '+':
            childPath = getenv("CHILD_PATH");
            if (childPath != NULL) { printf("CHILD_PATH+: %s\n", childPath);}
                              else { printf("CHILD_PATH не установлена\n");}
            break;
          break;
        case '*':
            // Поиск переменной CHILD_PATH в массиве параметров среды
            i = 0;
            while (envp[i] != NULL) {
            if (strncmp(envp[i], "CHILD_PATH=", 11) == 0) {
                childPath = envp[i] + 11; // Установка childPath на значение после 'CHILD_PATH='
                break;
                }
                i++;
            }

            if (childPath != NULL) {
                printf("CHILD_PATH*: %s\n", childPath);
                } else {
                printf("CHILD_PATH is not set\n");
                }
            break;
        case '&':
            // Поиск переменной CHILD_PATH в массиве параметров среды c внешней переменной environ
            i = 0;
            while (environ[i] != NULL) {
                if (strncmp(environ[i], "CHILD_PATH=", 11) == 0) {
                    childPath = environ[i] + 11; // Установка childPath на значение после 'CHILD_PATH='
                    break;
                    }
                i++;
                }

                if (childPath != NULL) {
                    printf("CHILD_PATH&: %s\n", childPath);
                    } else {
                    printf("CHILD_PATH is not set\n");
                    }
            break;

        case 'q':
            printf("exiting program\n");
            exit(0);
            break;
        default:
            printf("invalid input\n");}


    if(choice == '+' || choice == '*' || choice == '&')
    {
    char *args[] = {do_child_number(child_number), "parm_1", (char*)0};
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error occured, error code - %d\n", errno);
        exit(errno);
    }
    if (pid == 0) {
        printf("Child process created. Please, wait...\n");
        execve(childPath, args, env_vars);
    }
    wait(&child_status);
    printf("Child process have ended with %d exit status\n", child_status);
    }

}
    exit(0);
}

// Функция для сравнения строк с учетом LC_COLLATE=C
int compare_strings(const void* str1, const void* str2) {
    return strcoll(*(const char**)str1, *(const char**)str2);
}

void sort_and_print_env_vars() {

    // Получение переменных среды
    extern char** environ;

    int num_env_vars = 0;
    while (environ[num_env_vars] != NULL) {
        num_env_vars++;
    }

    // Копирование переменных среды в массив
    char** env_vars = (char**)malloc(num_env_vars * sizeof(char*));
    for (int i = 0; i < num_env_vars; i++) {
        env_vars[i] = strdup(environ[i]);
    }

    // Сортировка массива переменных среды
    qsort(env_vars, num_env_vars, sizeof(char*), compare_strings);

    // Вывод отсортированных переменных среды в stdout
    for (int i = 0; i < num_env_vars; i++) {
        printf("%s\n", env_vars[i]);
        free(env_vars[i]);  // Освобождение памяти для каждой строки
    }

    free(env_vars);  // Освобождение памяти для массива переменных среды
}

char* do_child_number(int number)
{
    char* child = (char*)malloc(20 * sizeof(char));
    if (number < 10) {
        snprintf(child, 20, "child_0%d", number);
    } else {
        snprintf(child, 20, "child_%d", number);
    }
    return child;
}
