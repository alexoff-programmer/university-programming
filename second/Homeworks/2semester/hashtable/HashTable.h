#ifndef HASH_TABLE_H
#define HASH_TABLE_H

using namespace std;

// Структура данных для хранения в таблице
struct Data {
    char c;
    int k;
};

struct DataString {
    string word;
    string help;
};

// Переключатель типа данных (в коде на фото используется либо int, либо Data)
// typedef string T; // TASK 1
typedef DataString T; // TASK 2
//typedef int T; // TASK 3
// typedef struct Data T; // Раскомментировать для работы со структурой

typedef int hashTableIndex; // Индекс в хеш-таблице
//#define compEQ(a, b) ((a) == (b)) // TASK 1 and 3
#define compEQ(a, b) ((a.word) == (b.word)) // TASK 2

// Структура узла списка
typedef struct Node {
    T data;             // Данные, хранящиеся в вершине
    struct Node* next;  // Следующая вершина
} *pNode;

extern pNode p;
extern pNode* hashTable;       // Массив указателей (сама таблица)
extern int hashTableSize;      // Размер таблицы

// Прототипы функций
int kolchar(char* s);
hashTableIndex myhash(T data);
pNode insertNode(T data);
void deleteNode(T data);
pNode findNode(T data);
void printTable();
#endif