#include <iostream>
#include <cmath>
using namespace std;
/* 3
int main() {
    setlocale(LC_ALL, "Russian");
    double x, y;
    cin >> x >> y;
    if (x == 0 || y == 0) {
        if (x != 0)
            cout << "�� ��� x.";
        else if (y != 0)
            cout << "�� ��� y.";
        else
            cout << "� ������ ���������.";
    }
    else if (x > 0) {

        if (y > 0) {
            cout << "� ������ ��������.";
        }
        else {
            cout << "� �������� ��������.";
        }
    }
    else {
        if (y > 0) {
            cout << "�� ������ ��������.";
        }
        else {
            cout << "� ������� ��������.";
        }
    }
    return 0;
}
*/
/* 4.1
int main() {
    double x, y, r, sqr_sum;
    cin >> x >> y >> r;
    sqr_sum = sqrt(pow(x,2) + pow(y,2));
    if (sqr_sum <= r) {
        cout << "�����������."
    }
    else {
        cout << "�� �����������."
    }
}
*/
/* 4.2
int main() {
    double x, y, r, R, sqr_sum;
    cin >> x >> y >> r;
    R = 2 * r;
    sqr_sum = sqrt(pow(x,2) + pow(y,2));
    if (sqr_sum <= R && sqr_sum >= r) {
        cout << "�����������."
    }
    else {
        cout << "�� �����������."
    }
}
*/
/* 5.1
int main() {
    double x;
    cin >> x;
    if (x <= 0) {
        cout << 0;
    }
    else if (x > 0 && x <= 1) {
        cout << x;
    }
    else {
        cout << pow(x, 2);
    }
}
*/
/* 5.2
int main() {
    double x;
    cin >> x;
    if (x > 0) {
        cout << log10(x);
    }
    else if (x == 0) {
        cout << 0;
    }
    else {
        cout << pow(x, 2);
    }
}
*/
/* 6
int main() {
    int N, a, b, c;
    cin >> N;
    if (N > 9 && N < 1000) {
        if (N < 100) {
            cout << N / 10 + N % 10;
        }
        else {
            a = N % 10 != 0 ? N % 10 : 1;
            b = (N / 10) % 10 != 0 ? (N / 10) % 10 : 1;
            c = N / 100 != 0 ? N / 100 : 1;
            cout << a * b * c;
        }
    }
}
*/
/* 7
int main() {
    bool isZero = false;
    int N, num, prod = 1, sum = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (isZero) {
            sum += num;
            prod *= num;
        }
        if (num == 0)
            isZero = true;
    }
    cout << "Production = " << prod << ", Sum = " << sum;
}
*/
/* 8
int main() {
    int N, num, max_num, min_num;
    cin >> N;
    cin >> num;
    max_num = min_num = num;
    for (int i = 0; i < N - 1; i++) {
        cin >> num;
        max_num = max_num < num ? num : max_num;
        min_num = min_num > num ? num : min_num;
    }
    cout << "Max = " << max_num << ", Min = " << min_num;
}
*/
/* 9
int main() {
    setlocale(LC_ALL, "Russian");
    int n, sum = 0;
    cin >> n;
    for (int i = 1; (double) i <= n / 2.0; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (n == sum)
        cout << "����� �������� �����������.";
    else
        cout << "����� �� �������� �����������.";
}
*/
/* 10.1
int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += pow((-1), i) / (2 * i + 1);
	}
}
*/
/* 10.2
int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += pow((-1), i + 1) / (i * (i + 1));
	}
}
*/
/* 11.1
int main() {
	double res = 1, t;
	for (int i = 2; i <= 10; i++) {
		t = 1;
		for (int j = 2; j <= i; j++) {
			t *= j;
		}
		res -= 1 / t;
	}
	cout << res;
}
*/
/* 11.2
int main() {
	double res = 1, t;
	for (int i = 1; i <= 8; i++) {
		t = 1;
		for (int j = 2; j <= i; j++) {
			t *= j;
		}
		res *= 2 + pow((-1), i + 1) / t;
	}
	cout << res;
}
*/