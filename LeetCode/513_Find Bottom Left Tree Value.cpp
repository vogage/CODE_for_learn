#include<stdio.h>
#include<vector>
 
using namespace std;

//Definition for a binary tree node.
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
    int findBottomLeftValue(TreeNode* root) {
        int res= 0;
        int depth = 0;
        dfs(root,res,1,depth);
        
        return res;
    }
    void dfs(TreeNode* root, int& res, int temp_depth,int& depth) {
        if (temp_depth > depth) {
            res = root->val;
            depth = temp_depth;
        }
        if (root->left) dfs(root->left, res, temp_depth + 1, depth);
        if (root->right) dfs(root->right, res, temp_depth + 1, depth);
     }

};
int main() {

	return 0;
}