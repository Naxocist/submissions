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
        cout << curr->val;
        if(curr->next != NULL) cout << " ";
        curr = curr->next;
    }
    cout << endll;

}

void insertNode(int pos, int val){
    if(pos < 0) {
        printf("[%d: %d not inserted]\n", pos, val);
        return ;
    }

    node *newNode = createNode(val);

    node *curr = head, *prev = NULL;
    int index = 0;
    while(curr != NULL && index != pos) {
        prev = curr;
        curr = curr->next;
        index++;
    }

    if(curr == NULL && index != pos){
        printf("[%d: %d not inserted]\n", pos, val);
        return ;
    }

    if(prev == NULL && pos == 0) {
        head = newNode;
        newNode->next = curr;
        return ;
    }

    if(curr == NULL && index == pos){
        prev->next = newNode;
        newNode->next = NULL;
        return ;
    }
    prev->next = newNode;
    newNode->next = curr;  // pos == index

}

void deleteNode(int pos){
    if(pos < 0) {
        printf("[%d: not deleted]\n", pos);
        return ;
    }

    if(head == NULL) {
        printf("[%d: not deleted]\n", pos);
        return ;
    }

    node *curr = head, *prev = NULL;
    int index = 0;
    while(curr && index != pos){
        prev = curr;
        curr = curr->next;
        index++;
    }
    if(!curr){
        printf("[%d: not deleted]\n", pos);
        return ;
    }
    if(!prev){
        printf("[%d: %d deleted]\n", pos, head->val);
        head = head->next;
        return ;
    }

    printf("[%d: %d deleted]\n", pos, curr->val);
    prev->next = curr->next;
    free(curr);

}

void indexingNode(int pos){
    if(pos < 0) {
        printf("[%d: invalid index]\n", pos);
        return ;
    }
    if(head == NULL){
        printf("[%d: invalid index]\n", pos);
        return ;
    }

    node *curr = head;
    int index=0;
    while(curr && index != pos) curr = curr->next, index++;

    if(!curr){
        printf("[%d: invalid index]\n", pos);
        return ;
    }

    printf("%d: %d\n", pos, curr->val);
}


int main() {

     int n; cin >> n;

     while(n--){
         char c; cin >> c;
         int index, x;
         if(c == 'i'){
             cin >> index >> x;
             insertNode(index, x);
         }

         if(c == 'd'){
             cin >> index;
             deleteNode(index);
         }

         if(c == 'v'){
            cin >> index;
            indexingNode(index);
         }

         if(c == 'p') printNode();
     }

    return 0;
}
