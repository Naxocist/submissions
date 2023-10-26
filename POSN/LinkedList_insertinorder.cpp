#include <bits/stdc++.h>
#define endll '\n'
using namespace std;


struct node {
    int val;
    node *next;
};

node *head = NULL;

node *createNode(int val){
    // node *newNode = (node *) malloc(sizeof(node));
    node *newNode = new node;
    newNode->val = val;
    newNode->next = NULL;

    return newNode;
}

void printNode(){

    node *curr = head;

    while(curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endll;

}

void insertNode(int val){
    node *newNode = createNode(val);
    if(head == NULL) {
        head = newNode;
        return ;
    }

    node *curr = head, *prev = NULL;
    while(curr && curr->val < val) {
        prev = curr;
        curr = curr->next;
    }

    if(!prev) {
        head = newNode;
        newNode->next = curr;
        return ;
    }
    prev->next = newNode;
    newNode->next = curr;

}

void deleteNode(int val){
    if(head == NULL) {
        cout << val << " [not deleted]\n";
        return ;
    }

    node *curr = head, *prev = NULL;
    while(curr && curr->val != val){
        prev = curr;
        curr = curr->next;
    }
    if(!curr){
        cout << val << " [not deleted]\n";
        return ;
    }
    if(!prev){
        head = head->next;
        cout << val << " [deleted]\n";
        return ;
    }

    cout << val << " [deleted]\n";
    prev->next = curr->next;
    free(curr);

}


int main() {

     int n; cin >> n;

     while(n--){
         char c; cin >> c;
         int x;
         if(c == 'i'){
             cin >> x;
             insertNode(x);
         }

         if(c == 'd'){
             cin >> x;
             deleteNode(x);
         }

         if(c == 'p') printNode();
     }

    return 0;
}
