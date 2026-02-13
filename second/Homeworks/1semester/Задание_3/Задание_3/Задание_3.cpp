#include <iostream>
using namespace std;

int a() {
    int c, count = 0;
    while ((c = getchar()) != '.') {
        if (c == 'a') {
            count++;
        }
    }
    
    return (cout << count << " раз"), 0;
}

int b() {
    int c, count = 0;
    bool is_u = 0;
    while ((c = getchar()) != '.' && !is_u)
        if (c == 'e') 
            count++;
        else if (c == 'u')
            is_u = 1;
    cout << count << " раз";
    return 0;
}
int c() {
    int c, d = 0;
    while ((c = getchar()) != '.') {
        if (c == 'n' || c == 'o')
            d = d ? d : c;
        else
            d = 0;
        if (c == 'n' && d == 'o' || c == 'o' && d == 'n') {
            cout << "Найдена последовательность.";
            break;
        }
        
    }
    return 0;
}

bool onlyFirstTime(int& iter) {
    if (iter == 0) {
        iter++;
        return 1;
    }
    return 0;
}

int d() {
    int c, d = 0, count_plus = 0, count_minus = 0;
    bool b = false;
    while ((c = getchar()) != '.') {
        if (c == '+' && d == '-' || c == '-' && d == '+') {
            if (!b)
                d == '+' ? count_plus++ : count_minus++;
            c == '+' ? count_plus++ : count_minus++;
            b = true;
        }
        else if (b) {
            cout <<"Встречается." << "\n" << "+: " << count_plus << "\n" << "-: " << count_minus;
            break;
        }
        d = c;
    }
   
    return 0;
}

int e() {
    int c, d = 0, e = 0, count = 0;
    while ((c = getchar()) != '.') {
        if (e == 'C' && d == '+' && c == '+')
            count++;
        e = d;
        d = c;
    }
    cout << "C++ в последовательности встречается " << count << " раз";
    return 0;
}

int f() {
    int c, d = 0, e = 0, f = 0, count = 0;
    while ((c = getchar()) != '.') {
        if (f == 'c' && e == 'h' && d == 'a' && c == 'r')
            return cout << "Есть слово char", 0;
        f = e;
        e = d;
        d = c;
    }
    
}

int g() {
    int c, count = 0, max = 0, f = 'a';
    while ((c = getchar())) {
        if (c != f) {
            f = 'a';
            if (!max || count > max)
                max = count;
            count = 0;
        }
        if (c == f) {
            count++;
            f++;
        }
        if (c == '.')
            return cout << "Наибольшая комбинация - " << max << " символов.", 0;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "ВВЕДИТЕ ПОСЛЕДОВАТЕЛЬНОСТЬ СИМВОЛОВ: ";
    return g();
}
