#include<stdio.h>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> temp;
		//BST(res, temp,root,sum,0);
		BST(res, temp, root, sum);
		return res;
	}
	/*
	void BST(vector<vector<int>> &res, vector<int>& temp,TreeNode *root, int sum, int depth) {
		vector<int> temp2 = temp;
		if (!root)return;
		temp2.push_back(root->val);
		if (root->val == sum&&!root->left&&!root->right) { res.push_back(temp2); return; }
		
		BST(res, temp2, root->left, sum - root->val, depth + 1);
		BST(res, temp2, root->right, sum - root->val, depth + 1);
		return;

		
		
	}
	*/
	void BST(vector<vector<int>> &res, vector<int>& temp, TreeNode *root, int sum) {

		if (!root)return;
		temp.push_back(root->val);

		if (root->val == sum && (!root->left) && (!root->right)) { 
			res.push_back(temp); return; 
		}



		BST(res, temp, root->left, sum - root->val);
		BST(res, temp, root->right, sum - root->val);

		temp.pop_back();




	}
};

int main() {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);
	root->right->right ->left= new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	Solution mysolu;
	vector<vector<int>> res = mysolu.pathSum(root, 22);
	return 0;
}