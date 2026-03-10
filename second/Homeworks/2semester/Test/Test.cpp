#include <iostream>
#include <random>
#include <string>
#include <iomanip>

using namespace std;

// --- Базовая структура из исходника ---

typedef struct Node {
    int value; // Изменил на int для корректной работы с диапазоном -50...+50
    struct Node* next;
} *pNode;

typedef struct Stack {
    pNode top;
    int len;
} *pStack;

// --- Функции управления ---

pStack createStack() {
    pStack pS = (pStack)malloc(sizeof(Stack));
    if (pS) {
        pS->top = NULL;
        pS->len = 0;
    }
    return pS;
}

bool isEmpty(pStack pS) {
    return (pS == NULL || pS->top == NULL);
}

void push(pStack pS, int val) {
    pNode p = (pNode)malloc(sizeof(Node));
    if (p) {
        p->value = val;
        p->next = pS->top;
        pS->top = p;
        pS->len++;
    }
}

int pop(pStack pS) {
    if (isEmpty(pS)) return 0;
    pNode p = pS->top;
    int v = p->value;
    pS->top = p->next;
    free(p);
    pS->len--;
    return v;
}

void clearStack(pStack pS) {
    while (!isEmpty(pS)) pop(pS);
}

// Красивый вывод стека (с сохранением данных)
void display(pStack pS, string name) {
    cout << setw(15) << left << name << ": ";
    if (isEmpty(pS)) {
        cout << "[пусто]" << endl;
        return;
    }

    pStack temp = createStack();
    cout << "[ ";
    while (!isEmpty(pS)) {
        int v = pop(pS);
        cout << v << " ";
        push(temp, v);
    }
    cout << "]" << endl;

    while (!isEmpty(temp)) push(pS, pop(temp));
    free(temp);
}

// Заполнение случайными числами
void fill(pStack pS, int n, mt19937& gen) {
    uniform_int_distribution<int> dist(-50, 50);
    for (int i = 0; i < n; i++) push(pS, dist(gen));
}

// --- Задачи ---

void runTask1(mt19937& gen) {
    pStack mainS = createStack(), posS = createStack(), negS = createStack(), buf = createStack();
    fill(mainS, 10, gen);
    display(mainS, "Исходный");

    while (!isEmpty(mainS)) push(buf, pop(mainS));
    while (!isEmpty(buf)) {
        int v = pop(buf);
        push(v >= 0 ? posS : negS, v);
        push(mainS, v);
    }
    display(posS, "Положительные");
    display(negS, "Отрицательные");

    clearStack(mainS); free(mainS); free(posS); free(negS); free(buf);
}

void runTask2(mt19937& gen) {
    pStack mainS = createStack(), evenS = createStack(), oddS = createStack(), buf = createStack();
    fill(mainS, 10, gen);
    display(mainS, "Исходный");

    while (!isEmpty(mainS)) push(buf, pop(mainS));
    while (!isEmpty(buf)) {
        int v = pop(buf);
        push(v % 2 == 0 ? evenS : oddS, v);
        push(mainS, v);
    }

    cout << "Вершина чётных: " << (evenS->top ? to_string(evenS->top->value) : "NULL") << endl;
    cout << "Вершина нечётных: " << (oddS->top ? to_string(oddS->top->value) : "NULL") << endl;

    clearStack(mainS); free(mainS); free(evenS); free(oddS); free(buf);
}

void runTask3(mt19937& gen) {
    pStack s1 = createStack(), s2 = createStack(), buf = createStack();
    fill(s1, 10, gen);
    display(s1, "Стек 1 (До)");

    while (!isEmpty(s1) && (s1->top->value % 2 != 0)) {
        push(buf, pop(s1));
    }
    while (!isEmpty(buf)) push(s2, pop(buf));

    display(s1, "Стек 1 (После)");
    display(s2, "Стек 2");

    clearStack(s1); free(s1); free(s2); free(buf);
}

void runTask4(mt19937& gen) {
    pStack s = createStack(), buf = createStack();
    fill(s, 10, gen);
    display(s, "До чистки");

    while (!isEmpty(s)) {
        int v = pop(s);
        if (v % 2 != 0) push(buf, v);
    }
    while (!isEmpty(buf)) push(s, pop(buf));

    display(s, "Без чётных");
    clearStack(s); free(s); free(buf);
}

void runTask5(mt19937& gen) {
    pStack s = createStack(), buf = createStack();
    fill(s, 10, gen);
    display(s, "До удаления");

    int i = 0;
    while (!isEmpty(s)) push(buf, pop(s));
    while (!isEmpty(buf)) {
        int v = pop(buf);
        if (i % 2 == 0) push(s, v);
        i++;
    }

    display(s, "Итог (каждый 2-й)");
    clearStack(s); free(s); free(buf);
}

// --- Обновлённый main ---

int main() {
    setlocale(LC_ALL, "ru_ru");
    random_device rd;
    mt19937 gen(rd());

    int choice;
    do {
        cout << "\n--- МЕНЮ ТЕСТИРОВАНИЯ СТЕКА ---" << endl;
        cout << "1. Разделить +/-" << endl;
        cout << "2. Разделить чёт/нечёт" << endl;
        cout << "3. Перенос до первого чётного" << endl;
        cout << "4. Удалить все чётные" << endl;
        cout << "5. Удалить каждый второй" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задачу: ";
        cin >> choice;

        switch (choice) {
        case 1: runTask1(gen); break;
        case 2: runTask2(gen); break;
        case 3: runTask3(gen); break;
        case 4: runTask4(gen); break;
        case 5: runTask5(gen); break;
        case 0: cout << "Программа завершена." << endl; break;
        default: cout << "Ошибка выбора!" << endl;
        }
    } while (choice != 0);

    return 0;
}