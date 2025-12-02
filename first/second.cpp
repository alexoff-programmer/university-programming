#include <iostream>
#include <cmath>
using namespace std;

// 2 int main() {
//	setlocale(LC_ALL, "Russian");
//	int num;
//	string rubles = "рублей";
//	cout << "Введите кол-во рублей: ";
//	cin >> num;
//	switch (num % 10)
//	{
//	case 1: rubles = "рубль"; break;
//	case 2: case 3: case 4: rubles = "рубля"; break;
//	default: break;
//	}
//	switch (num % 100)
//	{
//	case 11: case 12: case 13: case 14: rubles = "рублей";
//	default: break;
//	}
//	cout << num << " " << rubles;
//}

/* 3
int main() {
	setlocale(LC_ALL, "Russian");
	int code;
	const int VLADIVOSTOK = 432, MOSKVA = 495, 
		KRASNODAR = 861, VOLGOGRAD = 844;
	double total_cost, minutes, price;
	const double VLADIVOSTOK_PRICE = 9.20, MOSKVA_PRICE = 4.10, 
		KRASNODAR_PRICE = 2.05, VOLGOGRAD_PRICE = 2.50;
	cin >> code >> minutes;
	switch (code)
	{
	case VLADIVOSTOK: total_cost = VLADIVOSTOK_PRICE * minutes; price = VLADIVOSTOK_PRICE; break;
	case MOSKVA:; total_cost = MOSKVA_PRICE * minutes; price = MOSKVA_PRICE; break;
	case KRASNODAR: total_cost = KRASNODAR_PRICE * minutes; price = KRASNODAR_PRICE; break;
	case VOLGOGRAD: total_cost = VOLGOGRAD_PRICE * minutes; price = VOLGOGRAD_PRICE; break;
	default: cout << "�������� ��� �������."; return 0;
	}
	cout << "��������� ������: " << price << ", ����� ���������: " << total_cost << ".";
	return 0;
}
*/
/* 4
int main() {
	setlocale(LC_ALL, "Russian");
	int n, last, first;
	cin >> n; first = n;
	while (first > 9) {
		first /= 10;
	}
	last = n % 10;
	if (last == first)
		cout << "���������.";
	else
		cout << "�� ���������";
}
*/
/* 5
int main() {
	setlocale(LC_ALL, "Russian");
	int n, t = 0;
	bool sorted = true;
	cin >> n;
	while (n > 0) {
		if (n % 10 <= t) {
			cout << "�� ����������� �� ��������.";
			return 0;
		}
		t = n % 10;
		if (n >= 10) n /= 10;
		else break;
	}
	cout << "����������� �� ��������.";
}
*/
// int main() {
// 6 unsigned int n, max, min;
// int temp;
// cin >> n;
// max = min = n % 10;
// while (n > 10) {
//     temp = n % 10;
//     if (temp > max) max = temp;
//     else if (temp < min) min = temp;
//     n /= 10;
// }
// cout << "Max = " << max << endl
//     << "Min = " << min << endl;
// }

// 8.1 int main() {
//	setlocale(LC_ALL, "Russian");
//	int i = 1;
//	float eps = 1.0e-5, a, t = 1, sum = 0;
//	do {
//		a = 1 / (t * i);
//		t *= -1;
//		i++;
//		sum += a;
//	} while (fabs(a) >= eps);
//	cout << "Приближённая сумма последовательности: " << sum;
//}

// 8.2 int main() {
//	setlocale(LC_ALL, "Russian");
//	int i = 1;
//	float eps = 1.0e-5, a, t = 1, sum = 0;
//	do {
//		a = 1 / (t * i);
//		t *= -1;
//		i += 2;
//		sum += a;
//	} while (fabs(a) >= eps);
//	cout << "Приближённая сумма последовательности: " << sum;
//}

// 9 int main() {
//	setlocale(LC_ALL, "Russian");
//	int m, n;
//	double x, y;
//	cout << "Введите M: ";
//	cin >> m;
//	cout << "Введите N: ";
//	cin >> n;
//	cout << "x      y = f(x)" << fixed << setprecision(4) << endl;
//	for (int i = m; i < n; i++) {
//		x = 0.1 * i;
//		y = sin(x);
//		cout << x << " " << y << endl;
//	}
//	return 0;
//}

// 10.a int main() {
//	float x, y = 1, sum = 0;
//	int n;
//	cout << "Enter X and N: ";
//	cin >> x >> n;
//	for (int i = 0; i < n; i++) {
//		y *= sin(x);
//		sum += y;
//	}
//	cout << fixed << "Here is Y: " << y;
//	return 0;
//}

// 10.b int main() {
//	float x, y = 1, sum = 0;
//	int n;
//	cout << "Enter X and N: ";
//	cin >> x >> n;
//	for (int i = 0; i < n; i++) {
//		y = sin(x);
//		x *= x;
//		sum += y;
//	}
//	cout << fixed << "Here is Y: " << y;
//	return 0;
//}

// 10.c int main() {
//	float x, y = 1, sum = 0;
//	int n;
//	cout << "Enter X and N: ";
//	cin >> x >> n;
//	for (int i = 0; i < n; i++) {
//		y = sin(x);
//		x = sin(x);
//		sum += y;
//	}
//	cout << fixed << "Here is Y: " << y;
//	return 0;
//}