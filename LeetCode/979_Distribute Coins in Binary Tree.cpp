#include<unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	//You are given the root of a binary tree with n nodes where each node in the tree has node,
	//val coins.There are n coins in total throughout the whole tree.

	//In one move, we may choose two adjacent nodesand move one coin from one node to another.
	//A move may be from parent to child, or from child to parent.

	//Return the minimum number of moves required to make every node have exactly one coin.

	int distributeCoins(TreeNode* root) {
		res = 0;
		int temp = dfs(root);
		return res;
	}

	int dfs(TreeNode* root) {
		if (!root)return 0;

		int left = dfs(root->left);
		int right = dfs(root->right);
		root->val = root->val + left + right - 1;
		res += abs(left);
		res += abs(right);
		return root->val;
	}
private:
	int res = 0;
};


int main() {
	Solution mysolu;
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(3);
	root->right = new TreeNode(0);
	//[4, 0, null, null, 0, null, 0]
	TreeNode* root1 = new TreeNode(4);
	root1->left =new TreeNode( 0);
	root1->left->right = new TreeNode(0);
	root1->left->right->right = new TreeNode(0);

	int res = mysolu.distributeCoins(root);
	return 0;
}