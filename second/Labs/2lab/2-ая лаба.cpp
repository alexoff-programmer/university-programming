// 2-ая лаба.cpp

#include <iostream>
#include <cstdio>
using namespace std;

//  Кастинг - преобразование одного типа в другой тип.Так как указатель это переменная, его можно кастовать до другого типа.
//  (тип_указателя*) указатель

int casting1() {
    int k = 6;
    int* pK = &k;
    double d = 3.14;
    double* pD = &d;
    cout << "&k: " << pK << ", k = " << *pK << endl;
    cout << "&d: " << pD << ", d = " << *pD << endl;
    /*pD = (double*)pK;
    cout << "&d: " << pD << ", d = " << *pD << " (=pK)" << endl;*/
    pK = (int*)pD;
    cout << "&k: " << pK << ", k = " << *pK << " (=pD)" << endl;
    return 0;
}

//  Кастинг удобен, если необходимо взять часть переменной

int casting2() {
    int A = 371; // 101001011
    int* pA = &A;
    printf("%d\n", *pA);
    char* pC = (char*)pA;
    for (int i = 0; i < sizeof(A); i++)
        printf("%d\t", *(pC + i));
    return 0;
}

int main()
{
    return casting2();
}
