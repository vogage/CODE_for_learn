#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		ListNode *first = head;
		ListNode *second = head;
		while (first&&second) {
			first = first->next;
			second = second->next;
			if (second) second = second->next;
		}
		//reverse_nodelist(first);
		second = reverse_nodelist(first);

		first = head;
		ListNode *res=head;
		
		while(first&&second){

			ListNode* temp_first = first->next;
			first->next = second;
			first = temp_first;

			ListNode* temp_second = second->next;
			second->next = first;
			second = temp_second;

		}
		if (!second)first->next = NULL;
			//res = res->next;
		
		//head = res->next;


	}

	ListNode* reverse_nodelist(ListNode* head) {
		ListNode *first = new ListNode(0);
		first->next = head;
		ListNode* next = head->next;
		while (next) {
			head->next = next->next;
			next->next = first->next;
			first->next = next;
			next = head->next;
		}
		return first->next;
		
	}
};

class Solution2 {
public:
	void  reorderList(ListNode* head) {
	
		head = sub_reorder(head);
	}
	ListNode* sub_reorder(ListNode* head) {
		if (!head)return head;
		if (!head->next)return head;
		ListNode *first = head;
		ListNode *second = head->next;
		while (second->next) {
			first = first->next;
			second = second->next;

		}

		ListNode *temp = head->next;
		if (temp == second)return head;
		head->next = second;
		first->next = NULL;
		if(second)second->next = sub_reorder(temp);
		return head;
	}
};

int main() {
	ListNode *n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode*n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	Solution2 mysolu;
	//ListNode* res=mysolu.reverse_nodelist(n1);
	mysolu.reorderList(n1);
	return 0;
}