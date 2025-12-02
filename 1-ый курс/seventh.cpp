#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#define ARRAY_LENGTH 3
#define X_LENGTH 10
#define Y_LENGTH 20

int* getArr(int* arr, int len) {
	cout << "Введите значения элементов массива:" << endl;
	for (int i = 0; i < len; i++) {
		cout << "a[" << i << "] = ";
		cin >> *(arr + i);
	}
	cout << "Элементы массива получили значение." << endl;
	return arr;
}

void printArr(int* arr, int len) {
	cout << "Выводим значения элементов массива..." << endl;
	for (int i = 0; i < len; i++) {
		cout << "a[" << i << "] = " << *(arr + i) << "\t";
	}
	return;
}

bool isSorted(int* arr, int len) {
	bool is_sorted = true;
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] >= arr[i + 1]) {
			is_sorted = false;
			break;
		}
	}
	return is_sorted;
}

bool indexOf(int x, int* arr, int len) {
	int index = -1;
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] == x) {
			index = i;
			break;
		}
	}
	return index;
}

double funcX(int* arr, int len) {
	double sum = 0, prod = 1;
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] > 0) {
			prod *= arr[i];
			sum += prod;
		}
		else {
			break;
		}
	}
	return sum;
}

int max(int* arr, int len) {
	int max = *arr + *(arr + len - 1), temp;
	for (int i = 1; i < len / 2; i++) {
		temp = *(arr + i) + *(arr + len - i - 1);
		if (max < temp)
			max = temp;
	}
	return max;
}

int min(int* arr, int len) {
	int min = *arr * *(arr + 1), temp;
	for (int i = 1; i < len - 1; i++) {
		temp = arr[i] * arr[i + 1];
		if (min > temp)
			min = temp;
	}
	return min;
}

int funcD(int* arr, int len) {
	double sum = 0;
	int cnt_u = 0, cnt_z = 0;
	for (int i = 1; i < len; i++) {
		if (arr[i] < 0)
			cnt_u++;
		else
			cnt_z++;
	}
	int size = cnt_u < cnt_z ? cnt_u : cnt_z;
	int* u_arr = new int[cnt_u];
	int* z_arr = new int[cnt_z];
	for (int i = 0; i < len; i++) {
		if (arr[i] < 0)
			u_arr[i] = arr[i];
		else
			z_arr[len - i - 1] = arr[i];
	}
	for (int i = 0; i < size; i++) {
		sum += u_arr[i] * z_arr[i];
	}
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int array[ARRAY_LENGTH];
	int x[X_LENGTH];
	int y[Y_LENGTH];
	getArr(x, X_LENGTH);
	cout << min(x, X_LENGTH);
	return 0;
}