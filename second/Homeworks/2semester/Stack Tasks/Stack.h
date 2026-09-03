#ifndef STACK_H
#define STACK_H

typedef char T;

typedef struct Node {
    T value;
    struct Node* next;
} *pNode;

typedef struct Stack {
    pNode top;
    int len;
} *pStack;

pStack createStack();
T isEmpty(pStack pS);
T push(pStack pS, T c);
T pop(pStack pS);
void showStack(pStack pS);
void clearStack(pStack pS);

#endif