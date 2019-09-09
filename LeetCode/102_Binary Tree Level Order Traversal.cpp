#include<stdio.h>
#include<queue>
#include<vector>
#include<stack>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode*right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}

};
class Solution1 {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> q;
		vector<vector<int>> res;

		q.push(pair<TreeNode*,int>(root, 0));
		while (!q.empty()) {
			pair<TreeNode*, int>temp = q.front();
			q.pop();
			if (res.size() <= temp.second) res.push_back(vector<int>());
			res[temp.second].push_back(temp.first->val);
			if (temp.first->left) q.push(pair<TreeNode*, int>(temp.first->left, temp.second + 1));
			if (temp.first->right)q.push(pair<TreeNode*, int>(temp.first->right, temp.second + 1));
		}
		return res;
	}


};

class Solution2 {
public: 
	vector<vector<int>> levelOrder(TreeNode* root) {
	
		queue<TreeNode* > q;
		vector<vector<int>> res;
		vector<int> cur;

		if (!root)return res;
		q.push(root);
		q.push(NULL);
		while (!q.empty()) {
			TreeNode* temp = q.front();
			q.pop();
			if (temp == NULL) {
				res.push_back(cur);
				cur.resize(0);
				if (q.size() > 0)q.push(NULL);
			}
			else {
				cur.push_back(temp->val);
				if (temp->left)q.push(temp->left);
				if (temp->right)q.push(temp->right);
			}
		}
		return res;
	}
};


int main() {
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution2 mysolu;
	vector<vector<int>> res = mysolu.levelOrder(root);
	return 0;

}