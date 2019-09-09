#include<stdio.h>
#include<vector>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}

};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		return help(v, 0, v.size() - 1);
	}
	TreeNode* help(vector<int>& v, int start, int end) {
		if (start > end) return nullptr;
		int idx = (start + end) / 2;
		
		TreeNode *root = new TreeNode(v[idx]);
		root->left = help(v, start, idx - 1);
		root->right = help(v, idx + 1, end);
		return root;
		
	}
};

int main() {
	Solution mysolu;
	ListNode* head = new ListNode(-10);
	head->next = new ListNode(-3);
	head->next->next = new ListNode(0);
	head->next->next->next = new ListNode(5);
	head->next->next->next->next = new ListNode(9);
	TreeNode* res = mysolu.sortedListToBST(head);
	return 0;
}