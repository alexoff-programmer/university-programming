#ifndef QUEUE_TASKS_H
#define QUEUE_TASKS_H
#endif // !QUEUE_TASKS_H

#include "Queue.h"
#include <random>
pQueue genRandom(mt19937 gen, uniform_int_distribution<int> dist);
int task1(int a, int b);
int task2(int N, pQueue pQ);
int task3(pQueue pQ, pQueue pSQ);
int task4(int N, pQueue pQ);
int task5(pQueue pQ);