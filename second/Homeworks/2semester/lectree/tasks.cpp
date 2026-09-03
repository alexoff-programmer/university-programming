#include "tasks.h"
#include "db.h"
using namespace std;

pNODE genTree(int n) {
	pNODE root = NULL;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int k = rand() % 100;
		root = addnode(k, root);
	}
	return root;
}

void preorder_file(pNODE root, ofstream& file) {
	if (root) {
		file << root->key << " ";
		preorder_file(root->left, file);
		preorder_file(root->right, file);
	}
}

bool task1() {
	cout << "Create a tree:" << endl;
	pNODE root = genTree(20);
	preorder(root);
	cout << "Write down into a file..." << endl;
	ofstream ofile("./tree.txt");
	if (ofile.is_open()) {
		preorder_file(root, ofile);
		ofile.close();
	}
	else {
		cout << "ERROR!" << endl;
		return false;
	}

	cout << "Read file and create a newRoot:" << endl;
	ifstream ifile("./tree.txt");
	pNODE newRoot = NULL;
	if (ifile.is_open()) {
		int key;
		while (ifile >> key) {
			newRoot = addnode(key, newRoot);
		}
		ifile.close();
	}
	else {
		cout << "ERROR!" << endl;
		return false;
	}
	preorder(newRoot);
	return true;
}

/*
2. Найдите количество четных элементов бинарного дерева. Укажите эти элементы и их
уровни.
*/

int treeEvenCount(pNODE root) {
	if (!root) return 0;
	if (root->key % 2 == 0) {
		return 1 + treeEvenCount(root->left) + treeEvenCount(root->right);
	}
	return treeEvenCount(root->left) + treeEvenCount(root->right);
}

bool task2() {
	pNODE root = genTree(20);
	if (!root)
		return 0;
	inorder(root);
	cout << "Even elements: " << treeEvenCount(root) << endl;
	return 1;
}

/*
3. Найдите сумму элементов сбалансированного дерева, находящихся на уровне k.
*/

bool sumAtLevel(pNODE root, int& k, int* sum, int p = 0) {
	if (!root)
		return 0;
	if (p == k) {
		*sum += root->key;
	}
	sumAtLevel(root->left, k, sum, p + 1);
	sumAtLevel(root->right, k, sum, p + 1);
	return 1;
}

bool task3(int k) {
	if (k < 0) {
		cout << "Invalid tree level!" << endl;
		return false;
	}

	pNODE root = NULL;
	ifstream ifile("./balanced.txt");
	if (ifile.is_open()) {
		int key;
		while (ifile >> key) {
			root = addnode(key, root);
		}
		ifile.close();
	}
	else {
		cout << "ERROR!" << endl;
		return false;
	}

	cout << "Sum of k-level elements: ";
	int sum = 0;
	int* pSum = &sum;
	sumAtLevel(root, k, pSum);
	cout << *pSum << endl;
}

/*
Оператор мобильной связи организовал БД абонентов, содержащую сведения о
телефонах, их владельцах и используемых тарифах, в виде бинарного дерева. Составьте
программу, которая:
- обеспечивает начальное формирование базы данных в виде бинарного дерева;
- производит вывод всей БД;
- производит поиск владельца по номеру телефона;
- выводит наиболее востребованный тариф (по наибольшему числу абонентов)
*/


bool task4() {
	pAbonent db = NULL;
	db = add_abonent(db, 5, "125125125", "Alexander", "Fast");
	load_from_file("./abonents.txt", db);
	print_db(db);
	find_owner(db, "12512552525");
	map<string, int> plans;
	int maxCount = 0;
	string popularPlan;
	most_popular_plan(db, plans);
	for (auto& plan : plans) {
		if (plan.second > maxCount) {
			maxCount = plan.second;
			popularPlan = plan.first;
		}
	}
	cout << "Most popular plan: " << popularPlan << " with " << maxCount << " abonents." << endl;
	return true;
}