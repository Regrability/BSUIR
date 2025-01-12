#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#define MAX_LENGTH 50
struct a
{
    char janr[50];
    int data_voxoda;
};
struct movie // ����������� ��������� "�����"
{
    char* title; // �������� ������
    int duration; // ����������������� ������ � �������
    struct a dop_infa;
};
int vvod()
{
    int var;
    while ((scanf_s("%d", &var) == 0) || getchar() != '\n')
    {
        printf("wrong input! try again\n");
        rewind(stdin);
    }
    return var;
}
// ������� ������ ������� �� ��������
void find_movies_by_title(struct movie movies[], int num_movies, char title[])
{

    printf("Found movies with title '%s':\n", title);
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) { // ��������� �����
            printf("%s (%d min)\n", movies[i].title, movies[i].duration);
        }
    }
}

char* memory(char* arr)
{
    int i = 0, l = 0;
    arr = (char*)calloc(255, sizeof(char));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    fgets(arr, 250, stdin);
    while (arr[i] != '\n')
    {
        i++;
        l++;
    }
    arr = (char*)realloc(arr, l);
    arr[l] = '\0';
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return arr;
}
// ������� �������� ������� �� �����������������
void remove_movies_by_duration(struct movie movies[], int* num_movies)
{
    printf("vvedite maxcimalnoe vrema filma\n");
    int max_duration = vvod();
    int i = 0;
    while (i < *num_movies) { // ���� �� ��������� �� ���� �������
        if (movies[i].duration > max_duration) { // ���� ����������������� ������ ������������
            for (int j = i; j < *num_movies - 1; j++) { // �������� ��� �������� ������� �� ���� �����
                movies[j] = movies[j + 1];
            }
            (*num_movies)--; // ��������� ���������� ������� �� 1
        }
        else {
            i++; // ��������� � ���������� ������
        }
    }
}
void vivod_structyri(struct movie movies[], int* num_movies)
{
    for (int i = 0; i < *num_movies; i++) { // ����� ���������� �������
        printf("%s (%d min)\n", movies[i].title, movies[i].duration);
    }
}

void vvod_structyri(struct movie movies[], int* num_movies)
{
    for (int i = 0; i < *num_movies; i++)
    {
        char* title = NULL;
        printf("Enter title of film: ");
        title = memory(title);
        movies[i].title = malloc(15 * sizeof(char)); // ��������� ������ ��� ������ ������
        strcpy(movies[i].title, title);
        printf("Enter movie duration: ");
        movies[i].duration = vvod();
        title = NULL;
    }
}

void freechka(struct movie movies[], int* num_movies)
{
    for (int i = 0; i < *num_movies; i++)
    {
        free(movies[i].title);
    }
    free(movies);
}

void dobavlenie(struct movie movies[], int* num_movies)
{
    (*num_movies)++;
    movies = (struct movie*)realloc(movies, (*num_movies) * sizeof(struct movie));
    char* title = NULL;
    printf("Enter title of film: ");
    title = memory(title);
    movies[(*num_movies) - 1].title = malloc(255 * sizeof(char)); // ��������� ������ �� 255 ��������
    strcpy(movies[(*num_movies) - 1].title, title);
    printf("Enter movie duration: ");
    movies[(*num_movies) - 1].duration = vvod();

    //// ���� �������������� ����������
    //printf("Enter movie genre: ");
    //fgets(movies[(*num_movies) - 1].dop_infa.janr, 50, stdin);
    //printf("Enter release date: ");
    //movies[(*num_movies) - 1].dop_infa.data_voxoda = vvod();
}
//void dobavlenie(struct movie movies[], int* num_movies)
//{
//    (*num_movies)++;
//    movies = (struct movie*)realloc(movies, (*num_movies) * sizeof(struct movie));
//    char* title = NULL;
//    printf("Enter title of film: ");
//    title = memory(title);
//    movies[(*num_movies) - 1].title = malloc(20 * sizeof(char)); // ��������� ������ ��� ������ ������
//    strcpy(movies[(*num_movies) - 1].title, title);
//    printf("Enter movie duration: ");
//    movies[(*num_movies) - 1].duration = vvod();
//}
void input_film_info(struct movie* film) 
{
    printf("Please enter the duration (in minutes) of the film: ");
    film->duration = vvod();
    film->title = malloc(MAX_LENGTH * sizeof(char));
    printf("Please enter the title of the film: ");
    fgets(film->title, MAX_LENGTH, stdin);
    film->title[strcspn(film->title, "\n")] = '\0';  // remove newline character from input
}