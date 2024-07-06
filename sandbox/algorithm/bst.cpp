#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left = NULL, *right = NULL;
};



node *createNode(int val) {
    node *newNode = new node;

    newNode->val = val;
    return newNode;
}

node *insertNode(node *root, node *node) {
    if(root == NULL) {
        return root = node;
    }

    if(node->val > root->val) {
        root->right = insertNode(root->right, node);
    }else {
        root->left = insertNode(root->left, node);
    }

    return root;
}

void inOrder(node *root) {

    if(root->left != NULL) inOrder(root->left);
    printf("%d ", root->val);
    if(root->right != NULL) inOrder(root->right);
}


int main() {

    int n; scanf("%d", &n);
    node *root = NULL;

    while(n--) {
        int x; scanf("%d", &x);
        root = insertNode(root, createNode(x));
    }

    inOrder(root);

    return 0;
}