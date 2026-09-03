// tree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "tree.h"
using namespace std;

pNode addNode(pNode root, T data) {
    if (!root) {
        pNode pN = (pNode)malloc(sizeof(Node));
        pN->data = data;
        pN->left = NULL;
        pN->right = NULL;
    }
    if (data < root->data) root->left = addNode(root->left, data);
    else root->right = addNode(root->right, data);
    return root;
}
pNode delNode(pNode root, T data) {
    if (!root) return root;
    if (root->data == data) {
        if (!root->left && !root->right) {
            free(root);
            return root;
        }
        if (root->left && !root->right) {
            pNode p = root->left;
            free(root);
            return p;
        }
        if (!root->left && root->right) {
            pNode p = root->right;
            free(root);
            return p;
        }
        T temp = rightMost(root)->data;
        root->data = temp;
        delNode(root, temp);
    }
    root->left = delNode(root->left, data);
    root->right = delNode(root->right, data);
    return root;
}
pNode rightMost(pNode root) {
    if (root->right) root = rightMost(root->right);
    return root;
}
pNode findNode(pNode root, T data) {
    if (!root) return NULL;
    if (root->data == data) return root;
    if (data < root->data) return findNode(root->left, data);
    else return findNode(root->right, data);
    
}
void clearTree(pNode root) {
    if (!root) return;
    clearTree(root->left);
    clearTree(root->right);
    free(root);
}
pNode preOrder(pNode root) {
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    return root;
}
pNode postOrder(pNode root) {
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    return root;
}
pNode inOrder(pNode root) {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    return root;
}
pNode countNodes(pNode root, int& c) {

}
pNode levelOf(pNode root, T data, int p, int& h) {
    if (!root) return NULL;
    if (root->data == data) {
        h = p;
        return root;
    }
    levelOf(root->left, data, p + 1, h);
    levelOf(root->right, data, p + 1, h);
    return root;
}
int treeLevel(pNode root, int p, int& h);

int main()
{
    std::cout << "Hello World!\n";
}
