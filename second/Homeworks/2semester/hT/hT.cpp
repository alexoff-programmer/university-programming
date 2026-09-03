// hT.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ht.h"
#include <string.h>

int task(std::string word) {
    int maxnum = 26, hTS = 20, t = 0;
    T* a = (T*)calloc(maxnum, sizeof(T));
    pNode* hT = (pNode*)calloc(hTS, sizeof(pNode));

    char* str = (char*)malloc(word.size() + 1);
    if (!str) return 0;
    strcpy(str, word.c_str());
    
    for (int i = 0; str[i]; i++) {
        a[i] = {str[i], kolchar(str + i)};
        t++;
    }
    for (int i = 0; i < t; i++) {
		int index = myHash(a[i].c, hTS);
		hT[index] = addNode(hT[index], a[i]);
    }
	printHT(hT, hTS);

    free(a);
	free(str);
	free(hT);
    return 0;
}

void printHT(pNode* hT, int hTS) {
    for (int i = 0; i < hTS; i++) {
        std::cout << "Bucket " << i << ": ";
        pNode current = hT[i];
        while (current) {
            std::cout << "(" << current->data.c << ", " << current->data.k << ") -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
}

pNode addNode(pNode head, T data) {
    pNode newNode = (pNode)malloc(sizeof(Node));
	if (!newNode) return head;
    newNode->data = data;
    newNode->next = head;
    return newNode;
}


int kolchar(char* s) {
    int i, j, k;
    for (i = j = k = 1; s[i]; i++) {
        if (s[i] != s[0]) {
            s[j++] = s[i];
        }
        else {
            k++;
		}
    }
	s[j] = 0;
    return k;
}

int myHash(char c, int hTS) {
	return (int)c % hTS;
}


int main()
{
    task("OPTIMIZATION");
    std::cout << "Hello World!\n";
}