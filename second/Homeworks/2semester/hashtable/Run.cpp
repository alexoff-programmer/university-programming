#include "Tasks.h"
#include <malloc.h>
#include <fstream>
#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

// --- Основная функция ---
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    task2();
    return 0;
}