#include "Queue.h"
using namespace std;

pQueue createQueue() {
    pQueue pQ = (pQueue)malloc(sizeof(Queue));
    if (!pQ)
        return nullptr;
    pQ->top = nullptr;
    pQ->end = nullptr;
    pQ->len = 0;
}

bool isEmpty(pQueue pQ) {
    return !pQ->len;
}

bool put(pQueue pQ, int x) {
    pNode pN = (pNode)malloc(sizeof(Node));
    if (!pN)
        return 0;

    pN->value = x;
    pN->next = nullptr;

    if (pQ->end != nullptr) {
        pQ->end->next = pN;
    }
    else
    {
        pQ->top = pN;
    }
    pQ->end = pN;
    
    pQ->len++;
    return 1;
}

int take(pQueue pQ) {
    if (isEmpty(pQ))
        return 0;

    pNode currentTop = pQ->top;
    int val = currentTop->value;
    pQ->top = currentTop->next;
    pQ->len--;

    if (isEmpty(pQ))
        pQ->end = nullptr;

    free(currentTop);
    return val;
}

void clearQueue(pQueue pQ) {
    while (!isEmpty(pQ)) take(pQ);
    free(pQ);
}

void showQueue(pQueue pQ) {
    pNode p = pQ->top;
    if (isEmpty(pQ))
        cout << "Queue is empty!!!";
    while (p) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}
