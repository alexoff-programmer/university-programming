#include "db.h"
#include <iostream>
#include <fstream>


pAbonent add_abonent(pAbonent db, int key, string phone, string owner, string plan) {
	if (!db) {
		pAbonent pA = new Abonent();

		pA->key = key;
		pA->phone = phone;
		pA->owner = owner;
		pA->plan = plan;
		pA->left = NULL;
		pA->right = NULL;
		return pA;
	}

	if (key < db->key) {
		db->left = add_abonent(db->left, key, phone, owner, plan);
	}
	else if (key > db->key) {
		db->right = add_abonent(db->right, key, phone, owner, plan);
	}
	return db;
}
void print_db(pAbonent db) {
	if (!db) return;
	print_db(db->left);
	cout << "Phone: " << db->phone << "; Owner: " << db->owner << "; Plan: " << db->plan << endl;
	print_db(db->right);
}
pAbonent find_owner(pAbonent db, string phone) {
	if (!db) return NULL;
	if (db->phone == phone) {
		cout << "Phone: " << db->phone << "; Owner: " << db->owner << "; Plan: " << db->plan << endl;
		return db;
	}
	find_owner(db->left, phone);
	find_owner(db->right, phone);
	return NULL;
}
void most_popular_plan(pAbonent db, map<string, int> &plans) {
	if (!db) return;
	plans[db->plan]++;
	most_popular_plan(db->left, plans);
	most_popular_plan(db->right, plans);
}

void load_from_file(const string& filename, pAbonent root) {
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "Ошибка: Не удалось открыть файл " << filename << endl;
		return;
	}

	// Переменные для временного хранения данных из строки
	int key;
	string phone;
	string name;
	string tariff;

	int count = 0;
	// Читаем файл до тех пор, пока удается считать все 4 поля
	while (file >> key >> phone >> name >> tariff) {
		// Вызываем ваш метод добавления (передаем корень и данные)
		root = add_abonent(root, key, phone, name, tariff);
		count++;
	}

	file.close();
	cout << "Успешно загружено абонентов: " << count << endl;
}