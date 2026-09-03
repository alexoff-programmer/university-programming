// Stack Tasks.cpp : задания для практической работы 

// ПРОСТОЙ УРОВЕНЬ

#include "Stack.h"
#include "Stack Tasks.h"
#define N 20
using namespace std;

// Просто генератор случайных чисел для заполнения стека

void genStack(pStack stack, mt19937 &gen, uniform_int_distribution<int> &dist) {
    cout << "Запустили процесс генерации...\n";
    for (int i = 0; i < N; i++) {
        push(stack, dist(gen));
    }
}

// Генератор файла с текстом

ofstream genTextFile(string name, string str) {
    ofstream File(name);
    if (File.is_open()) {
        File << str;
        cout << "File is created." << endl;
    }
    else {
        cout << "Something is went wrong..." << endl;
    }
    return File;
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

/*
6. Вывести содержимое стека, начиная с обратного конца. В общем случае необходимо извлекать элементы стека по 
одному и вставлять их последовательно в другой стек, затем распечатать элементы из второго стека в прямом порядке.
*/

int task6(pStack stack, pStack service, mt19937& gen, uniform_int_distribution<int>& dist) {
    cout << "\nЗАДАЧА 6\n";
    genStack(stack, gen, dist);

    cout << "Изначальный стек:\n";
    showStack(stack);

    cout << "Процесс сортировки...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    showStack(service);

    clearStack(service);
    return 0;
}

/*
7. Преобразовать текстовый файл по следующему правилу. Если вновь считанный символ - "стирающий символ" (#), 
то удаляется один стоящий перед ним символ. Если вновь считанный символ является "символом-убийцей" (@), 
то удаляются все символы, находящиеся перед ним. Если считанный символ не является ни символом-убийцей, 
ни стирающим символом, то он помещается в стек. Если вновь считанный символ - стирающий символ, то удаляется 
символ в вершине стека. В случае, когда считанный символ является символом-убийцей, редактор очищает весь стек.
*/

int task7(pStack stack, pStack service, mt19937& gen, uniform_int_distribution<int>& dist) {
    cout << "\nЗАДАЧА 7\n";
    string fileName = "task7.txt";
    string str = "Ва@жный #э#т#а#п#.# Пока вы не закроете файл, данные могут оставаться в оперативной памяти (буфере) и не появиться на диске сразу.";

    genTextFile(fileName, str);
    ifstream file(fileName);

    cout << "Процесс наполнения стека и очистки...\n";
    if (file.is_open()) {
        char c;
        while (file.get(c)) {
            switch (c) {
                case '#': pop(stack); break;
                case '@': clearStack(stack); break;
                default: push(stack, c);
            }
        }
    }

    cout << "Подготовка стека к отображению...\n";
    while (!isEmpty(stack)) {
        push(service, pop(stack));
    }
    cout << "Процесс обработки завершён!\n";
    cout << "----------------------------\n";
    cout << "Изначальная строка:\n" << str << endl;
    cout << "Форматированная строка:\n";
    while (!isEmpty(service)) {
        char c = pop(service);
        cout << c;
        push(stack, c);
    }

    clearStack(stack);
    return 0;
}

/*
8. Создать стек из случайных целых чисел и поменять местами крайние элементы.
*/

int task8(pStack stack, pStack service, mt19937& gen, uniform_int_distribution<int>& dist) {
    cout << "\nЗАДАЧА 8\n";
    genStack(stack, gen, dist);

    int first; int last;

    cout << "Изначальный стек:\n";
    showStack(stack);

    cout << "Процесс сортировки...\n";
    last = pop(stack);
    while (!isEmpty(stack)) {
        first = pop(stack);
        if (isEmpty(stack))
            break;
        push(service, first);
    }
    push(stack, last);
    while (!isEmpty(service)) {
        push(stack, pop(service));
    }
    push(stack, first);

    cout << "Процесс сортировки завершён!\n";
    cout << "----------------------------\n";
    
    cout << "Стек, крайние элементы которого поменялись местами:\n";
    showStack(stack);

    clearStack(stack);
    return 0;
}

/*
9. Определить, является ли произвольная последовательность круглых, квадратных и фигурных скобок, правильно построенной. 
{ [ ] ( [ { { ( ) } } ] ) } правильно построенная.
*/

bool isStartBracket(char c) {
    return (c == '(' || c == '{' || c == '[');
}

bool isEndBracket(char c) {
    return (c == ']' || c == '}' || c == ')');
}

int task9(string seq) {
    cout << "\nЗАДАЧА 9\n";
    cout << "Получена последовательность:\n" + seq << endl;

    char temp;
    pStack stack = createStack();
    for (char c : seq) {
        if (isStartBracket(c)) {
            push(stack, c);
            continue;
        }
        if (!isEndBracket(c))
            continue;
        temp = pop(stack);
		if (c == '}' && temp != '{' || c == ')' && temp != '(' || c == ']' && temp != '[') {
            cout << "Последовательность скобок неверна.";
            return 0;
        }
    }

    if (isEmpty(stack)) {
        cout << "Последовательность скобок верна";
    }
    else {
        cout << "Последовательность скобок неверна.";
    }

    free(stack);
    return 0;
}

/*
10. Применить стек для вычисления выражения а) (6+8)*5-6/2; b) (5+7)*3-4*3.
Одной из форм представления выражений является польская инверсная запись, задающая выражение так, что
операции в нем записываются в порядке выполнения, а операнды находятся непосредственно перед операцией.
Например, выражение (6+8)*5-6/2 в польской инверсной записи имеет вид 6 8 + 5 * 6 2 / - .Особенность такой записи
состоит в том, что значение выражения можно вычислить за один просмотр записи слева направо, используя стек.
Каждое новое число заносится в стек, а операции выполняются над верхними элементами стека, заменяя эти элементы
результатом операции. Для приведенного выражения динамика изменения стека будет иметь вид S = <; <6>; <6,8>;
<14>; <14,5>; <70>; <70,6>; <70,6,2>; <70,3>; <67>,
*/


int task10(string problem) {
	pStack stack = createStack();
    for (char c : problem) {
		if (c >= '0' && c <= '9') {
            push(stack, c - '0');
            continue;
        }
		int b = pop(stack);
		int a = pop(stack);
        switch (c) {
            case '+': push(stack, a + b); break;
            case '-': push(stack, a - b); break;
            case '*': push(stack, a * b); break;
            case '/': push(stack, a / b); break;
		}
    }
	cout << (int) pop(stack);
	free(stack);
    return 0;
}