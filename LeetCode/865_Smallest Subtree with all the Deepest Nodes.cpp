#include<stdio.h>
#include<stack>
#include<unordered_map>


using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) :left(NULL), right(NULL), val(x) {}
};


class Solution {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		unordered_map<TreeNode*, pair<int, int>> map_tre;
		TreeNode* res=nullptr ;
		get_depth(root, map_tre,1);
		get_root(root, map_tre,res);
		return res;
	}
	void get_root(TreeNode*root,unordered_map<TreeNode*,pair<int,int>>&map_tre,TreeNode* &res) {
		if (!root->left&&!root->right)return;
		if (!root->right) { res = root->left; get_root(root->left, map_tre, res); }
		if (!root->left) { res = root->right; get_root(root->right, map_tre, res); }
		if (map_tre[root->left].second == map_tre[root->right].second) { res = root; return; }
		else {
			if (map_tre[root->left].second > map_tre[root->right].second) {
				get_root(root->left,map_tre,res);
			}
			else {
				get_root(root->right,map_tre,res);
			}
		}
	}
	void get_depth(TreeNode* root,unordered_map<TreeNode*,pair<int,int>>&map_tre, int depth) {
		if (!root)return;
		map_tre[root].first = depth;
		get_depth(root->left, map_tre, depth + 1);
		get_depth(root->right, map_tre, depth + 1);
		int left_max_depth=0, right_max_depth=0;
		if (root->left) left_max_depth = map_tre[root->left].second;
		if (root->right) right_max_depth = map_tre[root->right].second;
		depth = max(left_max_depth, depth);
		depth = max(right_max_depth, depth);
		map_tre[root].second = depth;



	}
	
};

class Solution2 {
public:
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		pair<TreeNode*, int> res = deep_tree(root);
		return res.first;
	}
	pair<TreeNode*, int> deep_tree(TreeNode* root) {
		if (!root)return pair<TreeNode*, int>(NULL, 0);
		pair<TreeNode*, int> left = deep_tree(root->left), right = deep_tree(root->right);
		int d1 = left.second, d2 = right.second;
		return pair<TreeNode*, int>(d1 == d2 ? root : d1 > d2 ? left.first : right.first, max(d1, d2) + 1);
	}
};

int main() {
	Solution2 mysolu;

	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	TreeNode* res = mysolu.subtreeWithAllDeepest(root);
	return 0;
}