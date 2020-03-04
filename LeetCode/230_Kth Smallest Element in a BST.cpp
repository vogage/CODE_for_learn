#include<stdio.h>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> st;
		unordered_set<TreeNode*> set;

		TreeNode *temp = root;
		st.push(temp);
		
		temp = temp->left;
		while (temp) {
			st.push(temp);
			
			temp = temp->left;
		}
		while (!st.empty()) {
			temp = st.top();
			st.pop();
			set.insert(temp);
			k--;
			if (k == 0)return temp->val;
		/*	if (temp->right&&set.find(temp->right) == set.end()) {
				st.push(temp->right);
			}
			while(temp->left&&set.find(temp->left) == set.end()) {
				st.push(temp->left);
				temp = temp->left;
			}*/
			if (temp->right) {
				st.push(temp->right);
				if (temp->right->left) {
					TreeNode* temp2 = temp->right->left;
					while (temp2) {
						st.push(temp2);
						temp2 = temp2->left;
					}
				}
			}
		
		}
		return 0;
	}


};

class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int count = count_node(root->left);
		if (k <= count) {
			return kthSmallest(root->left, k);
		}
		else if(k>count+1){
			return kthSmallest(root->right, k - count - 1);
		}
		return root->val;

	}
	int count_node(TreeNode* root) {
		if (!root) return 0;
		return 1 + count_node(root->left) + count_node(root->right);
	}
};

int main() {
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->left->left->left = new TreeNode(1);

	TreeNode* root1 = new TreeNode(2);
	root1->left = new TreeNode(1);
	root1->right = new TreeNode(3);
	Solution2 mysolu;
	int res = mysolu.kthSmallest(root, 4);
	return 0;
}