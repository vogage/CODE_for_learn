#include<stdio.h>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


class BSTIterator {
public:
	int min = INT_MIN;
	int max = INT_MIN;
	TreeNode *node;
	BSTIterator(TreeNode* root) {
		node = root;
		TreeNode *node2 = node;
		while (node2->right) {
			node2 = node2->right;
		}
		max = node2->val;
	}

	/** @return the next smallest number */
	int next() {
		if (node->val > min) {
			if (!node->left) {
				min = node->val;
				
				return min;
			}
			else {
				node = node->left;
				next();
			}
		}
		else {
			node = node->right;
			next();
		}

	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		if (min < max) return true;
		else return false;
	}
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


class BSTIterator2 {
public:
	vector<int> q;
	
	BSTIterator2(TreeNode* root) {
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode *node = st.top();
			st.pop();
			if (node->left) {
				st.push(node->left);
			}
			if (node->right) st.push(node->right);
	
			q.push_back(node->val);				
		
			
		}
		sort(q.begin(), q.end());
		reverse(q.begin(), q.end());
	}

	/** @return the next smallest number */
	int next() {
		if (hasNext()) {
			int res= q.back();
			q.pop_back();
			return res;
		}
		
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return!q.empty();
	}
};
int main() {
	TreeNode *root = new TreeNode(7);
	root->left = new TreeNode(3);
	root->right = new TreeNode(15);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(20);
	BSTIterator2* obj = new BSTIterator2(root);
	int param_1 = obj->next();
	int param_2 = obj->next();
	int param_3 = obj->next();

	int param_0 = obj->hasNext();
	return 0;
}





















