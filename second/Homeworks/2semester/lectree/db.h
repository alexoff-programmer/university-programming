#ifndef DB_H
#define DB_H

#include <string>
#include <map>
using namespace std;
/*
Оператор мобильной связи организовал БД абонентов, содержащую сведения о
телефонах, их владельцах и используемых тарифах, в виде бинарного дерева. Составьте
программу, которая:
- обеспечивает начальное формирование базы данных в виде бинарного дерева;
- производит вывод всей БД;
- производит поиск владельца по номеру телефона;
- выводит наиболее востребованный тариф (по наибольшему числу абонентов)
*/

typedef struct Abonent {
	int key;
	string phone;
	string owner;
	string plan;
	struct Abonent* left;
	struct Abonent* right;
} * pAbonent;

pAbonent add_abonent(pAbonent db, int key, string phone, string owner, string plan);
void print_db(pAbonent db);
pAbonent find_owner(pAbonent db, string phone);
void most_popular_plan(pAbonent db, map<string, int> &plans);
void load_from_file(const string& filename, pAbonent root);

#endif