#include <iostream>
using namespace std;

int a() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '?') {
            cout << '!';
            continue;
        }
        cout << (char)c;
    }
    return 0;
}

int b() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '&')
            cout << (char)c;
        if (c == '-')
            continue;
        cout << (char)c;
    }
    return 0;
}
int c() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c < 97 && c > 122)
            continue;
        cout << (char)c;
    }
    return 0;
}
int d() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c > 65 && c < 90)
            c += 32;
        cout << (char)c;
    }
    return 0;
}
int e() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c > 97 && c < 122)
            c -= 32;
        cout << (char)c;
    }
    return 0;
}
int f() {
    int c;
    bool d = false;
    while ((c = getchar()) != EOF) {
        if (c == '+')
            if (!d)
                d = true;
            else
                continue;
        else
            d = false;
        cout << (char)c;
    }
    return 0;
}

int g() {
    int c, count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '*') {
            ++count;
            continue;
        }
        else
            if (count >= 2) {
                count /= 2;
                while (count > 0) {
                    cout << '+';
                    --count;
                }
            }
            else if (count == 1) {
                count = 0;
                cout << '*';
            }
        cout << (char)c;
    }
    return 0;
}
int h() {
    int c;
    bool l = false, f = true;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            if (c == '0' && f)
                l = true;
            else if (c != '0')
                l = false;
            f = false;
            if (l)
                continue;
        }
        else {
            if (l)
                cout << '0';
            f = true;
            l = false;
        }
        cout << (char)c;
    }
    return 0;
}
int i() {
    int c, a = 0, b = 0;
    bool s = false;
    while ((c = getchar()) != EOF) {
        if (c == 't') {
            s = true; // c = t a = t | c = h b = t a = h | c = e  
            a = c;
            continue;
        }
        if (s) {
            b = a;
            a = c;
            s = false;
            continue;
        }
        if (!s && (b == 't' && a == 'h' && c == 'e')) {
            a = b = 0;
            continue;
        }
        else if (a && b) {
            cout << (char)b << (char)a;
            a = b = 0;
        }
        cout << (char)c;
    }
    return 0;
}
int j() {
    int c, a = 0;
    bool d = false;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            if (c < a)
                d = true;
            a = c;
            if (d)
                continue;
        }
        else {
            d = false;
        }
        cout << c;
        
    }
    return 0;
}
int k() {
    int c, a = 0, b = 0, d = 0, e = 0, i = 0;
    while ((c = getchar()) != EOF) {
        if (c == 'c' || i) {
            i++;
            e = d;
            d = b;
            b = a;
            a = c;
            if (i == 4)
                i = 0;
        }
        cout << (char)c;
        if (!i && (e = 'c' && d == 'h' && b == 'i' && a == 'l' && c == 'd')) {
            cout << "ren";
            a = b = d = e = 0;
        }
        else if (a && b && d && e) {
            a = b = d = e = 0;
        }
    }
    return 0;
}

int l() {
    int c;
    bool d = false;
    while ((c = getchar()) != EOF) {
        if (c == '{')
            d = true;
        else if (c == '}') {
            d = false;
            continue;
        }
        if (d)
            continue;
        cout << (char)c;
    }
    return 0;
}


int main() {
    return g();
}