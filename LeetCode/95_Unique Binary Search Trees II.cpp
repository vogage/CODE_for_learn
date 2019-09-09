#include<stdio.h>
#include<vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution 
{
public:
	vector<TreeNode *> generateTrees(int n) {
		return genTrees(1, n);
	}

	vector<TreeNode *> genTrees(int start, int end) {
		vector<TreeNode*>  list;
		if (start > end) {
			list.push_back(NULL);
			return list;
		}
		if (start == end) {
			list.push_back(new TreeNode(start));
			return list;
		}

		vector<TreeNode*> left, right;
		for (int i = start; i <= end; i++) {
			left = genTrees(start, i - 1);
			right = genTrees(i + 1, end);
			for (TreeNode* lnode : left) {
				for (TreeNode*rnode: right) {
					TreeNode* root = new TreeNode(i);
					root->left = lnode;

					root->right = rnode;
					list.push_back(root);

				}
			}
		}
		return list;
	}
private:

};

int main() {
	Solution mysolu;
	vector<TreeNode*> res;
	res = mysolu.generateTrees(3);
	return 0;
}