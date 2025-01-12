//City.cpp
#include "City.h"

list<City> list_cities;

void collect_city(Conversation conversation)
{
	bool flag = true;
    for (list<City>::iterator it = list_cities.begin(); it != list_cities.end(); ++it)
    {
        if ((*it).name == conversation.city_name)
        {
            flag = false;
            (*it).total_talk_time += conversation.duration;
            (*it).sum_money += conversation.duration * conversation.tariff;
            break;
        }
    }
    if (flag)
    {
        City city;
        city.name = conversation.city_name;
        city.total_talk_time = conversation.duration;
        city.sum_money = conversation.tariff * conversation.duration;
        list_cities.push_back(city);
    }
}

void collect_cities(list<Conversation>& List)
{
    list_cities.clear();
    for (list<Conversation>::iterator it = List.begin(); it != List.end(); ++it)
    {
        collect_city(*it);
    }
}

void print_cities()
{
    system("cls");
    if (list_cities.empty())
    {
        cout << "Нету городов для вывода" << endl;
    }
    else {
        int i = 1;
        shapka_city();

        for (list<City>::const_iterator it = list_cities.cbegin(); it != list_cities.cend(); ++it)
        {
            print_city(*it, i);
            i++;
        }
    }
    
}

void print_city(City city, int number)
{
    cout << '|' << left << setw(5) << number << '|';
    cout << left << setw(15) << city.name << '|';
    cout << left << setw(25) << city.total_talk_time << '|';
    cout << left << setw(15) << city.sum_money << '|' << endl;
    cout << string(65, '-') << endl;
}

void shapka_city()
{
    cout << string(65, '-') << endl;
    cout << '|' << left << setw(5) << "Номер" << '|';
    cout << left << setw(15) << "Название города" << '|';
    cout << left << setw(25) << "Общее время разговоров" << '|';
    cout << left << setw(15) << "Общая сумма" << '|' << endl;
    cout << string(65, '-') << endl;
}

void BubbleSort()
{
    system("cls");
    if (list_cities.empty())
    {
        cout << "Нету городов для сортировки" << endl;
    }
    else
    {
        bool swapped = true; // Флаг, указывающий наличие обменов
        while (swapped)
        {
            swapped = false; // Сбрасываем флаг перед каждой итерацией

            // Проходим по элементам списка
            list<City>::iterator it = list_cities.begin();
            list<City>::iterator nextIt = next(it);

            while (nextIt != list_cities.end())
            {
                // Если текущий элемент больше следующего элемента
                if ((*it).total_talk_time > (*nextIt).total_talk_time)
                {
                    // Меняем местами элементы
                    iter_swap(it, nextIt);
                    swapped = true; // Устанавливаем флаг обмена
                }

                // Переходим к следующим элементам
                ++it;
                ++nextIt;
            }
        }
    }
    print_cities();
}

void SearchValue()
{
    system("cls");
    if (list_cities.empty())
    {
        cout << "Нету городов для сортировки" << endl;
    }
    else
    {
        bool flag = true;
        double key;
        int i = 1;
        cout << "Введите общее время разговора: ";
        cin >> key;
        for (typename list<City>::iterator it = list_cities.begin(); it != list_cities.end(); ++it)
        {
            if ((*it).total_talk_time == key)
            {
                if (flag) { shapka_city(); flag = false; }
                print_city(*it, i);
                i++;
            }
        }
        if (flag) cout << "Нету таких городов" << endl;
    }
}