


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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root)return false;
        int x_depth = -1;
        int y_depth = -1;
        dfs(root, x, x_depth, y, y_depth,0);
        return x_depth == y_depth;
    }
    void dfs(TreeNode* root, int& x, int& x_depth, int& y, int& y_depth,int depth) {
        if (root->val == x) x_depth =depth;
        if (root->val == y)y_depth = depth;
        if (root->left) dfs(root->left, x, x_depth, y, y_depth, depth + 1);
        if (root->right) dfs(root->right, x, x_depth, y, y_depth, depth + 1);
        if (root->left && root->right) {
            if ((root->left->val ==x&& root->right->val==y)||
                (root->left->val == y && root->right->val ==x)) {
                x_depth = -1;
            }
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    Solution mysolu;
    bool res = mysolu.isCousins(root, 5, 4);
    return 0;
}