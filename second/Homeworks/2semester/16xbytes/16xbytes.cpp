//  Вывести в 16 - ричной системе счисления значение байтов переменной ul(unsigned long) ul = 0xAE13C7DD
//  Вывод на экран :
//  1. Номер байта
//  2. Значение

#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru_ru");
    unsigned long ul = 0xAE13C7DD;
    unsigned char* pul = (unsigned char*) &ul;
    for (int i = 0; i < 4; i++) {
        printf("%d-й байт: %02X\n", i, *(pul+i));
    }
}
