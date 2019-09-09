#include<stdio.h>
#include<vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return help(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
	}
	TreeNode* help(vector<int>& inorder, vector<int>& postorder, int post_start, int post_end, int in_start, int in_end) {
		if (post_start > post_end || in_start > in_end)return nullptr;
		TreeNode* root = new TreeNode(postorder[post_end]);
		int idx = 0;
		while (idx <= in_end) {
			if (inorder[idx] == root->val) break;
			idx++;
		}
		root->left = help(inorder, postorder, post_start, post_start + idx - in_start - 1, in_start, idx - 1);
		root->right = help(inorder, postorder, post_start + idx - in_start, post_end - 1, idx + 1, in_end);
		return root;
	}


};
int main() {
	vector<int> inorder = { 9,3,15,20,7 };
	vector<int> postorder = { 9,15,7,20,3 };
	Solution mysolu;
	TreeNode* res = mysolu.buildTree(inorder, postorder);
	return 0;
}