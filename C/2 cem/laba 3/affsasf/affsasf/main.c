#include "Roman.h";
int main()
{
    char* title = NULL;
    int choice = 0;
    struct movie* movies = NULL; // инициализация массива структур "фильм"
    struct movie* new_films = NULL;
    int num_movies = 0; // количество фильмов
    printf("Enter num movies: ");
    num_movies = vvod();
    movies = (struct movie*)malloc((num_movies) * sizeof(struct movie));
    vvod_structyri(movies, &num_movies);
    while (choice != 5)
    {
        printf("\nenter film(1) \ndisplay films(2) \nfind film(3) \ndelete films(4) \nexit(5)\n\n ");
        choice = vvod();
        switch (choice)
        {
        case 1:
        {
            new_films =(struct movie*)realloc(movies, (num_movies + 1) * sizeof(struct movie));
            if (new_films == NULL) {
                printf("Error: Memory allocation failed\n");
                break;
            }
            movies = new_films;
            input_film_info(&movies[num_movies]);
            num_movies++;
            printf("Film added successfully!\n");
            break;
        }
            break;
        case 2:   
        vivod_structyri(movies, &num_movies);
            break;
        case 3:
        printf("vvedite nazvanie filma\n");
        title = memory(title);
        find_movies_by_title(movies, num_movies, title); // поиск фильмов по названию
        title = NULL;
            break;
         case 4:
        remove_movies_by_duration(movies, &num_movies); // удаление фильмов по продолжительности
             break;
         case 5:
        printf("\n     goodbay");
             choice = 5;
        freechka(movies, &num_movies);
         break;
        }
    }
    return 0;
}