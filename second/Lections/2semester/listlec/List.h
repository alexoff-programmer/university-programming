#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <malloc.h>

using namespace std;

typedef int T;

typedef struct Node {
    T value;
    struct Node* next;
} *pNode;

typedef struct List {
    pNode top;
    int len;
} *pList;

// Создание пустого списка
pList createList();

// Проверка списка на пустоту
bool isEmpty(pList pL);

// Поиск указателя на узел по значению (вспомогательная для добавления)
pNode getPointer(pList pL, T date);

// Добавление узла после заданного pN
bool addNodeAfter(pList pL, pNode pN, T newdate, bool ignore = false);

// Вывод списка на экран
void showList(pList pL);

// Поиск узла по значению
pNode findNode(pList pL, T date);

// Вставка узла со значением date1 после всех узлов со значением date
bool putAfter(pList pL, T date, T date1);

// Удаление узла, стоящего за pN
bool delNode(pList pL, pNode pN);

bool uniqueList(pList pL);

// Очистка всех узлов списка
void clearList(pList pL);

// Полное удаление списка из памяти
void deleteList(pList pL);

#endif