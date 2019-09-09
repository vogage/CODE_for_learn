#include<stdio.h>
#include<list>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (!head->next)return head;
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		bool change = true;
		
		while (change) {
			change = false;
			ListNode *n0 = dummy;
			ListNode *n1 = dummy->next;
			ListNode *n2 = dummy->next->next;
			while (n1&&n2) {
				if (n1->val > n2->val) {
					n1->next = n2->next;
					n2->next = n1;
					n0->next = n2;
					change = true;
					break;
				}
				n0 = n0->next;
				n1 = n1->next;
				n2 = n2->next;
			}
		}
		return dummy->next;
	}
};

class Solution2 {
public:
	ListNode* sortList(ListNode* head) {
		if (!head)return head;
		ListNode *mid = new ListNode(head->val);
		
		if (!head->next)return head;
		ListNode *p = head->next;
		

		ListNode *p1 = new ListNode(0);
		
		ListNode *p2 = new ListNode(0);
		ListNode *left = p1;
		ListNode *right = p2;
		while (p) {
			if (p->val < mid->val) {
				p1->next = p;
				p1 = p1->next;
			}
			else {
				p2->next = p;
				p2 = p2->next;
			}
			p = p->next;
		}
		p1->next = NULL;
		p2->next = NULL;
		if (!left->next) {
			right->next = sortList(right->next);
			mid->next = right->next;
			return mid;
		}
		left->next = sortList(left->next);
		if (!right->next) {
			ListNode *left_end = left->next;
			while (left_end->next) {
				left_end = left_end->next;
			}
			left_end->next = mid;
			return left->next;
		}
		right->next = sortList(right->next);
	
		ListNode *left_end = left->next;
		while (left_end->next) {
			left_end = left_end->next;
		}
		left_end->next = mid;
		mid->next = right->next;
		return  left->next;
	}
	
};
int main() {
	ListNode *n1 = new ListNode(4);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	Solution2 mysolu;

	ListNode *n11 = new ListNode(-1);
	ListNode *n22 = new ListNode(5);
	ListNode *n33 = new ListNode(3);
	ListNode *n44 = new ListNode(4);
	ListNode *n55 = new ListNode(0);

	n11->next = n22;
	n22->next = n33;
	n33->next = n44;
	n44->next = n55;


	ListNode * res = mysolu.sortList(n11);
	return 0;
}