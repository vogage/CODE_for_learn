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
    int rob(TreeNode* root) {
        queue<TreeNode* >q1;
        q1.push(root);
        vector<int> sum;
        while (!q1.empty()) {
           
            int temp_sum = 0;
           queue<TreeNode*> q2;

            while (!q1.empty()) {
                TreeNode* temp=q1.front();
                q1.pop();
                temp_sum += temp->val;
                if (temp->left) q2.push(temp->left);
                if (temp->right) q2.push(temp->right);
            }
            q1 = q2;
            sum.push_back(temp_sum);
        }
        //dp
        int n = sum.size();
        if (n == 1)return sum[0];
        if (n == 2)return max(sum[0],sum[1]);
        vector<int> dp(n, 0);
        dp[0] = sum[0];
        dp[1]= max(sum[0], sum[1]);
        for (int i =2; i < n; i++) {
            dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};



class Solution2 {
public:
    int rob(TreeNode* root) {
        if (root == NULL)return 0;
        //robed
        int robbed = root->val;
        int unrobbed = 0;
        if (root->left) {
            robbed = robbed + rob(root->left->left) + rob(root->left->right);
            unrobbed += rob(root->left);
        }
        if (root->right) {
            robbed = robbed + rob(root->right->left) + rob(root->right->right);
            unrobbed += rob(root->right);
        }
       
        
        return max(robbed, unrobbed);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    Solution2 mysolu;
    int res = mysolu.rob(root);
    return 0;
}