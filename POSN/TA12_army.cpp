#include <bits/stdc++.h>
using namespace std;


struct node{
    int val;
    node *left, *right;
};


node *createNode(double data){
    node *newNode = new node;
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node *insertBST(node *root, int data){
    if(root == NULL) return createNode(data);

    if(data < root->val){
        root->left = insertBST(root->left, data);
    }else{
        root->right = insertBST(root->right, data);
    }

    return root;
}

void inOrder(node *root){
    if(root == NULL) return ;

    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}


int main(){

    int n, x; scanf("%d", &n);

    node *root = NULL;
    while(n--){
        scanf("%d", &x);

        root = insertBST(root, x);
    }
    if(root == NULL) {
        return 0;
    }

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();

        for(int i=0; i<s; ++i){

            node *N = q.front();
            q.pop();
            if(i==0 || i == s-1){
                printf("%d ", N->val);
            }

            if(N->left != NULL) q.push(N->left);
            if(N->right != NULL) q.push(N->right);
        }   

        printf("\n");
    }
    // inOrder(root);
    return 0;
}
