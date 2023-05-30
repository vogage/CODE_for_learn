#include<stdio.h>
#include<stack>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
		if (!root) return false;
		int uni_val = root->val;
		stack<TreeNode*> st;
		if(root->left) st.push(root->left);
		if (root->right) st.push(root->right);
		while (!st.empty()) {
			TreeNode* temp = st.top();
			st.pop();
			if (temp->left) st.push(temp->left);
			if (temp->right) st.push(temp->right);
			if (temp->val !=uni_val)return false;
		}
		return true;
    }
};

int main() {
	Solution mysolu;
	TreeNode* root = new TreeNode(2);
	bool res = mysolu.isUnivalTree(root);
	return 0;
}