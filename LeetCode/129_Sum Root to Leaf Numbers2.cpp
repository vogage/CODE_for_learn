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
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		int temp = 0;
		dfs(root, temp, res);
		return res;
	}

	void dfs(TreeNode* root, int temp, int& res) {
		temp = root->val + temp * 10;
		if (root->left) dfs(root->left, temp, res);
		if (root->right) dfs(root->right, temp, res);
		if ((!root->left) && (!root->right)) res += temp;
		return;
	}
};


int main() {
	Solution mysolu;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	int res = mysolu.sumNumbers(root);
	return 0;
}