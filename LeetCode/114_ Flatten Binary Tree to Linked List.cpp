#include<stdio.h>
#include<vector>

using namespace std;


struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
	vector<int> res;
	TreeNode *prev;
public:
	void flatten(TreeNode* root) {
		if (!root)
			return;
		flatten(root->right);
		flatten(root->left);
		root->right = prev;
		root->left = nullptr;
		prev = root;
	}

	void flatten2(TreeNode* root) {
		preorder(root);
		TreeNode *t = root;
		for (int i = 1; i < res.size(); i++) {
			t->right = new TreeNode(res[i]);
			t = t->right;
		}
		
	}

	void preorder(TreeNode* root) {
		if (!root)return;
		res.push_back(root->val);
		preorder(root->left);
		preorder(root->right);
	}
};
int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(6);
	Solution mysolu;
	mysolu.flatten(root);
	return 0;
}