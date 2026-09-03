#pragma once
typedef struct Data {
	char c;
	int k;
} T;

typedef struct Node {
	T data;
	Node* next;
} *pNode;

pNode addNode(pNode head, T data);
int kolchar(char* s);
int myHash(char c, int hTS);
void printHT(pNode* hT, int hTS);