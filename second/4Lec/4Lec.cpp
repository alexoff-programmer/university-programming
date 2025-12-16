// 4Lec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdarg>
using namespace std;
typedef struct {
    double x, y;
} Point, *pPoint;


double dist(pPoint A, pPoint B) {
    double d;
    d = sqrt(pow((A->x - B->x), 2) + pow((A->y - B->y), 2));
    return d;
}

Point make(double x, double y) {
    Point temp;
    temp.x = x;
    temp.y = y;
    return temp;
}

Point mid(Point A, Point B) {
    return make((A.x + B.x) / 2, (A.y + B.y) / 2);
}

void show(Point A) {
    cout << "x(" << A.x << ") y(" << A.y << ")" << endl;
}

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
        /*else if (*format == '\\') {
            format++;
            switch (*format) {
            case 't':
                putchar('\t');
                break;
            case 'n':
                putchar('\n');
                break;
            }
            case '\\':
                putchar('\\');
                break;
            default:
                putchar()
        }*/
        else {
            putchar(*format);
        }
        format++;
    }
    va_end(args);
}

void miniprint(const char* format, ...) {
    va_list list;
    va_start(list, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
            case 'd':
                printf("%d", va_arg(list, int));
                break;
            case 'f':
                printf("%f", va_arg(list, double));
                break;
            default:
                putchar('%');
                putchar(*format);
                break;
            }
        }
        else 
            putchar(*format);
        format++;
    }
    va_end(list);
}

int main()
{
    /*Point A{ 1, 2 }, B{ 2, 3 }, C{ 4, 5 }, D{ 6, 7 };
    f(A, B, C, D);
    cout << "-----------------------------------------\n";
    f1(A, B, C, D);

    cout << "prod1 = " << prod(2e0, 4e0, 3e0, 0e0) << "\n";
    cout << "prod1 = " << prod(1.5, 2.0, 3.0, 0.0) << "\n";*/

    miniprintf("decimal - %d, float - %f", 5, 5.127);
    miniprint("decimal - %d, float - %f", 5, 5.127);

    Point A{ 0., -3. }, B{ 0., 1. };
    pPoint pA = &A, pB = &B;

    cout << "\n" << "AB = " << dist(pA, pB) << endl;
    show(A);
    show(B);
    show(mid(A, B));
}