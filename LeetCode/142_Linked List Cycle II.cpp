#include<iostream>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x),next(NULL) {}
};


class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode *first = head;
		ListNode *second = head;
		do {
			if (first) { first = first->next; }
			else return NULL;
			if (second) { second = second->next; }
			else return NULL;

			if (second) { second = second->next; }
			else return NULL;


		} while (first != second);
		ListNode *meet = first;
		first = head;
		while (meet != first) {
			meet = meet->next;
			first = first->next;
		}
		return meet;

	}
};

int main() {
	ListNode *n1 = new ListNode(3);
	ListNode *n2 = new ListNode(2);
	ListNode* n3 = new ListNode(0);
	ListNode* n4 = new ListNode(-4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;
	Solution mysolu;
	ListNode *res = mysolu.detectCycle(n1);
	return 0;
}