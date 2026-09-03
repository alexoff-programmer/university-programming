#include <iostream>
#include <iomanip>
#include "HashTable.h"

using namespace std;

pNode p = NULL;
pNode* hashTable = NULL;
int hashTableSize = 0;


hashTableIndex myhash(T dat) {
    unsigned int sum = 0;
    //for (char c : dat) {
    //    sum += (unsigned char) c;
    //} // Task 1
    for (char c : dat.word) {
        sum += (unsigned char)c;
    }
    //sum = dat;
    return (sum % hashTableSize);
}

// --- Функция вставки ---
pNode insertNode(T newdata) {
    pNode p, p0;
    hashTableIndex i;

    i = myhash(newdata);
    p = new Node;

    if (!p) {
        cout << "Нехватка памяти в insertNode()\n";
    }
    else {
        p0 = hashTable[i];
        hashTable[i] = p;
        p->next = p0;
        p->data = newdata;
    }
    return p;
}

// --- Функция удаления ---
void deleteNode(T dat) {
    pNode p0 = NULL, p;
    hashTableIndex i;
    i = myhash(dat);
    p = hashTable[i];

    //while (p && !compEQ(p->data, dat)) {
    //    p0 = p;
    //    p = p->next;
    //} // Task 1

    while (p && !compEQ(p->data, dat)) {
        p0 = p;
        p = p->next;
    } // Task 2

    if (!p) return; // Элемент не найден

    if (p0)
        p0->next = p->next;
    else
        hashTable[i] = p->next;

    delete p;
}

// --- Функция поиска ---
pNode findNode(T data) {
    pNode p;
    int k = 0; // Счетчик сравнений
    p = hashTable[myhash(data)];

    while (p && !compEQ(p->data, data)) {
        k++;
        p = p->next;
    }

    if (p && compEQ(p->data, data)) k++;

    //cout << " !!! => " << data << " comp=" << k << endl; // Task 1 AND 3
    cout << " !!! => " << p->data.word << ", help: " << p->data.help << " comp=" << k << endl; // Task 2
    return p;
}

// --- Вспомогательная функция для подсчета символов ---

int kolchar(char* s) {
    int k, i, j;
    for (k = i = j = 1; s[i]; i++) {
        if (s[i] != s[0])
            s[j++] = s[i];
        else
            k++;
    }
    s[j] = 0;
    return k;
}

// Вывод таблицы на экран
void printTable() {
    cout << "\n--- Содержимое Хеш-таблицы ---" << endl;
    for (int i = 0; i < hashTableSize; i++) {
        cout << "[" << setw(2) << i << "]: ";
        pNode temp = hashTable[i];
        while (temp) {
            //cout << temp->data << " -> "; // Task 1 AND 3
			cout << temp->data.word << " (" << temp->data.help << " -> "; // Task 2
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}