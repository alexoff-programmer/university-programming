#ifndef TREE_H
#define TREE_H
#endif // !TREE_H


typedef int T;

typedef struct Node {
	T data;
	struct Node* left;
	struct Node* right;
} *pNode;

pNode addNode(pNode root, T data);
pNode delNode(pNode root, T data);
pNode rightMost(pNode root);
pNode findNode(pNode root, T data);
void clearTree(pNode root);
pNode preOrder(pNode root);
pNode postOrder(pNode root);
pNode inOrder(pNode root);
int countNodes(pNode root);
int levelOf(pNode root, T data);
int treeLevel(pNode root);