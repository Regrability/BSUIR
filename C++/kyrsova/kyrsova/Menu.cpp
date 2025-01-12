//Menu.cpp
#include "Menu.h"

list<Conversation> list_conversations;

void Run() {
    int choice;
    while (true)
    {
        print_menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            add_conversation();
            break;
        case 2:
            system("cls");
            delete_conversation();
            break;
        case 3:
            system("cls");
            print_conversations();
            break;
        case 4:
            system("cls");
            change_conversation();
            break;
        case 5:
            system("cls");
            clear_conversations();
            break;
        case 6:
            system("cls");
            collect_cities(list_conversations);
            print_cities();
            break;
        case 7:
            system("cls");
            collect_cities(list_conversations);
            SearchValue();
            break;
        case 8:
            system("cls");
            collect_cities(list_conversations);
            BubbleSort();
            break;
        case 9:
            system("cls");
            cout << "Завершение программы..." << endl;
            break;
        default:
            cout << "неправильный ввод" << endl;
            break;
        }
        if (choice == 9) break;
    }
}

void print_menu() {
    cout << "\n-------------- Menu --------------" << endl;
    cout << "1. добавть разговор" << endl;
    cout << "2. удалить разговор" << endl;
    cout << "3. вывести разговоры" << endl;
    cout << "4. изменить разговор" << endl;
    cout << "5. очистить разговоры" << endl;
    cout << "6. вывести города" << endl;
    cout << "7. поиск города по ключу" << endl;
    cout << "8. отсортированные города по ключу" << endl;
    cout << "9. выйти из программы" << endl;
    cout << "----------------------------------" << endl;
    cout << "*ключ - общее время разговора городов" << endl;
}

void add_conversation() {
    Conversation conversation;
    conversation = read_conversation_from_user();
    write_conversation_to_file(conversation);
    list_conversations.push_back(conversation);
    cout << "разговор добавлен успешно" << endl;
}

void delete_conversation() {
    system("cls");
    print_conversations();
    if (list_conversations.size() > 0)
    {
        cout << "Введите номер звонка для удаления: ";
        int num;
        cin >> num;
        num--;
        if (num >= list_conversations.size())
        {
            cout << "Нету такого элемента" << endl;
            return;
        }
        list<Conversation>::iterator it = list_conversations.begin();
        advance(it, num);
        list_conversations.erase(it);
        write_list_conversation_to_file();
        cout << "Удаление прошло успешно" << endl;
    }
    else
    {
        cout << "Нету элементов для удаления" << endl;
    }
}

void change_conversation() {
    system("cls");
    print_conversations();
    if (list_conversations.size() > 0)
    {
        cout << "Введите номер звонка для изменения: ";
        int num;
        cin >> num;
        num--;
        if (num >= list_conversations.size())
        {
            cout << "Нету такого элемента" << endl;
            return;
        }
        list<Conversation>::iterator it = list_conversations.begin();
        advance(it, num);
        *it = read_conversation_from_user();
        write_list_conversation_to_file();
        cout << "Изменение прошло успешно" << endl;
    }
    else
    {
        cout << "Нету звонков для изменения" << endl;
    }
}

void print_conversations() {
    system("cls");
    if (list_conversations.empty())
    {
        cout << "Нету звонков для вывода" << endl;
    }
    else {
        int i = 1;
        shapka_conversation();

        for (list<Conversation>::const_iterator it = list_conversations.cbegin(); it != list_conversations.cend(); ++it)
        {
            print_conversation(*it, i);
            i++;
        }
    }
}

void clear_conversations() {
    if (list_conversations.empty())
    {
        cout << "Звонки очищены" << endl;
    }
    else {
        delete_file_conversation();
        list_conversations.clear();
        cout << "Звонки очищены" << endl;
    }
}

void write_list_conversation_to_file() {
    delete_file_conversation();
    for (list<Conversation>::const_iterator it = list_conversations.cbegin(); it != list_conversations.cend(); ++it)
    {
        write_conversation_to_file(*it);
    }
}

void read_conversation_from_file_to_list()
{
    read_conversation_from_file(list_conversations);
}