#ifndef TREE_H
#define TREE_H

typedef struct NODE {
    int key;
    struct NODE* left, * right;
} *pNODE;

// Прототипы функций
pNODE addnode(int x, pNODE root);
void preorder(pNODE root);  // нисходящий обход
void postorder(pNODE root); // восходящий обход
void inorder(pNODE root);   // последовательный обход
pNODE find_tree(pNODE root, int val);
int rightmost(pNODE root);  // поиск крайнего правого листа для замены
pNODE del_tree(pNODE root, int val);
void Nnodes(pNODE root, int* p);
void Height(pNODE root, int p, int* h);
void del_all(pNODE root);
void pr_node(pNODE root);

#endif