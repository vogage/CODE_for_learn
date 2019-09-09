#include<stdio.h>
#include<vector>
#include<stack>


using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
/*
class Solution1 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return helpbuild(0, 0, inorder.size() - 1, preorder, inorder);

		

	}
	TreeNode* helpbuild(int pre_start, int in_start, int in_end, vector<int>& preorder, vector<int> & inorder) {
		if (pre_start > preorder.size() - 1 || in_start > in_end) return NULL;
		TreeNode* root = new TreeNode(preorder[pre_start]);
		int idx = pre_start;
		for (int i = in_start; i <= in_end; i++) {
			if (inorder[i] == root->val) {
				idx = i; break;
			}
		}
		root->left = helpbuild(pre_start + 1, in_start, idx - 1, preorder, inorder);
		root->right = helpbuild(pre_start + idx - in_start + 1, idx + 1, in_end, preorder, inorder);
		return root;
	}
};
*/

class Solution2 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (!inorder.size())return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		int idx = 0;
		while (idx < inorder.size()) {
			if (inorder[idx] == preorder[0])break;
			idx++;
		}
		vector<int> pre_left;
		vector<int> pre_right;
		vector<int> in_left;
		vector<int> in_right;
	//	for(int i=1;i<)
		root->left = buildTree(pre_left, in_left);
		root->right = buildTree(in_left, in_right);


		return root;
	}
	
};

class Solution3 {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {

		if (preorder.size() == 0)
			return NULL;

		stack<int> s;
		stack<TreeNode *> st;
		TreeNode *t, *r, *root;
		int i, j, f;

		f = i = j = 0;
		s.push(preorder[i]);

		root = new TreeNode(preorder[i]);
		st.push(root);
		t = root;
		i++;

		while (i < preorder.size())
		{
			if (!st.empty() && st.top()->val == inorder[j])
			{
				t = st.top();
				st.pop();
				s.pop();
				f = 1;
				j++;
			}
			else
			{
				if (f == 0)
				{
					s.push(preorder[i]);
					t->left = new TreeNode(preorder[i]);
					t = t->left;
					st.push(t);
					i++;
				}
				else
				{
					f = 0;
					s.push(preorder[i]);
					t->right = new TreeNode(preorder[i]);
					t = t->right;
					st.push(t);
					i++;
				}
			}
		}

		return root;
	}
};

class Solution4 {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		stack<TreeNode*> st;
		if (!preorder.size())return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);
		TreeNode* temp = root;
		st.push(root);
		int i = 1;
		bool f = false;
		while (i < preorder.size()) {
			if (!st.empty() && st.top()->val == inorder[i]) {
				temp = st.top();
				st.pop();
				f = !f;
			}
			else {
				if (!f) {
					temp->left = new TreeNode(preorder[i]);
					temp = temp->left;
					st.push(temp);
				}
				else {
					temp->right = new TreeNode(preorder[i]);
					temp = temp->right;
					st.push(temp);
				}
			}
			i++;
		}
		return root;
	}
};

int main() {
	vector<int> pre = { 3,9,20,15,7 };
	vector<int> in = { 9,3,15,20,7 };
	Solution4 mysolu;
	TreeNode* res = mysolu.buildTree(pre, in);
	return 0;
}