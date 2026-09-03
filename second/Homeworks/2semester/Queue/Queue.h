#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct Queue {
    pNode top;
    pNode end;
    int len;
} *pQueue;

pQueue createQueue();

bool isEmpty(pQueue pQ);

bool put(pQueue pQ, int x);

int take(pQueue pQ);

void clearQueue(pQueue pQ);

void showQueue(pQueue pQ);

#endif