#include "tree.h"
#include <iostream>
//#include <malloc.h>
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
#include "tasks.h"

using namespace std;

// --- Основная функция ---
int main() {

    task4();

    //pNODE p, root = NULL;
    //int i, j, k, * h;
    //int val_h = 0;
    //h = &val_h;

    //srand(time(NULL));

    //// Инициализация дерева
    //root = addnode(10, root);
    //cout << 10 << " ";

    //for (i = 0; i < 7; i++) {
    //    k = rand() % 21;
    //    root = addnode(k, root);
    //    cout << k << " ";
    //}
    //cout << endl;

    //// Вывод обходов
    //cout << "preorder : \n";
    //preorder(root);

    //cout << "\npostorder: \n";
    //postorder(root);

    //printf("\ninorder: \n");
    //inorder(root);

    //cout << "!!! Top=" << root << endl;

    //// Статистика
    //i = 0;
    //Nnodes(root, &i);
    //printf("\nIn tree %d nodes\n", i);

    //*h = 0;
    //Height(root, 0, h);
    //printf("\nHeight tree =%d \n", *h);

    //// Цикл удаления случайных узлов
    //for (j = i = 0; i < 5 && j < 3; i++) {
    //    k = rand() % 101;
    //    p = find_tree(root, k);
    //    if (p) {
    //        cout << "------------------------------\n DELETE: ";
    //        pr_node(p);
    //        cout << endl;
    //        root = del_tree(root, k);
    //        inorder(root);
    //        j++;
    //    }
    //    else printf("\nValue %d not find\n", k);
    //}

    //cout << " END DELETE!\n";
    //postorder(root);

    //cout << " Delete tree\n";
    //del_all(root);
    //root = NULL;
    //cout << root << endl;

    return 0;
}