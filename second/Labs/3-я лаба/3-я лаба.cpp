// 3-я лаба
// Стеки
// Сначала описываем сам узел, а потом по нему уже строим стек.
// typedef struct STACK {} *pSTACK - typedef {структура} {синоним, но если указать звёздочку, то будет синоним на указатель}

#include <iostream>
#include <malloc.h>

#define _SIZE 15

using namespace std;

typedef struct Stck {
    int mas[_SIZE];
    int top, len;
};

void _init(struct Stck* St) {
    St->top = 0;
    St->len = 0;
};

void _print(struct Stck* St) {
    for (int i = St->top - 1; i >= 0; i--) {
        cout << St->mas[i] << " ";
    }
    cout << endl;
}

int _pop(struct Stck* St) {
    if (!St->len) {
        cout << "STACK IS EMPTY.";
        return 0;
    }
    St->top--;
    St->len--;
    cout << St->top << " ";
    return St->mas[St->top];
}

void _push(struct Stck* St, int a) {
    if (St->len < _SIZE) {
        St->mas[St->top] = a;
        St->top++;
        St->len++;
    }
    else cout << "STACK IS FULL.";
};


typedef struct Node {
    char value;
    struct Node* next;
} *pNode;

typedef struct Stack {
    pNode top;
    int len;
} *pStack;

pStack createStack() {
    pStack pS = (pStack)malloc(sizeof(Stack));
    if (pS) {
        pS->len = 0;
        pS->top = nullptr;
    }
    return pS;
}

int isEmpty(pStack pS) {
    return !(pS->top && pS->len);
}

int push(pStack pS, char c) {
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

char pop(pStack pS) {
    pNode p = pS->top;
    char c = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return c;
}

void showStack(pStack pS) {
    pStack qS = createStack();
    char c;
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

int main() {
    char c;
    Stck St;
    _init(&St);

    for (int j = 1, i = 11; i < 140; j++, i = 11 * j) {
        _push(&St, i);
        _print(&St);
    }

    cout << St.len << " ";
    _print(&St);

    for (int i = St.top; i; i--) {
        _pop(&St);
        _print(&St);
    }

    cout << "=====================================\n";

    pStack pS = createStack();
    showStack(pS);

    for (c = 'a'; c <= 'z'; c += 2) {
        push(pS, c);
        showStack(pS);
    }

    while (!isEmpty(pS)) {
        showStack(pS);
        pop(pS);
    }

    showStack(pS);
    clearStack(pS);
    cout << "=====================================\n";

    return 0;
}
