#include <bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *next;
};


node *createNode(int v) {
	node *N = new node;
	N->val = v;
	N->next = NULL;
	return N;
}

node *pushFront(node *head, int v) {
	node *N = createNode(v);
	if(head == NULL) return N;

	N->next = head;
	return N;
}

node *pushBack(node *head, int v) {
	if(head == NULL) return createNode(v);

	head->next = pushBack(head->next, v);
	return head;
}

node *popFront(node *head) {
	if(head == NULL || head->next == NULL) return NULL;

	node *t = head->next;
	free(head);
	return t;
}

node *popBack(node *head) {
	if(head == NULL) return NULL;

	if(head->next == NULL) {
		free(head);
		return NULL;
	}

	head->next = popBack(head->next);
	return head;
}

node *insert(node *head, int v, int pos) {

	if(pos == 0 || head == NULL) {
		node *N = createNode(v);
		N->next = head;
		return N;
	} 

	head->next = insert(head->next, v, pos-1);
	return head;
}

node *deletePos(node *head, int pos) {
	if(head == NULL) return head;

	if(pos == 0) {
		node *t = head->next;
		free(head);
		return t;
	}

	head->next = deletePos(head->next, pos-1);

	return head;
}

int findVal(node *head, int v, int pos) {
	if(head == NULL) return -1;

	if(head->val == v) return pos;

	return findVal(head->next, v, pos+1);
}

int findIdx(node *head, int p, int pos) {
	if(head == NULL) return -1;

	if(pos == p) {
		return head->val;
	}

	return findIdx(head->next, p, pos+1);
}


node *deleteVal(node *head, int v) {
	int idx = findVal(head, v, 0);
	if(idx == -1) {
		printf("Not in linked list\n");
		return head;
	}

	return deletePos(head, idx);
}




void print(node *head) {
	if(head == NULL) return ;

	printf("%d ", head->val);
	print(head->next);
	return ;
}

int main() {

	node *head = createNode(3);

	head = pushFront(head, 2);
	head = pushBack(head, 4);
	head = pushFront(head, 100);
	head = insert(head, 1000, 5);


	print(head);
	head = deletePos(head, 10);
	printf("\n");
	print(head);
	printf("\n");
	head = popBack(head);
	print(head);
	printf("\n");
	head = deleteVal(head, 2);
	print(head);	
	printf("\n");
	printf("idx 2 val : %d", findIdx(head, 100, 0));
	// printf("find 3 : %d\n", findPos(head, 3, 0));
	// printf("find 10 : %d\n", findPos(head, 10, 0));
	// printf("find 1000 : %d\n", findPos(head, 1000, 0));


	return 0;
}
