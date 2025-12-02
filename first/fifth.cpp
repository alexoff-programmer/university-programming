#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

#define N 5
#define M 4

float genFloatNum() {
	return (float)(rand() % 1001) / 10 - 50;
}

int task1() {
	const int m = 5, n = 6;
	float matrix[m][n];
	float max = NULL;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			max = (max) ? matrix[i][j] : (matrix[i][j] > max ? matrix[i][j] : max);
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] /= max;
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}

int task2() {
	float matrix[N][M];
	float vec[N] = {};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			matrix[i][j] = genFloatNum();
			if (matrix[i][j] > 0)
				vec[i] += matrix[i][j];
			cout << setw(6) << matrix[i][j];
		}
		cout << " | " << vec[i] << endl;
	}
	return 0;
}

int task3() {
	const int m = 8, n = 6;
	int cnt = 0;
	bool has_zero = false;
	float matrix[m][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[j][i] = genFloatNum();
			if (matrix[j][i] == 0)
				has_zero = true;
		}
		if (has_zero) {
			cnt++;
			has_zero = false;
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Count: " << cnt;
	return 0;
}

int task4() {
	const int m = 5, n = 7;
	int cnt_p = 0, cnt_n = 0;
	float matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			cout << setw(6) << matrix[i][j];
			if (matrix[i][j] > 0)
				cnt_p++;
			else if (matrix[i][j] != 0)
				cnt_n++;
		}
		cout << endl;
	}
	if (cnt_p > cnt_n)
		cout << "Положительных чисел больше.";
	else if (cnt_p < cnt_n)
		cout << "Отрицательных чисел больше.";
	else
		cout << "Равное кол-во положительных и отрицательных чисел.";
	return 0;
}

int task5() {
	const int m = 8, n = 8;
	float prod = 1, max = NULL;
	int col;
	float matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			if (!max)
				max = matrix[i][j];
			cout << setw(6) << matrix[i][j];
			if (i == j && max < matrix[i][j]) {
				col = j;
			}
		}
		cout << endl;
	}
	for (int i = 0; i < m; i++) {
		prod *= matrix[i][col];
	}
	cout << "Произведение: " << prod;
	return 0;
}

int task6() {
	const int m = 6;
	float sum_main = 0, sum_sub = 0;
	float matrix[m][m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = genFloatNum();
			if (i == j) {
				sum_main += matrix[i][j];
			}
			else if (i + j == m - 1) {
				sum_sub += matrix[i][j];
			}
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Сумма чисел главной диагонали = " << sum_main << endl;
	cout << "Сумма чисел побочной диагонали = " << sum_sub << endl;
	if (sum_main > sum_sub) {
		cout << "Сумма чисел главной диагонали больше.";
	}
	else if (sum_main == sum_sub) {
		cout << "Суммы чисел диагоналей равны.";
	}
	else {
		cout << "Сумма чисел побочной диагонали больше.";
	}
	return 0;
}

int task7() {
	const int m = 5, n = 10;
	int cnt5 = 0, cnt6 = 0;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			cout << setw(6) << matrix[i][j];
			if (j == 4 && matrix[i][j] % 2 == 0) {
				cnt5++;
			}
			else if (j == 5 && matrix[i][j] % 2 == 0) {
				cnt6++;
			}
		}
		cout << endl;
	}
	cout << "5 ст.: " << cnt5 << ", 6 ст.: " << cnt6;
	return 0;
}

int task8() {
	const int m = 6, n = 6;
	int cnt = 0;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			cout << setw(6) << matrix[i][j];
			if (matrix[i][j] % 2 == 0 && matrix[i][j] > -15 && matrix[i][j] < 15) {
				cnt++;
			}
		}
		cout << endl;
	}
	cout << "Кол-во: " << cnt;
	return 0;
}

int task9() {
	const int m = 6, n = 6;
	int matrix[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = genFloatNum();
			cout << setw(6) << matrix[i][j];
		}
		cout << endl;
	}
	cout << "Номера всех нечётных элементов:" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] % 2 != 0)
				cout << "[" << i + 1 << "], [" << j + 1 << "] = " << matrix[i][j] << endl;
		}
	}
	return 0;
}

int task10_1() {
	const int floor_cnt = 3;
	const int pos_cnt = 10;
	int positions[3][10];
	for (int i = 0; i < floor_cnt; i++) {
		cout << i + 1;
		if (i + 1 > 10 && i < 20)
			cout << "-ый";
		else switch ((i + 1) % 10)
		{
		case 2: case 6: case 7: case 8:
			cout << "-ой ";
			break;
		case 3:
			cout << "-ий ";
			break;
		default:
			cout << "-ый ";
			break;
		}
		cout << "этаж: |";
		for (int j = 0; j < pos_cnt; j++) {
			positions[i][j] = j + 1;
			cout << positions[i][j] << "|";
		}
		cout << endl;
	}
	return 0;
}

void printPositions(int positions[], const int floor_cnt, const int pos_cnt) {
	for (int i = 0; i < floor_cnt; i++) {
		cout << i + 1;
		if (i + 1 > 10 && i < 20)
			cout << "-ый";
		else switch ((i + 1) % 10)
		{
		case 2: case 6: case 7: case 8:
			cout << "-ой ";
			break;
		case 3:
			cout << "-ий ";
			break;
		default:
			cout << "-ый ";
			break;
		}
		cout << "этаж: |";
		for (int j = 0; j < pos_cnt; j++) {
			cout << positions[i * pos_cnt + j] << "|";
		}
		cout << endl;
	}
}

int task10_2() {
	const int floor_cnt = 3;
	const int pos_cnt = 10;
	int positions[3][10];
	for (int i = 0; i < floor_cnt; i++) {
		for (int j = 0; j < pos_cnt; j++) {
			positions[i][j] = j + 1;
		}
	}
	printPositions(reinterpret_cast<int*>(positions), floor_cnt, pos_cnt);
	while (true) {
		int floor = 0, pos = 0;
		cout << "Введите номер этажа, а затем номер ряда: ";
		cin >> floor >> pos;
		if (floor <= 0 || pos <= 0 || floor > floor_cnt || pos > pos_cnt) {
			cout << "\nВыход из системы бронирования.";
			break;
		}
		else {
			if (positions[floor - 1][pos - 1] == 0) {
				cout << "Ошибка: место уже занято." << endl;
				continue;
			}
			positions[floor - 1][pos - 1] = 0;
			printPositions(reinterpret_cast<int*>(positions), floor_cnt, pos_cnt);
			cout << "Вы забронировали место " << floor << " этаж " << pos << " ряд" << endl;
		}
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << fixed << setprecision(1);
	srand(time(NULL));
	return task9();
}