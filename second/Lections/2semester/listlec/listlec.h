#pragma once
#ifndef LISTLEC.H
#define LISTLEC.H
#endif // !LISTLEC.H

#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct List {
    pNode top;
    int len;
} *pList;

pList createList();

// Проверка списка на пустоту
int isEmpty(pList pL);

// Поиск указателя на узел по значению (вспомогательная для добавления)
pNode getPointer(pList pL, int date);

// Добавление узла после заданного pN
int addNodeAfter(pList pL, pNode pN, int newdate);

// Вывод списка на экран
void showList(pList pL);

// Поиск узла по значению
pNode findNode(pList pL, int date);

// Вставка узла со значением date1 после всех узлов со значением date
int putAfter(pList pL, int date, int date1);

// Удаление узла, стоящего за pN
int delNode(pList pL, pNode pN);

// Очистка всех узлов списка
void clearList(pList pL);

// Полное удаление списка из памяти
void deleteList(pList pL);