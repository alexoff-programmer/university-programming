#include <iostream>
#include <random>
#include <fstream>
#include "Stack.h"
#include "Stack Tasks.h"

using namespace std;

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

    //task1(stack, service, gen, dist);
    //task2(stack, service, gen, dist);
    //task3(stack, service, gen, dist);
    //task4(stack, service, gen, dist);
    //task5(stack, service, gen, dist);
    //task6(stack, service, gen, dist);
    //task7(stack, service, gen, dist);
    //task8(stack, service, gen, dist);
    //task9("{[]{[]{({[{}]})}}");
    task10("68+5*62/-");
    cout << endl;
    task10("57+3*43*-");

    return 0;
}
