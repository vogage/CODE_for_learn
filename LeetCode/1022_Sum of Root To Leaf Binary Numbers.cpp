

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
    int sumRootToLeaf(TreeNode* root) {
        if (!root)return 0;
        int temp = 0;
        res = 0;
        dfs(root, temp);
        return res;
    }
private:
    void dfs(TreeNode* root, int temp) {
        if (!root)return;
        temp = temp * 2 + root-> val;
        if (!root->left && !root->right) {
            res += temp;
            return;
        }
        dfs(root->left, temp);
        dfs(root->right, temp);
    }
private:
    int res;
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new  TreeNode(0);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
    Solution mysolu;
    int res = mysolu.sumRootToLeaf(root);
    return 0;
}