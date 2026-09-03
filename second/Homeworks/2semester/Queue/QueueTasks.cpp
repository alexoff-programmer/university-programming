#include "QueueTasks.h"
using namespace std;

/*
1. Без использования дополнительных структур, кроме очереди, напечатать числа, вводимые с
клавиатуры в следующем порядке: сначала - все числа, меньшие а, затем - все числа из отрезка
[a,b], и наконец - все остальные числа, сохраняя
трех групп чисел (а и b - заданные числа а<b).
*/

pQueue genRandom(mt19937 gen, uniform_int_distribution<int> dist) {
	pQueue pQ = createQueue();
	for (int i = 0; i < 10; i++) {
		put(pQ, dist(gen));
	}
	return pQ;
}

int task1(int a, int b)
{
	pQueue pQ = createQueue();
	pQueue pSQ = createQueue();
	int t;
	for (int i = 0; i < 5; i++) {
		cin >> t;
		put(pQ, t);
	}
	while (!isEmpty(pQ)) {
		t = take(pQ);
		if (t < a) cout << t << " ";
		else put(pSQ, t);
	}
	while (!isEmpty(pSQ)) {
		t = take(pSQ);
		if (t >= a && t <= b) cout << t << " ";
		else put(pQ, t);
	}
	while (!isEmpty(pQ)) {
		int t = take(pQ);
		cout << t << " ";
	}
	return 0;
}

/*
2 .Создать очередь из случайных целых чисел и преобразовать его в две очереди, переместив
элементы из первой очереди во вторую N элементов. Если исходная очередь содержит менее N
элементов, то перенести все элементы из исходной очереди в результирующую. Вывести на экран
значения вершин обеих очередей. Вывести на экран null, если первая очередь стала пустой.
*/

int task2(int N, pQueue pQ)
{
	pQueue pSQ = createQueue();
	int t;
	while (!isEmpty(pQ) && N > 0) {
		put(pSQ, take(pQ));
		N--;
	}
	cout << "Первая очередь:" << endl;
	showQueue(pQ);
	cout << "Вторая очередь:" << endl;
	showQueue(pSQ);
	cout << "Значения вершин: 1) " << pQ->top->value << ", 2) " << pSQ->top->value;
	return 0;
}

/*
3. Создать 2 входные очереди с одинаковым количеством элементов. 
Создать результирующую очередь, в которой элементы из первой и второй очередей чередуются. 
Вывести на экран первый и последний элементы полученной очереди.
*/

int task3(pQueue pQ, pQueue pSQ)
{
	pQueue pRQ = createQueue();
	showQueue(pQ);
	showQueue(pSQ);
	while (!isEmpty(pQ) && !isEmpty(pSQ)) {
		put(pRQ, take(pQ));
		put(pRQ, take(pSQ));
	}
	showQueue(pRQ);
	return 0;
}

/*
4. Создать очередь из случайных целых чисел и преобразовать ее в две очереди, 
перемещая элементы из первой в конец второй, пока значение начального элемента первой очереди не станет четным. 
Если исходная очередь не содержит четных элементов, то перенести все элементы из первой очереди во вторую. 
Вывести на экран null, если первая очередь стала пустой.
*/

int task4(int N, pQueue pQ)
{
	pQueue pSQ = createQueue();
	int t;
	while (!isEmpty(pQ) && N > 0) {
		put(pSQ, take(pQ));
		N--;
	}
	cout << "Первая очередь:" << endl;
	showQueue(pQ);
	cout << "Вторая очередь:" << endl;
	showQueue(pSQ);
	cout << "Значения вершин: 1) " << pQ->top->value << ", 2) " << pSQ->top->value;
	return 0;
}

/*
Выполнить циклический сдвиг элементов в очереди так, чтобы в ее начале был расположен
наибольший элемент.
*/

int task5(pQueue pQ)
{
	pQueue pSQ = createQueue();
	int max = take(pQ);
	put(pQ, max);
	int temp = max;
	while (!isEmpty(pQ)) {
		temp = take(pQ);
		max = (temp > max || !max) ? temp : max;
		put(pSQ, temp);
	}

	while (!isEmpty(pSQ)) {
		temp = take(pSQ);
		if (temp == max)
			break;
		put(pSQ, temp);
	}

	put(pQ, temp);
	while (!isEmpty(pSQ)) {
		put(pQ, take(pSQ));
	}
	cout << "After Cycle:" << endl;
	showQueue(pQ);
	return 0;
}