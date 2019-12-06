#include<stdio.h>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
struct TreeNode {
	TreeNode* left;
	TreeNode*right;
	int val;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		int floor = 0;
		if (!root)return res;
		//stack<pair<TreeNode*, int>> st;
		queue < pair<TreeNode*, int>> q;
		pair<TreeNode*, int> temp(root, 0);
		res.push_back(root->val);
		q.push(temp);
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			if (temp.second > floor) {
				res.push_back(temp.first->val);
				floor++;
			}	
	
			if (temp.first->right) {
				q.push(pair<TreeNode*, int>(temp.first->right, temp.second + 1));
			}		
			if (temp.first->left) {
				q.push(pair<TreeNode*, int>(temp.first->left, temp.second + 1));
			}
	
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> rightSideView(TreeNode* root) {
		
		vector<int> res;
		if (!root)return res;
		dfs(root, res, 1);
		return res;
	}
	void dfs(TreeNode* root, vector<int> &res, int depth) {
		if (!root)return;
		if (res.size() < depth) {
			res.push_back(root->val);
		}
		dfs(root->right, res, depth + 1);
		dfs(root->left, res, depth + 1);
	}
};

int main() {
	TreeNode* root =new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	Solution2 mysolu;
	vector<int> res = mysolu.rightSideView(root);
	return 0;
}