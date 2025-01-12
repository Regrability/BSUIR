#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 20
struct Movie {
    int duration;
    char* title;
    union
    {
        int release_year;
        char genre[MAX_GENRE_LENGTH];
    } info;
} Movie;
void print_movies_info(struct Movie* movies, int num_movies, int arr[])
{
    for (int i = 0; i < num_movies; i++)
    {
        printf("Movie #%d:\n", i + 1);
        printf("  Title: %s\n", movies[i].title);
        printf("  Duration: %d minutes\n", movies[i].duration);
        if (strlen(movies[i].info.genre) > 0) {
            printf("  Genre: %s\n", movies[i].info.genre);
        }
        else {
            printf("  Genre: N/A\n");
        }

        printf("  Release year: %d\n", arr[i]);

    }
    return 0;
}
void input_film_info(struct Movie* film, int* arr, int x)
{
    printf("Please enter the duration (in minutes) of the film: ");
    film->duration = vvod();
    film->title = malloc(MAX_TITLE_LENGTH * sizeof(char));
    printf("Please enter the title of the film: ");
    fgets(film->title, MAX_TITLE_LENGTH, stdin);
    film->title[strcspn(film->title, "\n")] = '\0';  // remove newline character from input
    printf("Enter the release year of movie: ");
    film->info.release_year = vvod();
    arr[x] = film->info.release_year;
    printf("Enter the genre of movie: ");
    char genre[MAX_GENRE_LENGTH];
    scanf("%s", genre);
    strcpy(film->info.genre, genre);
    return 0;
}
void find_new_movies(struct Movie* movies, int num_movies, int arr_data[])
{
    printf("Newest movies:\n");
    int newest_year = 0;
    for (int i = 0; i < num_movies; i++) {
        if (arr_data[i] > newest_year) {
            newest_year = arr_data[i];
        }
    }
    for (int i = 0; i < num_movies; i++) {
        if (arr_data[i] == newest_year) {
            printf("- %s\n", movies[i].title);
        }
    }
    return 0;
}
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
void remove_movies(struct Movie movies[], int* num_movies)
{
    printf("Enter the genre of movies to remove: ");
    char genre_to_remove[MAX_GENRE_LENGTH];
    scanf("%s", genre_to_remove);
    int i = 0;
    while (i < *num_movies) { // пока не пройдемся по всем фильмам
        if (strcmp(movies[i].info.genre, genre_to_remove) == 0) { // если продолжительность больше максимальной
            for (int j = i; j < *num_movies - 1; j++) { // сдвигаем все элементы массива на один влево
                movies[j] = movies[j + 1];
            }
            (*num_movies)--; // уменьшаем количество фильмов на 1
        }
        else {
            i++; // переходим к следующему фильму
        }
    }
    return 0;
}
void goodbay(struct Movie* movies, int num_movies, int arr_data[])
{
    printf("\n     goodbay");
    // free memory
    for (int i = 0; i < num_movies; i++) {
        free(movies[i].title);
    }
    free(movies);
    free(arr_data);
}