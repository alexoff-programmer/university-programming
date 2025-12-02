// 4Lec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdarg>
using namespace std;
typedef struct {
    int x, y;
} Point;

int sum(int k, ...) {
    va_list args;
    va_start(args, k);

    int S = 0;
    for (int i = 0; i < k; i++) {
        S += va_arg(args, int);
    }
    va_end(args);
    return S;
}

int prod(double k, ...) {
    va_list args;
    va_start(args, k);

    int prod = 1;
    do {
        prod *= k;
        k = va_arg(args, double);
    } while (k);
    va_end(args);
    return prod;
}

void f(Point a, Point b, Point c, Point d) {
    Point* p = &a;
    cout << "f &a = " << &a << "(" << ++p << ")" << endl;
    cout << "f &b = " << &b << "(" << ++p << ")" << endl;
    cout << "f &c = " << &c << "(" << ++p << ")" << endl;
    cout << "f &d = " << &d << "(" << ++p << ")" << endl;
}
void f1(Point d, Point c, Point b, Point a) {
    Point* p = &a;
    cout << "f &a = " << &a << "(" << ++p << ")" << endl;
    cout << "f &b = " << &b << "(" << ++p << ")" << endl;
    cout << "f &c = " << &c << "(" << ++p << ")" << endl;
    cout << "f &d = " << &d << "(" << ++p << ")" << endl;
}

void print_int(int a) {
    if (a < 0) {
        putchar('-');
        a = -a;
    }
    if (a == 0) {
        putchar('0');
        return;
    }
    if (a / 10)
        print_int(a / 10);
    putchar(a % 10 + '0');
}

void print_float(double a, int precision) {
    if (a < 0) {
        putchar('-');
        a = -a;
    }
    long long ipart = (long long)a;
    double f = (double) a - ipart;

    double mult = 1.0;
    for (int i = 0; i < precision; i++)
        mult *= 10.0;

    print_int(ipart);
    if (precision > 0) {
        putchar('.');

        long long fpart = (long long)(f * mult + 0.5);
        for (int i = 0; i < precision; i++) {
            mult /= 10.0;
            if (fpart < mult)
                putchar('0');
            else
                break;
        }
        print_int(fpart);
    }
    
}

void miniprintf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
            case 'd':
                print_int(va_arg(args, int));
                break;
            case 'f':
                print_float(va_arg(args, double), 3);
                break;
            default:
                putchar('%');
                putchar(*format);
                break;
            }
        }
        else {
            putchar(*format);
        }
        format++;
    }
    va_end(args);
}

int main()
{
    Point A{ 1, 2 }, B{ 2, 3 }, C{ 4, 5 }, D{ 6, 7 };
    f(A, B, C, D);
    cout << "-----------------------------------------\n";
    f1(A, B, C, D);

    cout << "prod1 = " << prod(2e0, 4e0, 3e0, 0e0) << "\n";
    cout << "prod1 = " << prod(1.5, 2.0, 3.0, 0.0) << "\n";

    miniprintf("decimal - %d, float - %f", 5, 5.127);
}

//void func1()
//{
//    char s[100];
//    cout << "Введите число: ";
//    cin >> s;
//
//    int i = 0;
//    int intDigits = 0;
//    bool beforeDot = true;
//
//    // Подсчёт цифр в целой части
//    while (s[i] != '\0')
//    {
//        if (s[i] == '.')
//        {
//            beforeDot = false;
//            break;
//        }
//        if (s[i] != '-') intDigits++;
//        i++;
//    }
//
//    cout << "Целая часть числа " << s << " содержит " << intDigits << " цифр." << endl;
//
//    // Печать строки в обратном порядке
//    int len = 0;
//    while (s[len] != '\0') len++;
//
//    cout << "Обратный порядок: ";
//    for (int j = len - 1; j >= 0; j--)
//    {
//        cout << s[j];
//    }
//
//    cout << endl;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
