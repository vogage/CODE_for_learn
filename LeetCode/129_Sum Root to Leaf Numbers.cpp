#include<stdio.h>
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
		int total = 0;
		int temp = root->val;
		DFS(root, temp, total);
		return total;
	}
	void DFS(TreeNode* root, int temp, int& total) {
		if (!root->left && !root->right) {
			total += temp;
			return;
		}
		if (root->left) DFS(root->left, temp*10 + root->left->val, total);
		if (root->right)DFS(root->right, temp * 10 + root->right->val, total);
	}
};

int main() {
	TreeNode *t = new TreeNode(4);
	t->left = new TreeNode(9);
	t->right = new TreeNode(0);
	t->left->left = new TreeNode(5);
	t->left->right = new TreeNode(1);
	Solution mysolu;
	int res = mysolu.sumNumbers(t);
	return res;
}


