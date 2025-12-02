#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int task1() {
	float x = -8.92;
	int y = 5;
	cout << "sizeof x=" << sizeof x << endl;
	cout << "sizeof y=" << sizeof y << endl;
	cout << "sizeof x+y=" << sizeof x + y << endl;
	cout << "sizeof (x+y)=" << sizeof(x + y) << endl;
	cout << "sizeof x*2+1=" << sizeof x * 2 + 1 << endl;
	cout << "sizeof 2*y+1=" << sizeof 2 * y + 1 << endl;
	cout << "sizeof ++y*2=" << sizeof ++y * 2 << endl;
	cout << "sizeof y--*2=" << sizeof y-- * 2 << endl;
	return 0;
}

int task1_2() {
	cout << "char = " << sizeof(char) << ", char* = " << sizeof(char*) << endl;
	cout << "int = " << sizeof(int) << ", char* = " << sizeof(int*) << endl;
	cout << "long = " << sizeof(long) << ", char* = " << sizeof(long*) << endl;
	cout << "float = " << sizeof(float) << ", float* = " << sizeof(float*) << endl;
	cout << "double = " << sizeof(double) << ", double* = " << sizeof(double*) << endl;
	cout << "long double = " << sizeof(long double) << ", long double* = " << sizeof(long double*) << endl;
	return 0;
}

int task2()
{
	int x = 42;
	int* xPtr = &x;
	cout << *xPtr;
	return 0;
}

int task3() {
	char c = 'c';
	int i = 1;
	double d = 1.0;
	cout << "char: " << (void*)(&c) << " " << (void*)(&c - 1) << " " << (void*)(&c + 2) << endl;
	cout << "int: " << &i << " " << &i - 1 << " " << &i + 2 << endl;
	cout << "double: " << &d << " " << &d - 1 << " " << &d + 2 << endl;
	return 0;
}

#define N 5

int task4() {
	int arr[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 101 - 50;
		cout << *(arr + i) << " ";
	}
	return 0;
}

int task5() {
	double arrDbl[] = { 1, 2, 3, 4, 5 };
	int arrSize = sizeof arrDbl / sizeof(double);
	cout << "Count of elements: " << arrSize << endl;
	for (int i = 0; i < arrSize; i++) {
		cout << "arrDbl[" << i << "] = " << arrDbl[i] << endl;
	}
	return 0;
}

int task6() {
	int arr[] = { 1, 20, 3, 45, 5 };
	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << "&arr[" << i << "] = " << &arr[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		*(arr + i) = i + 1;
		cout << "arr[" << i << "] = " << *(arr + i) << endl;
	}
	// arr = &arr[2]; // Не получается сместить начало массива, так как ссылка на первый элемент массива - константа
	cout << endl;
	int* pArr = &arr[2];
	for (int i = 0; i < 5; i++) {
		cout << "arr[" << i << "] = " << *(pArr - 2 + i) << endl;
	}
	return 0;
}

int task7() {
	int* arr = new int[10];
	for (int i = 0; i < 10; i++) {
		*(arr + i) = rand() % 101 - 50;
		cout << "arr[" << i << "] = " << *(arr + i) << endl;
	}
	delete[] arr;
	return 0;
}

int task8() {
	int* arr = new int[N];
	int max = NULL;
	for (int i = 0; i < N; i++) {
		cin >> *(arr + i);
		if (max < *(arr + i) || !max)
			max = *(arr + i);
	}
	for (int i = 0; i < N; i++) {
		cout << "arr[" << i << "] = " << *(arr + i) << " ";
	}
	cout << "\nMax = " << max;
	return 0;
}

#define M 10

int task9() {
	int arr[M];
	int arr2[N];
	int* arr3 = new int[M + N];
	cout << setw(6) << "Arr" << setw(6) << "Arr2" << setw(6) << "Arr3" << endl;
	for (int i = 0; i < M + N; i++) {
		if (i < M)
		{
			arr[i] = rand() % 101 - 50;
			*(arr3 + i) = arr[i];
			cout << setw(6) << arr[i];
		}
		else {
			cout << setw(6) << "";
			*(arr3 + i) = arr2[i - M];
		}
		if (i < N)
		{
			arr2[i] = rand() % 101 - 50;
			cout << setw(6) << arr2[i];
		}
		else
			cout << setw(6) << "";
		cout << setw(6) << *(arr3 + i);
		cout << endl;
	}
	return 0;
}

int task10() {
	int* arr = new int[N];
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 100;
		if (arr[i] % 2 == 1) {
			cnt++;
		}
		cout << arr[i] << " ";
	}
	int* arr2 = new int[cnt];
	cout << endl;
	for (int i = 0, j = 0; i < N; i++) {
		if (arr[i] % 2 == 1) {
			arr2[j] = arr[i];
			cout << arr2[j] << " ";
			j++;
		}
	}
	return 0;
}

int main() {
	srand(time(NULL));
	return task1();
}