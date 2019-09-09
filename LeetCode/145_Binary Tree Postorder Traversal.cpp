#include<stdio.h>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> PostorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root)return res;
		stack<TreeNode*> st;
		
		st.push(root);
		while (!st.empty()) {
			TreeNode* temp = st.top();
			st.pop();
			if (temp->left) st.push(temp->left);
			if (temp->right)st.push(temp->right);
			
	
		}
		reverse(res.begin(), res.end());
		return res;
	}
};



int main() {
	Solution mysolu;
	TreeNode *root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	vector<int> res = mysolu.PostorderTraversal(root);
	return 0;
}