#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root) return countNodes(root->left)+countNodes(root->right)+1;
		else return 0;
	}
};



int main() {
	TreeNode *root=new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);

	Solution mysolu;
	int res = mysolu.countNodes(root);

	return 0;
}
