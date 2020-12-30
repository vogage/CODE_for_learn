#include<stdio.h>
#include<vector>

using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
    
        return res;
    }
    void dfs(TreeNode* root, TreeNode* target, int K, int& steps, vector<int>& res) {
        
      
      
      
    }
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* target = new TreeNode(5);
    vector<int> res = mysolu.distanceK(root, target, 2);

    return 0;
}