// Подготовка к КР.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

double Rec_Fact_Up(int n) {
    if (n <= 1)
        return 1;
    return n * Rec_Fact_Up(n - 1);
}

double Rec_Fact_Dn(int i, int m, double Mult = 1) {
    Mult *= i;
    if (i == m)
        return Mult;
    return Rec_Fact_Dn(i + 1, m, Mult);
}

double rec_degree(double n, int d) {
    if (d == 0)
        return 1;
    if (!(d % 2))
        return rec_degree(n, d / 2) * rec_degree(n, d / 2);
    else
        return n * rec_degree(n, d - 1);
}

double maxr(int* a, int s) {
    if (s == 1)
        return a[0];
    int max = maxr(a, s - 1);
    return max = a[s - 1] > max ? a[s - 1] : max, max;
}

double sum(int* a, int s) {
    if (s == 1)
        return a[0];
    return a[s - 1] + sum(a, s - 1);
}

void Printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n)
    {
        Printd(n / 10);
        putchar(n % 10 + '0');
        putchar(' ');
    }
}

int NOD_rec(int n, int m) {
    if (!(n % m))
        return m;
    return NOD_rec(m, n % m);
}

unsigned long fib(unsigned long n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 2) + fib(n - 1);
}

void Printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n) {
        Printd(n / 10);
        putchar(n % 10 + '0');
        putchar(' ');
    }
    
}

int main()
{
    int array[] = { 1, 2, 3, 4, 2, 3, 10, 2, -1};
    Printd(-10192);
    std::cout << fib(5);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
