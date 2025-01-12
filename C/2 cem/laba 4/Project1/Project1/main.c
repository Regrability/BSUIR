#include "Roma.h";
int main() {
    int num_movies=0, choice=0;
    int *arr_data = (int*)malloc(100 * sizeof(int));
    struct Movie* movies = NULL;
    struct Movie* new_films;
    printf("\n-------------------------\n");
    while (choice != 5)
    {
        printf("enter film(1) \ndisplay films(2) \nfind new film(3) \ndelete films(4) \nexit(5)\n\n ");
        choice = vvod();
        switch (choice)
        {
        case 1:
        {
            new_films = (struct movie*)realloc(movies, (num_movies + 1) * sizeof(Movie));
            if (new_films == NULL) {
                printf("Error: Memory allocation failed\n");
                break;}
            movies = new_films;
            input_film_info(&movies[num_movies], arr_data, num_movies);
            num_movies++;
            printf("Film added successfully!\n");
            break;
        }
        break;
        case 2:
            print_movies_info(movies, num_movies, arr_data);
            break;
        case 3:
            find_new_movies(movies, num_movies, arr_data);
            break;
        case 4:
            remove_movies(movies, &num_movies);
            break;
        case 5:
            goodbay(movies, num_movies, arr_data);
            break;
        }
        printf("\n-------------------------\n");
    }
    return 0;
}