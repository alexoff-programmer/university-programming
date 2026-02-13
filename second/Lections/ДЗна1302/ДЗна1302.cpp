#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int x = 5;
    int y = 13;
    cout << "x = " << x << ", y = " << y << endl << endl;
    int* p = &x;
    int* q = &y;
    cout << "*p = " << *p << ", *q = " << *q << endl << endl;

    cout << "sizeof(x) = " << sizeof(x) << ", значение x = " << x << endl;
    cout << "sizeof(y) = " << sizeof(y) << ", значение y = " << y << endl;
    cout << "sizeof(p) = " << sizeof(p) << ", значение p (адрес x) = " << p << endl;
    cout << "sizeof(q) = " << sizeof(q) << ", значение q (адрес y) = " << q << endl << endl;

    int** pp = &p;

    cout << "pp = " << pp << endl;
    cout << "*pp = " << *pp << endl;
    cout << "**pp = " << **pp << endl;

    **pp = 25;  
    cout << "x = " << x << ", **pp = " << **pp << endl;
    return 0;
}