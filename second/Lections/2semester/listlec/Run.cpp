#include <iostream>
#include "Tasks.h"
using namespace std;

int main() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<T> dist(-10, 10);
	task1(genList(gen, dist));
}