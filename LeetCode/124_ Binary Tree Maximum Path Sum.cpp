#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct TreeNode {
	TreeNode *left;
	TreeNode* right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
	int globe_sum = INT_MIN;

public:
	int maxPathSum(TreeNode* root) {
		int sum = 0; 
		BST(root);
		return globe_sum;
	}
	//left+right+mid  
	int BST(TreeNode* root) {
		if (root == NULL)return 0;
		int left = max(0, BST(root->left));
		int right = max(0, BST(root->right));
		globe_sum = max(globe_sum, root->val + left + right);
		return max(left, right) + root->val;
		
		
	}



	
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class MySolution {
public:
	int maxPathSum(TreeNode* root) {
		int sum = 0; int globe_sum = INT_MIN;
		BST(root, sum, globe_sum);
		return globe_sum;
	}
	//left+right+mid  
	void BST(TreeNode* root, int sum, int& globe_sum) {
		if (root == NULL)return;
		int left = 0; int right = 0;
		int z = 0;
		bypass(root->left, 0, left);
		bypass(root->right, 0, right);
		sum = left + right + root->val;
		globe_sum = max(sum, globe_sum);
		if (root->left)BST(root->left, 0, globe_sum);
		if (root->right)BST(root->right, 0, globe_sum);
	}

	void bypass(TreeNode* root, int sum, int &gsum) {
		if (root == NULL)return;
		sum = sum + root->val;
		gsum = max(gsum, sum);
		bypass(root->left, sum, gsum);
		bypass(root->right, sum, gsum);

	}


};


int main() {
	TreeNode *t1 = new TreeNode(-10);

	t1->left = new TreeNode(9);
	t1->right = new TreeNode(20);
	t1->right->left = new TreeNode(15);
	t1->right->right = new TreeNode(7);
	Solution mysolu;
	int ans = mysolu.maxPathSum(t1);
	return 0;
}