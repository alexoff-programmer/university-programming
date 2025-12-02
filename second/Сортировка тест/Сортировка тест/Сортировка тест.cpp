// Сортировка тест.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#define SIZE 20

void gen_array(int* arr, int size) {
    std::random_device rd; // Источник энтропии
    std::mt19937 gen(rd()); // Генератор Mersenne Twister
    std::uniform_int_distribution<> distrib(1, 100);
    for (int i = 0; i < 20; i++)
        arr[i] = distrib(gen);
}

void print_array(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void print_array(const int* arr, int size, int p, int c) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("| p = %d, c = %d\n", p, c);
}

void copy_array(const int* a, const int size, int* b) {
    for (int i = 0; i < size; i++) {
        b[i] = a[i];
    }
}

void bubble_sort(int* arr, const int size) {
    int buff, p = 0, c = 0;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j > i; j--) {
            c++;
            if (arr[j - 1] > arr[j]) {
                buff = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = buff;
                p++;
            }
        }
    }
    print_array(arr, SIZE, p, c);
}

void bubble_sort_new(int* arr, const int size) {
    int buff, p = 0, c = 0, m = 0, i = 0;
    do {
        i++;
        for (int j = size - 1; j > m - 1; j--) {
            c++;
            if (arr[j - 1] > arr[j]) {
                m = i;
                buff = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = buff;
                p++;
            }
        }
    } while (!(i - m));
    print_array(arr, SIZE, p, c);
}

void shaker_sort(int* a, const int s) {
    int i, j = 0, n1 = 0, n2 = s - 1, p = 0, c = 0, buff;
    do {
        for (i = n1; i < n2; i++, c++) {
            if (a[i] > a[i + 1]) {
                p++;
                j = i;
                buff = a[i];
                a[i] = a[i + 1];
                a[i + 1] = buff;
            }
        }
        n2 = j;
        for (i = n2; i > n1; i--, c++) {
            if (a[i - 1] > a[i]) {
                p++;
                j = i;
                buff = a[i];
                a[i] = a[i - 1];
                a[i - 1] = buff;
            }
        }
        n1 = j;
    } while (n1 < n2);
    print_array(a, SIZE, p, c);
}

void selection_sort(int* a, int s) {
    int i, im, j, c = 0, p = 0, buf;
    for (i = 0; i < s - 1; i++) {
        im = i;
        for (j = i + 1; j < s; j++, c++) {
            if (a[im] > a[j])
                im = j;
        }
        buf = a[i];
        a[i] = a[im];
        a[im] = buf;
        p++;
    }
    print_array(a, SIZE, p, c);
}

void insert_sort(int* a, int s) {
    int i, j, c = 0, p = 0, buf;
    for (i = 1; i < s; i++, c++) {
        if (a[i - 1] > a[i]) {
            buf = a[i];
            for (j = i - 1; j >= 0 && a[j] > buf; j--, c+=2) {
                a[j + 1] = a[j]; p++;
            }
            a[j + 1] = buf; p++;
        }
    }
    print_array(a, SIZE, p, c);
}

void shella_sort(int* a, int s) {
    int i, j, step = s / 2, c = 0, p = 0, buf;
    while (step) {
        for (i = step; i + step < s; i++, c++) {
            if (a[i - step] > a[i]) {
                buf = a[i];
                for (j = i - step; j >= 0 && a[j] > buf; j -= step, c += 2) {
                    a[j + step] = a[j];
                    p++;
                }
                a[j + step] = buf;
                p++;
            }
        }
        step /= 2;
    }
    print_array(a, SIZE, p, c);
}

int main()
{
    int gen_arr[SIZE] {};
    gen_array(gen_arr, SIZE);
    print_array(gen_arr, SIZE);
    int arr[SIZE];

    std::cout << "Bubble Sort: ";
    copy_array(gen_arr, SIZE, arr);
    bubble_sort(arr, SIZE);

    std::cout << "Bubble Sort New: ";
    copy_array(gen_arr, SIZE, arr);
    bubble_sort_new(arr, SIZE);

    std::cout << "Shaker Sort: ";
    copy_array(gen_arr, SIZE, arr);
    shaker_sort(arr, SIZE);

    std::cout << "Selection Sort: ";
    copy_array(gen_arr, SIZE, arr);
    selection_sort(arr, SIZE);

    std::cout << "Insert Sort: ";
    copy_array(gen_arr, SIZE, arr);
    insert_sort(arr, SIZE);

    std::cout << "Shell Sort: ";
    copy_array(gen_arr, SIZE, arr);
    shella_sort(arr, SIZE);
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
