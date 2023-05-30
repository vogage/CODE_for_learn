#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<math.h>

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
    //    Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b 
    //    where v = | a.val - b.val | and a is an ancestor of b.

    //    A node a is an ancestor of b if either : 
    //    any child of a is equal to b 
    //    or any child of a is an ancestor of b.
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        if (!root)return res;
        int temp_max = root -> val;
        int temp_min = root->val;
        dfs(root, temp_max,temp_min);
        return res;
    }
private:
    void dfs(TreeNode* root,int temp_max,int temp_min) {
        if (!root)return;
        res = max(res, abs(temp_max - root->val));
        res = max(res, abs(temp_min - root->val));
        temp_max = max(temp_max, root->val);
        temp_min = min(temp_min, root->val);
        dfs(root->left, temp_max,temp_min);
        dfs(root->right, temp_max,temp_min);
    }
private:
    int res;
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    int res = mysolu.maxAncestorDiff(root);


    return 0;
}