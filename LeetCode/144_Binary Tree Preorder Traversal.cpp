#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		vector<int> res;
		if (!root)return res;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* temp = st.top();
			st.pop();
			res.push_back(temp->val);
			if (temp->right)st.push(temp->right);
			if (temp->left) st.push(temp->left);
			
		}
		return res;
	}
	
};


int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	Solution mysolu;
	vector<int> res = mysolu.preorderTraversal(root);
	return 1;
}