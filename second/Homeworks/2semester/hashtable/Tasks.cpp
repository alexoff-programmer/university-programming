#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "HashTable.h"

using namespace std;

/*
1. Постройте Х-Т из слов произвольного текстового файла, задав ее размерность с экрана
Выведите построенную Х-Т слов на экран. Осуществите поиск введенного слова. Выполните
программу для различных размерностей X-Т и сравните количество сравнений. Удалите все слова,
начинающиеся на указанную букву, выведите Х-Т.
*/

//int task1() {
//
//	cout << "Введите размер хеш-таблицы: ";
//	cin >> hashTableSize;
//
//	// Выделяем память под таблицу
//	hashTable = (pNode*)calloc(hashTableSize, sizeof(pNode));
//	if (!hashTable) {
//		cerr << "Ошибка выделения памяти!" << endl;
//		return 1;
//	}
//	
//
//	ifstream file("input.txt");
//	if (!file) {
//		cerr << "Файл input.txt не найден!" << endl;
//		return 1;
//	}
//
//	string word;
//	while (file >> word) {
//		insertNode(word);
//	}
//	file.close();
//
//	printTable();
//
//	// Поиск
//	string searchWord;
//	cout << "\nВведите слово для поиска: ";
//	cin >> searchWord;
//	pNode found = findNode(searchWord);
//	if (!found) cout << "Слово не найдено." << endl;
//
//	// Удаление слов на букву
//	char letter;
//	cout << "\nВведите букву для удаления всех слов на нее: ";
//	cin >> letter;
//
//	pNode nextNode, current;
//	
//	for (int i = 0; i < hashTableSize; i++) {
//		
//		while (current) {
//			current = hashTable[i];
//			// Сохраняем следующее, так как текущее можем удалить
//			nextNode = current->next;
//			if (current->data[0] == letter) {
//				deleteNode(current->data);
//			}
//			current = nextNode;
//		}
//	}
//
//	cout << "\nТаблица после удаления слов на '" << letter << "':" << endl;
//	printTable();
//	free(hashTable);
//	return 0;
//
//
//}

/*
2. Постройте X-Т для зарезервированных слов, используемого ЯП (не менее 20 слов),
содержащую HELP для каждого слова. Выдайте на экран подсказку по введенному слову.
Добавьте подсказку по вновь введенному слову, используя при необходимости реструктуризацию
Х-Т. Сравните эффективность добавления ключа в таблицу или ее реструктуризацию для
различной степени заполненности таблицы.
*/

int task2() {
	hashTableSize = 30; // Можно изменить размер для тестирования
	hashTable = (pNode*)calloc(hashTableSize, sizeof(pNode));
	ifstream file("ЯП.txt");
	string line, searchWord = "", help;
	stringstream ss;
	if (!file) {
		cerr << "Файл ЯП.txt не найден!" << endl;
		return 1;
	}
	// Наполняем нашу базу
	while (getline(file, line)) {
		ss.clear();
		ss.str(line);
		string word, help;
		if (getline(ss, word, '|') && getline(ss, help)) {
			insertNode({ word, help });
		}
	}

	printTable();

	do {
		cout << "Введите искомое слово: ";
		cin >> searchWord;
		pNode node = findNode({ searchWord, "" });
		if (!node) {
			cout << "Слово не найдено. Добавьте к нему подсказку: ";
			cin >> help;
			pNode p = insertNode({ searchWord, help });
			cout << "Подсказка успешно добавлена!\n" << p->data.word << "|" << p->data.help << endl;
		}
	} while (searchWord[0] != '\0');
	return 0;
}

//int task3() {
//	hashTableSize = 30;
//	hashTable = (pNode*)calloc(hashTableSize, sizeof(pNode));
//	ifstream file("numbers.txt");
//	if (!file) {
//		cerr << "Файл numbers.txt не найден!" << endl;
//		return 1;
//	}
//	for (int num; file >> num;) {
//		insertNode(num);
//	}
//	printTable();
//	int searchNum;
//	cout << "Введите число для поиска в Х-Т: ";
//	cin >> searchNum;
//	findNode(searchNum);
//}

/*
* 3. В текстовом файле содержатся целые числа. Постройте X-Т из чисел файла. Осуществите поиск
введенного целого числа в Х-Т. Сравните результаты количества сравнений при различном наборе
данных в файле.
*/