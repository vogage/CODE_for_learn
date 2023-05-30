#include<vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n + 1, vector<TreeNode*>());
        TreeNode *root = new TreeNode();
        dp[1].push_back(root);
        for (int k = 1; k <= n; k = k + 2) {
            for (int i = 1; i <= k - 2; i = i + 2) {
                int j = k - i-1;
                for (int ii = 0; ii < dp[i].size(); ii++) {
                    for (int jj = 0; jj < dp[j].size(); jj++) {
                        TreeNode* root2 =new TreeNode();
                        root2->left = dp[i][ii];
                        root2->right = dp[j][jj];
                        dp[k].push_back(root2);
                    }
                }
            }
        }
        return dp[n];
    }
    
};

int main() {
    Solution mysolu;
    int n = 7;
    vector<TreeNode*> res = mysolu.allPossibleFBT(n);


	return 0;
}