#include<stdio.h>
#include<iostream>
#include<stack>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};



class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (!head)return NULL;
		Node *head1 = new Node(head->val, NULL, NULL);
		Node *temp1 = head1;
		Node *temp0 = head;
		while (temp0->next) {
			temp0 = temp0->next;
			temp1->next = new Node(temp0->val, NULL, NULL);
			temp1 = temp1->next;
		}
		temp1 = head1;
//		temp1->random = head->random;
		temp0 = head;
		while (temp0) {
			
			Node* temprand = temp0->random;
			Node* search = head;
			Node* search1 = head1;
			while (search) {
				if (temprand == search) {
					temp1->random = search1;
					break;
				}
				search = search->next;
				search1 = search1->next;
			}
			temp1 = temp1->next;
			temp0 = temp0->next;
		}
		return head1;
	}
};

class Solution2 {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL)return NULL;
		Node *l1 = head;
		Node *l2;
		for (; l1 != NULL; l1 = l1->next->next) {
			l2 = new Node(l1->val,NULL, NULL);
			l2->next = l1->next;
			l1->next = l2;
		}
		Node *newhead = head->next;
		for (l1 = head; l1 != NULL; l1 = l1->next->next) {
			if (l1->random != NULL) l1->next->random = l1->random->next;
		}

		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = l1->next;
			l1->next = l2->next;
			if (l2->next!=NULL) l2->next = l2->next->next;
		}
		return newhead;

	}
};

class Solution3 {
public:
	Node* copyRandomList(Node* head) {
		if (!head)return NULL;
		Node *l1, *l2;
		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = new Node(l1->val, NULL, NULL);
			l2->next = l1->random;
			l1->random = l2;
		}
		Node* newhead = head->random;
		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = l1->random;
		
			l2->random = l2->next ? l2->next->random : NULL;
		}
		for (l1 = head; l1 != NULL; l1 = l1->next) {
			l2 = l1->random;
			l1->random = l2->next;
			l2->next = l1->next ? l1->next->random : NULL;
		}
		return newhead;
	}
};

int main() {
	Solution3 mysolu;
	Node *n1 = new Node(1, NULL, NULL);
	Node *n2 = new Node(2, NULL, NULL);

	n1->next = n2;
	n1->random = n2;
	n2->random = n2;

	Node *res = mysolu.copyRandomList(n1);
	return 0;

}