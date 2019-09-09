
#include<stdio.h>

using namespace std;

struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {

		//divide in two list, 
		// one is bigger than x
		// the other is less than x
		
		ListNode *bigger_head = new ListNode(0);
		ListNode *lesser_head = new ListNode(0);
		ListNode *p1 = bigger_head;
		ListNode *p2 = lesser_head;

		while (head) {
			if (head->val >= x) {
				bigger_head->next = head;
				bigger_head = bigger_head->next;
			}
			else {
				lesser_head->next= head;
				lesser_head = lesser_head->next;
			}
			head = head->next;
		}
		bigger_head->next = nullptr;
		lesser_head->next = p1->next;
		return p2->next;
	}
};

int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(4);
	p1->next = p2;
	ListNode *p3 = new ListNode(3);
	p2->next = p3;
	ListNode *p4 = new ListNode(2);
	p3->next = p4;
	ListNode *p5 = new ListNode(5);
	p4->next = p5;
	ListNode *p6 = new ListNode(2);
	p5->next = p6;

	int x = 3;
	Solution mysolu;
	ListNode *ans = mysolu.partition(p1,x);
	return 0;

}