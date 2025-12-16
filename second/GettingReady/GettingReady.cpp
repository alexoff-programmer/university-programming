#include <iostream>
#define N 8
using namespace std;

void bubbleSort(int* a, int s) {
    int i, j, p = 0, c = 0, buf;
    for (i = 0; i < s; i++) {
        for (j = s - 1; j > i; j--, c++) {
            if (a[j] < a[j - 1]) {
                p++;
                buf = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buf;
            }
        }
    }
    cout << "\nBubble:   \tp(" << p << "), c(" << c << ")" << endl;
}

void bubbleSortNew(int* a, int s) {
    int i = 0, j, m = 0, p = 0, c = 0, buf;
    do {
        i = m;
        for (j = s - 1; j > i; j--, c++) {
            if (a[j] < a[j - 1]) {
                p++;
                m = j;
                buf = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buf;
            }
        }
    } while (m - i);
    cout << "\nBubbleNew:\tp(" << p << "), c(" << c << ")" << endl;
}

void shakerSort(int* a, int s) {
    int i, j, l = 0, r = s - 1, p = 0, c = 0, buf;
    do {
        for (i = l; i < r; i++, c++) {
            if (a[i] > a[i + 1]) {
                j = i;
                p++;
                buf = a[i];
                a[i] = a[i + 1];
                a[i + 1] = buf;
            }
        }
        r = j;
        for (i = r; i > l; i--, c++) {
            if (a[i] < a[i - 1]) {
                j = i;
                p++;
                buf = a[i];
                a[i] = a[i - 1];
                a[i - 1] = buf;
            }
        }
        l = j;
    } while (l - r);
    cout << "\nShaker:   \tp(" << p << "), c(" << c << ")" << endl;
}

void insertSort(int* a, int s) {
    int i, j, buf, c = 0, p = 0;
    for (i = 1; i < s; i++, c++) {
        if (a[i] < a[i - 1]) {
            buf = a[i];
            for (j = i - 1; j >= 0 && a[j] > buf; j--, c++, p++) {
                a[j + 1] = a[j];
            }
            a[j + 1] = buf;
            p++;
        }
    }
    cout << "\nInsert:   \tp(" << p << "), c(" << c << ")" << endl;
}

void selectionSort(int* a, int s) {
    int i, j, min, c = 0, p = 0, buf;
    for (i = 0; i < s; i++) {
        min = i;
        for (j = i + 1; j < s; j++, c++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        buf = a[i];
        a[i] = a[min];
        a[min] = buf;
        p++;
    }
    cout << "\nSelection:   \tp(" << p << "), c(" << c << ")" << endl;
}

void copyArray(int* a, int* b, int s) {
    for (int i = 0; i < s; i++) {
        b[i] = a[i];
    }
}

void printArray(int* a, int s) {
    for (int i = 0; i < s; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int arr[N]{ 2, 1, 3, 7, 5, 4, 8, 0 };
    printArray(arr, N);
    int tempArr[N]{};

    //bubbleSort
    copyArray(arr, tempArr, N);
    bubbleSort(tempArr, N);
    printArray(tempArr, N);

    //bubbleSortNew
    copyArray(arr, tempArr, N);
    bubbleSortNew(tempArr, N);
    printArray(tempArr, N);

    //shakerSort
    copyArray(arr, tempArr, N);
    shakerSort(tempArr, N);
    printArray(tempArr, N);

    //insertSort
    copyArray(arr, tempArr, N);
    insertSort(tempArr, N);
    printArray(tempArr, N);

    //selectionSort
    copyArray(arr, tempArr, N);
    selectionSort(tempArr, N);
    printArray(tempArr, N);
}

