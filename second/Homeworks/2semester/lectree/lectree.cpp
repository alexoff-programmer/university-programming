#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tree.h"

using namespace std;


pNODE addnode(int x, pNODE root) {
    if (!root) {
        root = (pNODE)malloc(sizeof(NODE));
        if (root) {
            root->key = x;
            root->left = NULL;
            root->right = NULL;
        }
    }
    else if (x < root->key)
        root->left = addnode(x, root->left);
    else
        root->right = addnode(x, root->right);
    return root;
}

void pr_node(pNODE root) {
    if (root) {
        cout << root->key << " (" << root << ") ";
        cout << "Left=" << root->left << " Right=" << root->right << "\n ";
    }
}

void preorder(pNODE root) {
    if (root) {
        pr_node(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(pNODE root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        pr_node(root);
    }
}

void inorder(pNODE root) {
    if (root) {
        inorder(root->left);
        pr_node(root);
        inorder(root->right);
    }
}

pNODE find_tree(pNODE root, int val) {
    if (!root) return NULL;
    if (val == root->key) return root;
    if (val < root->key) return find_tree(root->left, val);
    else return find_tree(root->right, val);
}

int rightmost(pNODE root) {
    while (root->right) {
        root = root->right;
    }
    return root->key;
}

pNODE del_tree(pNODE root, int val) {
    if (!root) return NULL;
    if (root->key == val) {
		if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        if (!root->right && root->left) {
            pNODE temp = root->left;
            free(root);
            return temp;
		}
        if (!root->left && root->right) {
            pNODE temp = root->right;
            free(root);
            return temp;
        }
		root->key = rightmost(root->left);
        root->left = del_tree(root->left, root->key);
        return root; 
    }
    if (val < root->key) root->left = del_tree(root->left, val);
    else root->right = del_tree(root->right, val);
    return root;
}



int Nnodes(pNODE root) {
    if (!root) return 0;
	return 1 + Nnodes(root->left) + Nnodes(root->right);
}

void Height(pNODE root, int p, int* h) {
    if (!root) return;
    p++;
    if (!root->left && !root->right) {
        if (p > *h) *h = p;
        return;
    }
    Height(root->left, p, h);
    Height(root->right, p, h);
}

void del_all(pNODE root) {
    if (!root) return;
    del_all(root->left);
    del_all(root->right);
    cout << "DEL: " << root << " -> " << root->key << "; ";
    free(root);
}