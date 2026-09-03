#include "Tasks.h"

using namespace std;

/*
1. Описать функцию, которая по списку L строит два новых списка: E1 -
из положительных элементов и Е2 - из остальных элементов списка L (тип
элемента - float)
2. Описать функцию, которая вставляет в список L новый элемент Е1 за
каждым вхождением элемента Е;
3 Описать функцию, которая переворачивает список L, т. е. изменяет
ссылки в этом списке так, чтобы его элементы оказались расположенными
в обратном порядке;
*/

pList genList(mt19937 gen, uniform_int_distribution<T> dist) {
	pList pL = createList();
	T val;
	for (int i = 0; i < 20; i++) {
		val = dist(gen);
		addNodeAfter(pL, getPointer(pL, val), val);
	}
	return pL;
}

int task1(pList pL) {
	pList pE1 = createList();
	pList pE2 = createList();
	pNode pN = pL->top;
	while (pN) {
		if (pN->value > 0) addNodeAfter(pE1, getPointer(pE1, pN->value), pN->value);
		else addNodeAfter(pE2, getPointer(pE2, pN->value), pN->value);
		pN = pN->next;
	}
	cout << "List 1:" << endl;
	showList(pE1);
	cout << "List 2:" << endl;
	showList(pE2);
	return 0;
}

int task2(pList pL, T date1, T date2) {
	cout << "Source:" << endl;
	showList(pL);
	if (!pL) return 0;
	pNode pN = pL->top;
	while (pN) {
		if (pN->value == date1) {
			addNodeAfter(pL, pN, date2, true);
			pN = pN->next;
		}
		pN = pN->next;
	}
	cout << "Changed:" << endl;
	showList(pL);
}

int task3(pList pL) {
	cout << "Source:" << endl;
	showList(pL);
	pNode prev = NULL;
	pNode p = pL->top;
	pNode next = NULL;
	
	while (p) {
		next = p->next;
		p->next = prev;
		prev = p;
		p = next;
	}

	pL->top = prev;
	cout << "Changed:" << endl;
	showList(pL);
	return 0;
}