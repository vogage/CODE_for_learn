#include<iostream>
#include<vector>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (low > high)return 0;
        if (!root)return 0;
        
        return root->val >= low ? (root->val <= high ? root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) :
            rangeSumBST(root->left, low, high)) :rangeSumBST(root->right, low, high);
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right = new TreeNode(15);
    root->right->right = new TreeNode(18);
   
    Solution mysolu;
    int res = mysolu.rangeSumBST(root,7,15);
	return 0;
}
