#include <iostream>
#include <cstdlib> // Для srand и rand (для потенциальной оптимизации pivot)

// Максимальный размер, используемый в SelectionSort (для соответствия старому коду)
const int max = 10;

// Вспомогательная функция для копирования массива
void CopyArray(int* source, int* destination, int k) {
    for (int i = 0; i < k; ++i) {
        destination[i] = source[i];
    }
}

// Вспомогательная функция для вывода массива
void PrintArray(const char* name, int* x, int k)
{
    std::cout << name << " after sorting: ";
    for (int i = 0; i < k; i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << "\n";
}

void EnterArray(int size, int* a) {
}
void CopyArray(int size, int* a, int* b) {
}

// 1. Пузырьковая сортировка (Bubble Sort)
void BubbleSort(int k, int* x)
{
    long long comparisons = 0;
    long long swaps = 0;
    int buf;

    for (int i = 0; i < k - 1; i++)
    {
        for (int j = k - 1; j > i; j--)
        {
            comparisons++;
            if (x[j - 1] > x[j])
            {
                // Обмен (Swap)
                buf = x[j];
                x[j] = x[j - 1];
                x[j - 1] = buf;
                swaps++;
            }
        }
    }

    std::cout << "BubbleSort: comparisons=" << comparisons;
    std::cout << ", swaps=" << swaps << "\n";
}

void BubbleSortNew(int k, int* x)
{
    int j, i = 0, m = 0, c = 0, p = 0, buf;
    do {
        m = i;
        for (int j = k - 1; j > m; j--)
        {
            c++;
            if (x[j - 1] > x[j])
            {
                i = j;
                buf = x[j];
                x[j] = x[j - 1];
                x[j - 1] = buf;
                p++;
            }
        }
    } while (i - m);

    std::cout << "BubbleSort: comparisons=" << c;
    std::cout << ", swaps=" << p << "\n";
}

// 2. Шейкерная сортировка (Shaker Sort)
void ShakerSort(int k, int* x)
{
    long long comparisons = 0;
    long long swaps = 0;
    int t;
    int n1 = 0;
    int n2 = k - 1;
    int j = 0;

    do
    {
        // Проход справа налево
        for (int i = n2; i > n1; i--)
        {
            comparisons++;
            if (x[i - 1] > x[i])
            {
                t = x[i - 1]; x[i - 1] = x[i]; x[i] = t;
                j = i; swaps++;
            }
        }
        n1 = j;

        // Проход слева направо
        for (int i = n1; i < n2; i++)
        {
            comparisons++;
            if (x[i] > x[i + 1])
            {
                t = x[i]; x[i] = x[i + 1]; x[i + 1] = t;
                j = i; swaps++;
            }
        }
        n2 = j;
    } while (n1 < n2);

    std::cout << "ShakerSort: comparisons=" << comparisons;
    std::cout << ", swaps=" << swaps << "\n";
}

// 3. Сортировка простым выбором (Selection Sort)
void SelectionSort(int k, int* x)
{
    long long comparisons = 0;
    long long swaps = 0;
    int min_idx, temp;

    for (int i = 0; i < k - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < k; j++)
        {
            comparisons++;
            if (x[j] < x[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            temp = x[i]; x[i] = x[min_idx]; x[min_idx] = temp;
            swaps++;
        }
    }

    std::cout << "SelectionSort: comparisons=" << comparisons;
    std::cout << ", swaps=" << swaps << "\n";
}

// 4. Сортировка простым включением (Insertion Sort)
void InsertSort(int k, int* x)
{
    long long comparisons = 0;
    long long shifts = 0;
    int i, j, temp;

    for (i = 1; i < k; i++)
    {
        temp = x[i]; shifts++;
        for (j = i - 1; j >= 0; j--)
        {
            comparisons++;
            if (x[j] > temp)
            {
                x[j + 1] = x[j]; shifts++;
            }
            else
            {
                break;
            }
        }
        x[j + 1] = temp; shifts++;
    }

    std::cout << "InsertSort: comparisons=" << comparisons;
    std::cout << ", shifts (copy/move)=" << shifts << "\n";
}

// --- 5. Быстрая сортировка (Quick Sort) ---

// Вспомогательная функция для обмена двух элементов (используется только для QuickSort)
void Swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Функция разделения (Partition)
int Partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Опорный элемент - последний
    int i = (low - 1);     // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Основная функция Quick Sort
void QuickSortRecursive(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSortRecursive(arr, low, pi - 1);  // Левая часть
        QuickSortRecursive(arr, pi + 1, high); // Правая часть
    }
}

// Функция-обертка для удобства вызова, чтобы соответствовать сигнатуре других сортировок
void QuickSort(int k, int* x) {
    QuickSortRecursive(x, 0, k - 1);
    // Примечание: QuickSort обычно не подсчитывает операции внутри себя, 
    // так как это усложняет рекурсивную структуру.
    std::cout << "QuickSort: (O(N log N) average)\n";
}

int main()
{

    // Исходный тестовый массив
    const int N = 10;
    int original_array[N] = { 2, 6, 7, 0, 9, 1, 5, 3 };
    int temp_array[N];

    std::cout << "Исходный массив: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << original_array[i] << " ";
    }
    std::cout << "\n\n";

    // 1. Пузырьковая сортировка
    CopyArray(original_array, temp_array, N);
    BubbleSort(N, temp_array);
    PrintArray("BubbleSort", temp_array, N);
    std::cout << "---------------------------\n";

    // 1.1 Пузырьковая сортировка
    CopyArray(original_array, temp_array, N);
    BubbleSortNew(N, temp_array);
    PrintArray("BubbleSortNew", temp_array, N);
    std::cout << "---------------------------\n";

    // 2. Шейкерная сортировка
    CopyArray(original_array, temp_array, N);
    ShakerSort(N, temp_array);
    PrintArray("ShakerSort", temp_array, N);
    std::cout << "---------------------------\n";

    // 3. Сортировка простым выбором
    CopyArray(original_array, temp_array, N);
    SelectionSort(N, temp_array);
    PrintArray("SelectionSort", temp_array, N);
    std::cout << "---------------------------\n";

    // 4. Сортировка простым включением
    CopyArray(original_array, temp_array, N);
    InsertSort(N, temp_array);
    PrintArray("InsertSort", temp_array, N);
    std::cout << "---------------------------\n";

    // 5. Быстрая сортировка (Quick Sort)
    CopyArray(original_array, temp_array, N);
    QuickSort(N, temp_array);
    PrintArray("QuickSort", temp_array, N);
    std::cout << "---------------------------\n";


    return 0;
}