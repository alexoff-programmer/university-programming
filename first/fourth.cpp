#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define k 10

int task1() {
	int A[k];
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 100;
		if (A[i] % 2 == 0)
			cnt++;
	}
	int* B = new int[cnt];
	for (int i = 0, j = 0; i < k; i++) {
		if (A[i] % 2 == 0) {
			B[j] = A[i];
			cout << B[j] << " ";
			j++;			
		}
	}
	return 0;
}

int task2() {
	int A[k];
	int cnt = 0, cnt2 = 0;
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 101 - 50;
		if (A[i] > 0)
			cnt++;
		if (A[i] < 0)
			cnt2++;
	}
	int* B = new int[cnt];
	int* C = new int[cnt2];
	for (int i = 0, j = 0; i < k; i++) {
		if (A[i] > 0) {
			B[j] = i;
			cout << B[j] << " ";
			j++;
		}
	}
	cout << endl;
	for (int i = 0, j = 0; i < k; i++) {
		if (A[i] < 0) {
			C[j] = i;
			cout << C[j] << " ";
			j++;
		}
	}
	return 0;
}

int task3() {
	int A[k], B[k];
	int j = 0;
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 101 - 50;
		if (A[i] < 0) {
			B[j] = A[i];
			j++;
		}
	}
	for (int i = 0; i < k; i++) {
		if (A[i] > 0) {
			B[j] = A[i];
			j++;
		}
	}
	for (int i = 0; i < k; i++) {
		if (A[i] == 0) {
			B[j] = 0;
			j++;
		}
		cout << B[i] << " ";
	}
	return 0;
}

bool is_simple(int num) {
	bool res = true;
	if (num == 1)
		return res;
	if (num == 2)
		return res;
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0)
			res = false;
	}
	return res;
}

int task4() {
	int A[k];
	int sum = 0;
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 101;
		cout << A[i] << " ";
		if (is_simple(A[i]))
			sum += A[i];
	}
	cout << "\nSum = " << sum;
	return 0;
}
// -1 2 2 1 -3 1 -2 2 1
int sequence_cnt(int A[]) {
	int a_size = sizeof(A);
	int seq_size = 0;
	int cnt = 0;
	for (int i = 0; i < a_size - 1; i++) {
		if (A[i] > 0 && A[i + 1] < 0 || A[i] < 0 && A[i + 1] > 0) {
			seq_size++;
		}
		else {
			if (seq_size > 1) {
				cnt++;
			}
			seq_size = 0;
		}
	}
	return cnt;
}

int task5() {
	int A[k];
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 101 - 50;
		cout << A[i] << " ";
	}
	cout << "\nCount = " << sequence_cnt(A);
	return 0;
}

int task6() {
	int A[k];
	int sum = 0, sum2 = 0, cnt = 0;
	for (int i = 0; i < k; i++) {
		if (i < k - 1) {
			sum2 += A[i] * A[i + 1];
		}
		A[i] = rand() % 101 - 50;
		cout << A[i] << " ";
		if (A[i] > 0) {
			cnt++;
			sum += A[i];
		}
	}
	cout << "\nMid = " << (double) sum / cnt << "\nSum (a1*a2 + a2*a3 + an-1 * an) = " << sum2;
	return 0;
}

int task7_1() {
	int X[k], Y[k];
	int R = 3;
	cout << "R = 3" << endl;
	for (int i = 0; i < k; i++) {
		X[i] = rand() % 9 - 4;
		Y[i] = rand() % 9 - 4;
		cout << "X = " << X[i] << ", Y = " << Y[i];
		if (pow(X[i], 2) + pow(Y[i], 2) <= pow(R, 2)) {
			cout << ", i = " << i;
		}
		cout << endl;
	}
	return 0;
}

int task7_2() {
	int X[k], Y[k];
	int R = 3;
	cout << "R = 3, Ox = 1, Oy = 1" << endl;
	for (int i = 0; i < k; i++) {
		X[i] = rand() % 9 - 4;
		Y[i] = rand() % 9 - 4;
		cout << "X = " << X[i] << ", Y = " << Y[i];
		if (pow(X[i] - 1, 2) + pow(Y[i] - 1, 2) <= pow(R, 2)) {
			cout << ", i = " << i;
		}
		cout << endl;
	}
	return 0;
}

int task8() {
	int A[k];
	int cnt = 0, cnt2 = 0;
	for (int i = 0; i < k; i++) {
		A[i] = rand() % 101 - 50;
		if (A[i] > 0)
			cnt++;
		if (A[i] < 0)
			cnt2++;
	}
	int* Y = new int[cnt];
	int* Z = new int[cnt2];
	for (int i = 0, j = 0; i < k; i++) {
		if (A[i] > 0) {
			Y[j] = A[i];
			cout << Y[j] << " ";
			j++;
		}
	}
	cout << endl;
	for (int i = 0, j = 0; i < k; i++) {
		if (A[i] < 0) {
			Z[j] = A[i];
			cout << Z[j] << " ";
			j++;
		}
	}
	return 0;
}

int task9() {
	int A[15], B[15];
	int prod = 1;
	cout << fixed;
	for (int i = 0; i < 15; i++) {
		A[i] = rand() % 11 - 5;
		B[i] = rand() % 11 - 5;
	}
	for (int i = 0; i < 15; i++) {
		cout << setw(3) << A[i] << setw(3) << B[i] << endl;
	}
	for (int i = 0, j = 14; i < 15; i++, j--) {
		prod *= A[i] + B[j];
	}
	cout << prod;
	return 0;
}

int main() {
	srand(time(NULL));
	task9();
	return 0;
}