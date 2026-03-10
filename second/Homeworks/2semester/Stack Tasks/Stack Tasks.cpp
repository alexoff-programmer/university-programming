// Stack Tasks.cpp : задания для практической работы 

// ПРОСТОЙ УРОВЕНЬ

#include <iostream>
#include <random>
#include <string>
#define N 20
using namespace std;

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
        pS->top = NULL;
        pS->len = 0;
    }
    return pS;
}

int isEmpty(pStack pS) {
    if (pS->top && pS->len) return 0;
    return 1;
}

int push(pStack pS, int c) {
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

int pop(pStack pS) {
    pNode p = pS->top;
    int c = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return c;
}

void showStack(pStack pS) {
    pStack qS = createStack();
    int c;
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

// Просто генератор случайных чисел для заполнения стека

void genStack(pStack stack, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "Запустили процесс генерации...\n";
    for (int i = 0; i < N; i++) {
        push(stack, dist(gen));
    }
}

/*
1. Создать стек из случайных целых чисел, лежащих в диапазоне -50 до +50
и преобразовать его в два стека. Первый должен содержать только положительные числа,
а второй - только отрицательные. Порядок следования чисел должен быть сохранен.
*/

int task1(pStack stack, pStack service, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "\nЗАДАЧА 1\n";
    genStack(stack, gen, dist);

    pStack positive = createStack();
    pStack negative = createStack();
    int temp;

    cout << "Процесс сортировки...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    while (!isEmpty(service)) {
        temp = pop(service);
        push(temp >= 0 ? positive : negative, temp);
        push(stack, temp);
    }
    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальный стек:\n";
    showStack(stack);
    cout << "Положительные:\n";
    showStack(positive);
    cout << "Отрицательные:\n";
    showStack(negative);

    free(positive); free(negative);
	clearStack(stack);
    return 0;
}

/*
2. Создать стек из случайных целых чисел, лежащих в диапазоне -50 до +50. Создать два
результирующих стека. Первый из них должен содержать все элементы исходного стека с
четными значениями, а во второй - с нечетными. Один из результирующих стеков может
остаться пустым. Вывести значения вершин обоих стеков. Если стек пустой, то вывести null.
Порядок следования чисел должен быть сохранен.
*/

int task2(pStack stack, pStack service, mt19937 &gen, uniform_int_distribution<int> &dist) {
	cout << "\nЗАДАЧА 2\n";
    genStack(stack, gen, dist);

    pStack odd = createStack();
    pStack even = createStack();
    int temp;

    cout << "Процесс сортировки...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    while (!isEmpty(service)) {
        temp = pop(service);
        push(temp % 2 != 0 ? odd : even, temp);
        push(stack, temp);
    }
    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальный стек:\n";
    showStack(stack);
    cout << "Нечётные:\n";
    cout << "top = " << (odd->top ? to_string(odd->top->value) : "NULL") << endl;
    showStack(odd);
    cout << "Чётные:\n";
    cout << "top = " << (even->top ? to_string(even->top->value) : "NULL") << endl;
    showStack(even);

    free(odd); free(even);
    clearStack(stack);
    return 0;
}

/*3.
Создать стек из случайных целых чисел и преобразовать его в два стека, перемещая элементы
из первого стека во второй, пока значение вершины первого стека не станет четным. Если в
первом стеке нет элементов с четными значениями, то переместить из первого стека во второй
все элементы. Вывести на экран значения вершин обоих стеков. Если первый стек пустой, то
вывести null. Порядок следования чисел должен быть сохранен.
*/

int task3(pStack stack, pStack service, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "\nЗАДАЧА 3\n";
    genStack(stack, gen, dist);

	pStack firstStack = createStack();
    pStack secondStack = createStack();
    int temp;

    cout << "Процесс сортировки...\n";
    // Подготовка первого стека
	while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    while (!isEmpty(service)) {
        temp = pop(service);
		push(firstStack, temp);
        push(stack, temp);
    }

    while (!isEmpty(firstStack) && !(firstStack->top->value % 2 == 0)) {
        temp = pop(firstStack);
        push(service, temp);
    }
    while (!isEmpty(service)) {
        temp = pop(service);
        push(secondStack, temp);
	}
    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальный стек:\n";
    showStack(stack);
    cout << "Первый стек:\n";
    if (isEmpty(firstStack)) {
        cout << "top = " << (firstStack->top ? to_string(firstStack->top->value) : "NULL") << endl;
		cout << "NULL\n";
    }
    else {
        showStack(firstStack);
    }
    cout << "Второй стек:\n";
    cout << "top = " << (secondStack->top ? to_string(secondStack->top->value) : "NULL") << endl;
    showStack(secondStack);

    free(firstStack); free(secondStack);
    clearStack(stack);
    return 0;
}

/*
4. Создать стек из случайных целых чисел и удалить из него записи с четными числами.
Порядок следования чисел должен быть сохранен.
*/

int task4(pStack stack, pStack service, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "\nЗАДАЧА 4\n";
    genStack(stack, gen, dist);

	pStack oddStack = createStack();
    int temp;

    cout << "Процесс сортировки...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    while (!isEmpty(service)) {
        temp = pop(service);
        if (temp % 2 != 0) {
            push(oddStack, temp);
        }
		push(stack, temp);
    }

    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальный стек:\n";
    showStack(stack);
    cout << "Стек без чётных чисел:\n";
    showStack(oddStack);

	free(oddStack);
    clearStack(stack);
    return 0;
}

/*
5. Создать стек из случайных целых чисел и удалить из него каждый второй элемент. Порядок
следования чисел должен быть сохранен.
*/

int task5(pStack stack, pStack service, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "\nЗАДАЧА 5\n";
    genStack(stack, gen, dist);

    pStack halfStack = createStack();
    int temp;
    int i = 0;

    cout << "Процесс сортировки...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    while (!isEmpty(service)) {
        temp = pop(service);
        if (i % 2 == 0) {
            push(halfStack, temp);
        }
        i++;
        push(stack, temp);
    }

    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальный стек:\n";
    showStack(stack);
    cout << "Стек без чётных по номеру чисел:\n";
    showStack(halfStack);

    free(halfStack);
    clearStack(stack);
    return 0;
}

int main()
{
    setlocale(LC_ALL, "ru_ru");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(-50, 50);
    cout << "Подключили генератор...\n";

    pStack stack = createStack();
    pStack service = createStack();
    cout << "Создали стек...\n";

    task1(stack, service, gen, dist);
    task2(stack, service, gen, dist);
    task3(stack, service, gen, dist);
    task4(stack, service, gen, dist);
    task5(stack, service, gen, dist);

    return 0;
}
