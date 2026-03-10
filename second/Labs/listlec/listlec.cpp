#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct Node {
    int value;
    struct Node* next;
} *pNode;

typedef struct List {
    pNode top;
    int len;
} *pList;

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
int isEmpty(pList pL) {
    if (pL->top && pL->len) return 0;
    return 1;
}

// Поиск указателя на узел по значению (вспомогательная для добавления)
pNode getPointer(pList pL, int date) {
    pNode p = pL->top;
    if (isEmpty(pL) || date > p->value) return p;

    while (p->next && p->next->value > date) {
        p = p->next;
    }
    return p;
}

// Добавление узла после заданного pN
int addNodeAfter(pList pL, pNode pN, int newdate) {
    pNode pnew, p = pL->top;
    pnew = (pNode)malloc(sizeof(Node));
    if (!pnew) return 0;

    pL->len++;
    pnew->value = newdate;

    // Если список пуст или вставка в начало
    if (isEmpty(pL) || (pN == p && newdate > p->value)) {
        pnew->next = p;
        pL->top = pnew;
        return 1;
    }

    pnew->next = pN->next;
    pN->next = pnew;
    return 1;
}

// Вывод списка на экран
void showList(pList pL) {
    pNode p = pL->top;
    if (isEmpty(pL)) printf("List is empty\n");
    while (p) {
        cout << p << " -> " << p->value << " -> " << p->next << endl;
        p = p->next;
    }
}

// Поиск узла по значению
pNode findNode(pList pL, int date) {
    pNode p = pL->top;
    if (isEmpty(pL)) return NULL;
    while (p && p->value > date) p = p->next;
    if (p && p->value == date) return p;
    return NULL;
}

// Вставка узла со значением date1 после всех узлов со значением date
int putAfter(pList pL, int date, int date1) {
    if (isEmpty(pL) || findNode(pL, date) == NULL) return 0;
    pNode p = pL->top;

    while (p) {
        if (p->value == date) {
            addNodeAfter(pL, p, date1);
            p = p->next; // Пропускаем только что добавленный
        }
        if (p) p = p->next;
    }
    return 1;
}

// Удаление узла, стоящего за pN
int delNode(pList pL, pNode pN) {
    pNode p = pN->next;

    // Исключение: в списке всего 1 узел
    if (pL->len == 1) {
        free(pL->top);
        pL->top = NULL;
        pL->len--;
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

int main() {
    pNode p;
    pList List = createList();
    int com = 1, a, b;

    while (com) {
        puts("1-add");
        puts("2-find");
        puts("3-del");
        puts("4-show");
        puts("5-clear");
        puts("6-Add after");
        puts("0-exit");
        cin >> com;

        switch (com) {
        case 1:
            cout << "Enter number: ";
            cin >> a;
            if (!addNodeAfter(List, getPointer(List, a), a))
                cout << "Node don't add.";
            break;

        case 2:
            cout << "Enter number: ";
            cin >> a;
            p = findNode(List, a);
            if (p)
                cout << "Number ==" << a << " adres: " << p << endl;
            else
                cout << "Number ==" << a << " Not found!!" << endl;
            break;

        case 3:
            cout << "Enter number: ";
            cin >> a;
            p = findNode(List, a);
            if (!p) {
                cout << "Value " << a << " Not Found!\n";
            }
            else {
                if (a == List->top->value) {
                    pNode temp = List->top;
                    List->top = temp->next;
                    List->len--;
                    free(temp);
                }
                else {
                    delNode(List, getPointer(List, a));
                }
                cout << "Value " << a << " Delete !\n";
            }
            break;

        case 4:
            showList(List);
            break;

        case 5:
            clearList(List);
            showList(List);
            break;

        case 6:
            cout << "Enter number E: ";
            cin >> a;
            cout << "Enter number E1 (E->E1): ";
            cin >> b;
            putAfter(List, a, b);
            showList(List);
            break;
        }
    }

    deleteList(List);
    return 0;
}