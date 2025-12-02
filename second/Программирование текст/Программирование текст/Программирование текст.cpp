// Программирование текст.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

void get_and_print(string& str1, string& str2) {
    cout << "Введите первую строку: ";
    getline(cin, str1);
    cout << "Введите вторую строку: ";
    getline(cin, str2);
    cout << "Первая строка: " << str1 << "\n"
        << "Вторая строка: " << str2 << endl;
}

int same_count(string str1, string str2) {
    int i = 0;
    while (i < str1.size() && i < str2.size() && str1[i] == str2[i])
        i++;
    return i;
}

string mix_str(string str1, string str2) {
    int i = 0;
    string res = "";
    while (i < str1.size() || i < str2.size()) {
        if (i < str1.size())
            res += str1[i];
        if (i < str2.size())
            res += str2[i];
        i++;
    }
    return res;
}

int numbers(string d) {
    int count = 0;
    bool f = false;
    for (char c : d) {
        if (f)
            count++;
        if (c == '.')
            f = true;
    }
    return count;
}
string back(string d, int size) {
    if (size == 1)
        return string(1, d[0]);
    return d[size - 1] + back(d, size - 1);

}

int task3() {
    string d;
    cin >> d;
    int count = numbers(d);
    cout << "Дробная часть содержит " << count << " чисел." << endl;
    cout << "В обратном порядке: " << back(d, d.size());
    
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str2, str1;
    get_and_print(str1, str2);
    int same = same_count(str1, str2);
    cout << "Количество совпадений с начала: " << same << endl;
    cout << "В первой строке после совпадения осталось " << str1.size() - same << " символов, во второй — " << str2.size() - same << endl;
    cout << "Объединённый остаток: " << str1.substr(same) + str2.substr(same) << endl;
    cout << "Микс: " << mix_str(str1, str2) << endl;
    return task3();
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
