#include<stdio.h>
#include<stack>
#include<vector>

using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 /*
  class Solution {
  public:
	  bool isValidBST(TreeNode* root) {
		  stack<TreeNode*> st;
		  vector<int> v;
		  TreeNode* cur = root;
		  TreeNode* pre =nullptr;
		  while (cur || !st.empty()) {
			  while (cur) {
				  st.push(cur);
				  cur = cur->left;

			  }

			  cur = st.top();
			  if (pre&&cur->val <= pre->val)return false;
			  st.pop();
			  pre = cur;
			  cur = cur->right;
		  }
		  return true;
	  }

	  
  };
  
  */
  class Solution {
  public:
	  bool isValidBST(TreeNode* root) {
		  if (!root)return true;
		  stack<TreeNode*> st;
		  vector<int> v;
		  TreeNode* cur = root;
		  while (cur || !st.empty()) {
			  if (cur) {
				  st.push(cur);
				  cur = cur->left;

			  }
			  else {
				  TreeNode *temp = st.top();
				  v.push_back(temp->val);
				  st.pop();
				  cur = temp->right;
			  }
		  }
		  for (int i = 0; i < v.size() - 1; i++) {
			  if (v[i] >= v[i + 1])return false;
		  }
		  return true;
	  }
  };

int main() {
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(20);
	Solution mysolu;
	bool res = mysolu.isValidBST(root);
	return 0;
}