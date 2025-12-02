#include <iostream>
#include <conio.h>
using namespace std;

int add3(int& a) {
    return a += 3;
}

int a() {
    int c;
    for (int i = 0; i < 2; i++) {
        c = _getch();
        if (c >= '0' && c <= '5') {
            cout << (char)add3(c);
        }
    }
    return 0;
}

int main()
{
    return a();
}
