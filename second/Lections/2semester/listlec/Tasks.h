#ifndef TASKS_H
#define TASKS_H

#include "List.h"
#include <random>

pList genList(mt19937 gen, uniform_int_distribution<T> dist);
int task1(pList pL);
int task2(pList pL, T date1, T date2);
int task3(pList pL);

#endif
