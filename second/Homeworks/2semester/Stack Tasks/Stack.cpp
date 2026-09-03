#include "Stack.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

pStack createStack() {
    pStack pS = (pStack)malloc(sizeof(Stack));
    if (pS) {
        pS->top = NULL;
        pS->len = 0;
    }
    return pS;
}

T isEmpty(pStack pS) {
    if (pS->top && pS->len) return 0;
    return 1;
}

T push(pStack pS, T c) {
    pNode p = (pNode)malloc(sizeof(Node));
    if (p) {
        p->value = c;
        p->next = pS->top;
        pS->top = p;
        pS->len++;
        return 1;
    }
    return 0;
}

T pop(pStack pS) {
    pNode p = pS->top;
    T c = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return c;
}

void showStack(pStack pS) {
    pStack qS = createStack();
    T c;
    if (isEmpty(pS)) printf("Stack is empty\n");
    else {
        while (!isEmpty(pS)) {
            c = pop(pS);
            cout << c << " ";
            push(qS, c);
        }
        cout << "\n";
        while (!isEmpty(qS)) {
            c = pop(qS);
            push(pS, c);
        }
    }
}

void clearStack(pStack pS) {
    while (!isEmpty(pS)) {
        pop(pS);
    }
}