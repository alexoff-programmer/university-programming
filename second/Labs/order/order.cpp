// очереди

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

int pop(pQueue pQ) {
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

int main()
{
    pQueue pQ = createQueue();
    put(pQ, 1); put(pQ, 2); put(pQ, 3);
    cout << isEmpty(pQ) << pop(pQ) << pop(pQ) << pop(pQ);
}
