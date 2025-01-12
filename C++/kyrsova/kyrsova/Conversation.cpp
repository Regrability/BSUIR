//Conversation.cpp
#include "Conversation.h"

string filename = "conversations.txt";

Conversation read_conversation_from_user() {
    Conversation conversation;

    cin.ignore(); // Очистка символа новой строки из буфера ввода
    cout << "Введите дату: ";
    getline(cin, conversation.date);

    cout << "Введите код города: ";
    getline(cin, conversation.city_code);

    cout << "Введите название города: ";
    getline(cin, conversation.city_name);

    cout << "Введите продолжительность разговора: ";
    cin >> conversation.duration;
    cin.ignore(); // Очистка символа новой строки из буфера ввода

    cout << "Введите тариф: ";
    cin >> conversation.tariff;
    cin.ignore(); // Очистка символа новой строки из буфера ввода

    cout << "Введите номер телефона: ";
    getline(cin, conversation.phone_number);

    cout << "Введите номер абонента: ";
    getline(cin, conversation.subscriber_number);

    return conversation;
}


void write_conversation_to_file(const Conversation& conversation) {
    ofstream file(filename, ios::app);  // Открываем файл в режиме добавления (append)
    if (file.is_open()) {
        file << conversation.date << "\t";
        file << conversation.city_code << "\t";
        file << conversation.city_name << "\t";
        file << conversation.duration << "\t";
        file << conversation.tariff << "\t";
        file << conversation.phone_number << "\t";
        file << conversation.subscriber_number << "\n";
        file.close();
    }
    else {
        cout << "Не удалось открыть файл.\n";
    }
}

void read_conversation_from_file(list<Conversation>& List) {
    Conversation conversation;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (true)
        {
            if (getline(file, line)) {
                // Создаем строковый поток из прочитанной строки
                istringstream iss(line);

                getline(iss, conversation.date, '\t');
                getline(iss, conversation.city_code, '\t');
                getline(iss, conversation.city_name, '\t');
                iss >> conversation.duration;
                iss.ignore(); // Пропускаем символ табуляции
                iss >> conversation.tariff;
                iss.ignore(); // Пропускаем символ табуляции
                getline(iss, conversation.phone_number, '\t');
                getline(iss, conversation.subscriber_number, '\t');
                List.push_back(conversation);
            }
            else { break; }
        }
        file.close();
        cout << "Чтение из файла успешно выполнено.\n";
    }
    else {
        cout << "Не удалось открыть файл.\n";
    }
 
}

void delete_file_conversation() {
    ofstream file(filename, ios::trunc);
    if (!file.is_open()) {
        cout << "Error with rewrite File";
    }
    file.close();
}



void print_conversation(const Conversation& conversation, int number) {
    cout << '|' << left << setw(5) << number << '|';
    cout << left << setw(15) << conversation.date << '|';
    cout << left << setw(15) << conversation.city_code << '|';
    cout << left << setw(15) << conversation.city_name << '|';
    cout << left << setw(15) << conversation.duration << '|';
    cout << left << setw(15) << conversation.tariff << '|';
    cout << left << setw(15) << conversation.phone_number << '|';
    cout << left << setw(15) << conversation.subscriber_number << '|' << endl;
    cout << string(119, '-') << endl;
}

void shapka_conversation() {
    cout << string(119, '-') << endl;
    cout << '|' << left << setw(5) << "Номер" << '|';
    cout << left << setw(15) << "Дата" << '|';
    cout << left << setw(15) << "Код города" << '|';
    cout << left << setw(15) << "Название города" << '|';
    cout << left << setw(15) << "Время разговора" << '|';
    cout << left << setw(15) << "Тариф" << '|';
    cout << left << setw(15) << "Н/T в городе" << '|';//Номер телефона в городе
    cout << left << setw(15) << "Н/T абонента" << '|' << endl;//Номер телефона абонента
    cout << string(119, '-') << endl;
}