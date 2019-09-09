#include<stdio.h>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {

		stack<ListNode*> st;
		ListNode *first = head;
		ListNode *out = new ListNode(0);
		ListNode *out_first = out;
		while (first) {
			if (st.empty()) {
				st.push(first);
				first = first->next;
			}
			else {
				if (st.top()->val == first->val) {
					st.push(first);
					first = first->next;
				}
				else {
					if (st.size() == 1) {
						out_first->next = st.top();
						out_first=out_first->next;
						st.pop();
						st.push(first);
						first = first->next;
					}
					else {
						while (!st.empty()) {
							st.pop();
						}
						st.push(first);
						first = first->next;
					}
				}
			}
		}
		if (!st.empty()) {
			if (st.size() == 1) out_first->next = st.top();
			else out_first->next = NULL;
		}
		return out->next;
	}
};
int main() {
	ListNode *p1 = new ListNode(1);
	ListNode *p11 = new ListNode(2);
	p1->next = p11;
	ListNode *p2 = new ListNode(2);
	p11->next = p2;
	/*
	ListNode *p3 = new ListNode(3);
	p2->next = p3;
	ListNode *p4 = new ListNode(3);
	p3->next = p4;
	ListNode *p55 = new ListNode(3);
	p4->next = p55;
	ListNode *p5 = new ListNode(4);
	p55->next = p5;
	ListNode *p6 = new ListNode(4);
	p5->next = p6;
	ListNode *p7 = new ListNode(5);
	p6->next = p7;
	*/
	Solution mysolu;

	ListNode *ans = mysolu.deleteDuplicates(p1);



	return 0;
}