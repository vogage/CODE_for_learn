#include<stdio.h>
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == nullptr)return res;
        vector<int> temp;
        int temp_sum=0;
        dfs(root, temp_sum, sum, temp, res);
        return res;
    }
    void dfs(TreeNode* root, int temp_sum, int sum, vector<int> temp, vector<vector<int>>& res) {
        //leaf node
        temp_sum += root->val;  
        temp.push_back(root->val); 
        if (root->left == NULL && root->right == NULL) {
            
            if (temp_sum == sum) {
               res.push_back(temp);
                   return;
                
            }
        }
        if (root->left) dfs(root->left, temp_sum, sum, temp, res);
        if (root->right)dfs(root->right, temp_sum, sum, temp, res);
        
    }
};

int main() {
//         5
//        / \
//      4   8
//      /   / \
//   11  13  4
//    / \      / \
//   7  2    5   1
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution mysolu;
    vector<vector<int>> res = mysolu.pathSum(root, 22);
    return 0;
}