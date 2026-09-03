#include "QueueTasks.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "ru_ru");
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(-50, 50);

    //task1(5, 10);
	pQueue pRQ = genRandom(gen, dist);
	showQueue(pRQ);
	task5(pRQ);
}
