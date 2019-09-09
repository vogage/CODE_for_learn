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
	ListNode* insertionSortList(ListNode* head) {
		ListNode* temp_end = head;
		ListNode* dummy=new ListNode(0);
		dummy->next = head;
		if (!head)return head;

		while (temp_end->next) {
			ListNode* choose = temp_end->next;
			temp_end->next = temp_end->next->next;
			ListNode* n2 = dummy->next;
			ListNode* n1 = dummy;
			while (n1 != temp_end) {
				if (choose->val < n2->val) {
					n1->next = choose;
					
					choose->next = n2;
					break;
				}
				n1 = n1->next;
				n2 = n2->next;
			}
			if (n1 == temp_end) {
				n1->next = choose;

				choose->next = n2;
				temp_end = choose;
			}
			//temp_end = temp_end->next;
		}
		return dummy->next;
	}
};

int main() {
	ListNode *n1 = new ListNode(4);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(3);
	ListNode *n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	ListNode *n11 = new ListNode(-1);
	ListNode *n12 = new ListNode(5);
	ListNode *n13 = new ListNode(3);
	ListNode *n14 = new ListNode(4);
	ListNode *n15 = new ListNode(0);
	n11->next = n12;
	n12->next = n13;
	n13->next = n14;
	n14->next = n15;



	Solution mysolu;
	ListNode *ans = mysolu.insertionSortList(n11);
	return 0;
}