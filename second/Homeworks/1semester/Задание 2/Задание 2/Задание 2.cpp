#include <iostream>
using namespace std;

int a() {
	int c, count = 0;
	bool is_dot = 0;
	while ((c = getchar()) != EOF) {
        if (c == '.')
            is_dot = 1;
        else if (isdigit(c) && is_dot == 1) { // добавил условие is_dot == 1, до этого его упустил
            if (count >= 2)
                continue;
            count++;
        }
        else {
            is_dot = 0;
            count = 0;
        }
        cout << (char)c;
    }
	return 0;
}

int b() {
    int c;
    bool l = true, z = false;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            if (c != '0' || !l) {
                cout << (char)c;
                l = false;
            }
            z = true;
        }
        else if (c == '.') {
            if (l && z)
                cout << '0';
            cout << (char)c;
            l = false;
        }
        else {
            if (l && z)
                cout << '0';
            cout << (char)c;
            l = true;
            z = false;
        }
    }
    return 0;
}

// a+12.3456-b-0.456789+1.3-45678
// a-000123+bc+0000.0008-0000+0001.07-00105+0.1908900


int main() {
	return b();
}