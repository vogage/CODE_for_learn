#include<stdio.h>
#include<stack>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	stack<TreeNode*> st;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> tempst;
		searchp(root, p, tempst);
		while (!st.empty()) {
			TreeNode* temp = st.top();
			st.pop();
			if (searchq(temp, q)) return temp;
		}
		return nullptr;
	}
	void searchp(TreeNode* root, TreeNode* p, stack<TreeNode*> tempst) {
		if (!root)return;		
		tempst.push(root);
		if (root->val == p->val) {
			st = tempst;
			return;
		}

		searchp(root->left, p, tempst);
		searchp(root->right, p, tempst);
		tempst.pop();
	}
	bool searchq(TreeNode* temp, TreeNode* q) {
		stack<TreeNode*> sta;
		sta.push(temp);
		while (!sta.empty()) {
			TreeNode* tp = sta.top();
			sta.pop();
			if (tp->val == q->val) return true;
			if (tp->left)sta.push(tp->left);
			if (tp->right)sta.push(tp->right);
		}
		return false;
	}
};

int main() {
	Solution mysolu;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	
	TreeNode *p = new TreeNode(5);
	TreeNode *q = new TreeNode(1);

	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(2);

	TreeNode *p1 = new TreeNode(1);
	TreeNode* q1 = new TreeNode(2);

	TreeNode * res = mysolu.lowestCommonAncestor(root1, p1, q1);

	return 0;
}