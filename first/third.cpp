#include <iostream>
#include <cstdlib>
#include <iomanip>
#define N 6
using namespace std;

void task1() {
	int a[N];
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] > 7)
			a[i] = 7;
		cout << a[i] << " ";
	}
}

void task2() {
	int a[N];
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i += 2) {
		temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
	}
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
}

void task3() {
	int a[N], b[N], c[N];
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 101 - 50;
		b[i] = rand() % 101 - 50;
		c[i] = a[i] * b[i];
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n";
	cout << "B = [ ";
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	cout << "] \n";
	cout << "C = [ ";
	for (int i : c)
		cout << i << " ";
	cout << "]";
}

void task4() {
	int a[N];
	int p;
	cin >> p;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 21 - 10;
		if (a[i] % p == 0)
			cout << a[i] << " ";
	}
	cout << "\nA = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n";
}

void task5() {
	int a[30][3];
	for (int i = 0; i < 30; i++) {
		a[i][0] = i + 1;
		a[i][1] = rand() % 101;
		a[i][2] = 9 * a[i][1] / 5 + 32;
	}
	cout << " Day   C   F" << endl;
	for (int i = 0; i < 30; i++) {
		cout << setw(4) << a[i][0] << setw(4) << a[i][1] << setw(4) << a[i][2] << endl;
	}
}

void task6() {
	int a[N];
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 21 - 10;
		if (a[i] % 5 == 0 && a[i] % 7 != 0) {
			sum += a[i];
			cnt++;
		}
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n";
	cout << "Sum = " << sum << ", Count = " << cnt;
}

void task7() {
	int x[N];
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		x[i] = rand() % 21 - 10;
		if (x[i] % 3 == 0 && x[i] % 9 != 0) {
			sum += x[i];
			cnt++;
		}
	}
	cout << "X = [ ";
	for (int i = 0; i < N; i++) {
		cout << x[i] << " ";
	}
	cout << "] \n";
	cout << "Mid = " << (float) sum / cnt;
}

void task8() {
	int b[N];
	int sum = 0, prod = 1;
	for (int i = 0; i < N; i++) {
		b[i] = rand() % 21 - 10;
		if (b[i] >= 0) {
			sum += b[i];
		}
		else {
			prod *= b[i];
		}
	}
	cout << "B = [ ";
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
	cout << "] \n";
	cout << "Sum = " << sum << ", Prod = " << prod;
}

void task9() {
	int a[N];
	int sum = 0;
	int temp;
	for (int i = 0; i < N; i++) {
		sum = 0;
		a[i] = rand() % 21 - 10;
		for (int j = 0; j < sizeof(a[i]) / 4; j++) {
			temp = a[i];
			sum += temp % 10;
			temp /= 10;
		}
		if (sum % 2 == 0)
			cout << a[i] << " ";
	}
}

void task10() {
	float a[N];
	float maxn, minn;
	for (int i = 0; i < N; i++) {
		a[i] = (float) (rand() % 10000) / 100;
		if (i == 0)
			maxn = minn = a[0];
		if (maxn < a[i])
			maxn = a[i];
		else if (minn > a[i])
			minn = a[i];
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n";
	cout << "Min = " << minn << ", Max = " << maxn;
}

void task11() {
	float a[N];
	float maxn, max2n;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (i == 0)
			maxn = max2n = a[0];
		if (maxn < a[i]) {
			max2n = maxn;
			maxn = a[i];
		}
		else if (max2n < a[i] && a[i] != maxn) {
			max2n = a[i];
		}
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n";
	cout << "First max = " << maxn << ", Second max = " << max2n;
}

void task12() {
	float a[N], c[N];
	float maxn;
	for (int i = 0; i < N; i++) {
		a[i] = (float)(rand() % 10000) / 100;
		if (i == 0)
			maxn = a[i];
		if (maxn < a[i])
			maxn = a[i];
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << "] \n" << "C = [ ";
	for (int i = 0; i < N; i++) {
		c[i] = a[i] * maxn;
		cout << c[i] << " ";
	}
	cout << " ]";
	
}

void task13() {
	float a[N];
	float minn;
	for (int i = 0; i < N; i++) {
		a[i] = (float)(rand() % 10000) / 100;
		if (i == 0)
			minn = a[i];
		if (minn > a[i])
			minn = a[i];
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		a[i] -= minn;
		cout << a[i] << " ";
	}
	cout << " ]";
}
void task14() {
	int a[N];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 100;
		if (i % 2 == 0 && a[i] % 2 == 1)
			cnt++;
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	cout << " ], Count = " << cnt;
}

void task15a() {
	int a[N];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 1001 - 500;
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < N; i++) {
		if (a[i] > 0 && a[i + 1] > 0)
			cnt++;
	}
	cout << " ], Count = " << cnt;
}

void task15b() {
	int a[N];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		a[i] = rand() % 1001 - 500;
	}
	cout << "A = [ ";
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
	for (int i = 0; i < N - 1; i++) {
		if (a[i] > 0 && a[i + 1] < 0 ||
			a[i] < 0 && a[i + 1] > 0) 
		{
			cnt++;
		}	
	}
	cout << " ], Count = " << cnt;
}




int main() {
	srand(time(NULL));
	task11();
	return 0;
}