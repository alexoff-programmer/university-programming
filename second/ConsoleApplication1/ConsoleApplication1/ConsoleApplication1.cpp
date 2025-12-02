#include <iostream>
using namespace std;

// ЗАДАНИЯ ПРОДВИНУТОГО УРОВНЯ
int min(int* arr, int k) {
    if (k == 1)
        return arr[0];
    int temp = min(arr, k - 1);
    return arr[k - 1] < temp ? arr[k - 1] : temp;
}

int sum_pos() {
    int i;
    std::cin >> i;
    if (i < 0)
        return 0;
    return i + sum_pos();
}

int digits_a() {
    char c;
    cin >> c;
    if (c == '.')
        return 0;
    return 1 + digits_a();
}

int digits_b() {
    char c;
    cin >> c;
    if (c == '.')
        return 0;
    return (c >= '0' && c <= '9' ? 1 : 0) + digits_b();
}

int neg_sort() {
    int i;
    if (!(cin >> i)) {
        return -1;
    }
    if (i == 0) {
        return 0;
    }
    if (i < 0) {
        cout << i << " ";
        neg_sort();
    }
    neg_sort();
    cout << i << " ";
    return 0;
}

double f1(double x) {
    return x * x + x - 6;
}

double f2(double x) {
    return x * x - 144;
}

double find_root(double (*func)(double), double a, double b, double eps) {
    if (abs(b - a) <= 2 * eps) {
        return (a + b) / 2.0;
    }
    double c = (a + b) / 2.0;
    double fc = func(c);
    if (fc == 0.0) {
        return c;
    }
    if (func(a) * fc < 0) {
        return find_root(func, a, c, eps);
    }
    else {
        return find_root(func, c, b, eps);
    }
}

// ЗАДАНИЯ С ЛЕКЦИИ

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

int fib(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return fib(n-1) + fib(n-2);
}

int Count_Number(int* a, int n, int num, int i) {
    // подсчет кол-ва элементов массива, больших числа num 
    if (i == n) return 0;
    int add;
    return (a[i] > num) ? 1 : 0 + Count_Number(a, n, num, i + 1);
}

int count(int n) {
    if (n < 0) {
        n = -n;
    }
    if (n < 10)
        return 1;
    return 1 + count(n / 10);
}

int main() {
    int nums[4] = { 5, 2, 3, 4 };
    double res = find_root(f2, -15, 0, 0.1);

    cout << res << "\n";
    cout << f2(res);
}