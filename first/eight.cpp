#include <iostream>
#include <conio.h>
using namespace std;

#define N 3

void setmatrix(int matrix[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}
}

void printmatrix(int matrix[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j];
		}
	}
}

void sumofmatrix(int matrix1[][N], int matrix2[][N], int sum[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
}

void difofmatrix(int matrix1[][N], int matrix2[][N], int dif[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dif[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}

void prodofmatrix(int matrix1[][N], int matrix2[][N], int prod[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			prod[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
}

void multiplymatrix(int matrix1[][N], int multiplier, int mult[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mult[i][j] = matrix1[i][j] * multiplier;
		}
	}
}

void first(int matrix[][N]) {
	int res[N][N] = {0};
	multiplymatrix(matrix, 3, res);
	printmatrix(res);
}

void second(int matrix[][N], int matrix2[][N]) {
	int res1[N][N] = { 0 }, res2[N][N] = { 0 }, res3[N][N] = { 0 };
	multiplymatrix(matrix, 2, res1);
	multiplymatrix(matrix, 3, res2);
	difofmatrix(res1, res2, res3);
	printmatrix(res3);
}

void third(int matrix[][N], int matrix2[][N]) {
	int res[N][N];
	prodofmatrix(matrix, matrix2, res);
	printmatrix(res);
}

void fourth(int matrix[][N], int matrix2[][N]) {
	int res1[N][N], res2[N][N], res3[N][N];
	multiplymatrix(matrix, 4, res1);
	prodofmatrix(matrix, matrix2, res2);
	sumofmatrix(res1, res2, res3);
	printmatrix(res3);
}

int main() {
	int A[N][N];
	int B[N][N];
	setmatrix(A);
	setmatrix(B);
	first(A);
	second(A, B);
	third(A, B);
	fourth(A, B);
}