//Conversation.h
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <iomanip>
#include <list>
#include <algorithm>
#include <windows.h>


using namespace std;

struct Conversation {
    string date;
    string city_code;
    string city_name;
    double duration = 0.0;
    double tariff = 0.0;
    string phone_number;
    string subscriber_number;
};


Conversation read_conversation_from_user();
void write_conversation_to_file(const Conversation& conversation);
void read_conversation_from_file(list<Conversation>& List);
void delete_file_conversation();
void print_conversation(const Conversation& conversation, int number);
void shapka_conversation();
