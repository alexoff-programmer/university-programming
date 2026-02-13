// Проги.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int _sum(int* s, int n) {
    if (n == 1) return s[0];
    else return s[n - 1] + _sum(s, n - 1);
}

int rec_degree(int x, int n) {
    double r;
    if (!n) return 1;
    if (!(n % 2)) return r = rec_degree(x, n / 2), r * r;
    else return x * rec_degree(x, n - 1);
}

int NOD_rec(int n, int m) {
    if (!(n % m)) return m;
    else return NOD_rec(m, n % m);
}

double fact(double a) {
    if (a == 1)
        return 1;
    if (a == 2)
        return 2;
    return fact(a - 1) * a;
}

double Rec_Fact_Dn(int i, int m, double Mult = 1) {
    std::cout << "i = " << i << ", Mult = " << Mult << "*" << i << std::endl;
    Mult = Mult * i;
    if (i == m) {
        return Mult;
    }
    
    return Rec_Fact_Dn(i + 1, m, Mult);
}

int Rec_Fact_Up(int i) {
    if (i <= 0)
        return 1;
    return i * Rec_Fact_Up(i - 1);
}
 
void Printd(int n) { // Печать числа в виде последовательности символов.
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

int nod(int a, int b) {
    while (a != b) {
        a = a > b ? a - b : a;
        b = b > a ? b - a : b; // Наибольший общий делитель - вычитать одно из другого, присваивать результат, а затем повторять действие.
    }
    return a;
}

int nodModern(int a, int b, int c = 0) {
    if (a < b)
        return (std::cout << "Введите в последовательности a > b."), 0;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    std::cout << NOD_rec(391, 299) << "\n";
    Printd(-125);
    std::cout << std::endl;
    std::cout << Rec_Fact_Dn(3, 6); // прерывание (обслуживание работы функции), выделяется область памяти
    // По значению (по умолчанию, копия переменной), по ссылке (ссылка на переменную), по указателю (указатель на переменную).
    // По завершению работы функции стек функции уничтожается.
}