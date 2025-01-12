//City.h
#pragma once
#include "Conversation.h"

struct City {
    string name;
    double total_talk_time = 0.0;
    double sum_money = 0.0;
};

void collect_city(Conversation conversation);
void collect_cities(list<Conversation>& List);
void print_cities();
void print_city(City city, int number);
void shapka_city();
void BubbleSort();
void SearchValue();