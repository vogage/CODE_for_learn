#include<stdio.h>
#include<vector>
#include<queue>

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q_tree;
        q_tree.push(root);
        vector<int> res;
        while (!q_tree.empty()) {
            queue<TreeNode*> temp_q_tree;
            int temp_value = INT_MIN;
            while (!q_tree.empty()) {
                TreeNode* temp = q_tree.front();
                q_tree.pop();
                temp_value = max(temp_value, temp->val);
                if (temp->left) temp_q_tree.push(temp->left);
                if (temp->right) temp_q_tree.push(temp->right);
            }
            res.push_back(temp_value);
            q_tree = temp_q_tree;
        }
        return res;
    }
};

int main() {
    return 0;
}