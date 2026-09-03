#include "List.h"

// Создание пустого списка
pList createList() {
    pList New = (pList)malloc(sizeof(List));
    if (New) {
        New->top = NULL;
        New->len = 0;
    }
    return New;
}

// Проверка списка на пустоту
bool isEmpty(pList pL) {
    if (pL->top && pL->len) return 0;
    return 1;
}

// Поиск указателя на узел по значению (вспомогательная для добавления)
pNode getPointer(pList pL, T date) {
    pNode p = pL->top;
    if (isEmpty(pL) || date > p->value) return p;

    while (p->next && p->next->value > date) {
        p = p->next;
    }
    return p;
}

// Добавление узла после заданного pN
bool addNodeAfter(pList pL, pNode pN, T newdate, bool ignore) {
    pNode p = pL->top, pNew;
    pNew = (pNode)malloc(sizeof(Node));
    if (!pNew) return 0;

    pNew->value = newdate;
    pL->len++;

    if (isEmpty(pL) || p == pN && newdate > p->value && !ignore) {
        pNew->next = p;
        pL->top = pNew;
        return 1;
    }

    pNew->next = pN->next;
    pN->next = pNew;
    return 1;
}

// Вывод списка на экран
void showList(pList pL) {
    pNode p = pL->top;
    if (isEmpty(pL)) cout << "The list is empty." << endl;
    while (p) {
        cout << p << " -> " << p->value << " -> " << p->next << endl;
        p = p->next;
    }
}

// Поиск узла по значению
pNode findNode(pList pL, T date) {
    pNode p = pL->top;
    if (isEmpty(pL)) return NULL;
    while (p) {
        if (p->value == date)
            return p;
        p = p->next;
    }
}

// Вставка узла со значением date1 после всех узлов со значением date
bool putAfter(pList pL, T date, T date1) {
    if (isEmpty(pL) || !findNode(pL, date)) return 0;
    pNode p = pL->top;

    while (p) {
        if (p->value == date) {
            addNodeAfter(pL, p, date1, true);
            p = p->next;
        }
        p = p->next;
    }
    return 1;
}

// Удаление узла, стоящего за pN
bool delNode(pList pL, pNode pN) {
    if (!pL || !pN || isEmpty(pL)) return 0;
    pNode p = pN->next;

    if (pL->len == 1 && pL->top == pN) {
        free(pL->top);
        pL->top = NULL;
        pL->len = 0;
        return 1;
    }

    if (p) {
        pN->next = p->next;
        free(p);
        pL->len--;
        return 1;
    }
    return 0;
}

bool uniqueList(pList pL) {
    if (isEmpty(pL) || !pL) return 0;
    pNode p = pL->top;
    while (p->next) {
        if (p->value == p->next->value) {
            p->next = p->next->next;
            free(p->next);
        }
        p = p->next;
    }
    return 1;
}

// Очистка всех узлов списка
void clearList(pList pL) {
    while (pL->top) {
        delNode(pL, pL->top); // В лекции вызывается delNode для удаления
    }
}

// Полное удаление списка из памяти
void deleteList(pList pL) {
    clearList(pL);
    free(pL);
}