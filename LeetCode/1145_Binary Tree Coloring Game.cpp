#include<stack>

using namespace std;

// Definition for a binary tree node.
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        stack<TreeNode*> st_node;
        st_node.push(root);
        int left_node_sum = 0, right_node_sum = 0;
       
        while (!st_node.empty()) {
            TreeNode* temp = st_node.top();
            st_node.pop();
            if (temp->val == x) {
                left_node_sum = cal_node_num(temp->left);
                right_node_sum = cal_node_num(temp->right);
                break;
            }
            if (temp->left) st_node.push(temp->left);
            if (temp->right)st_node.push(temp->right);

        }
        return n > 2 * (left_node_sum + right_node_sum + 1) ||
            2 * left_node_sum > n || 2 * right_node_sum>n;
    }
    

    int cal_node_num(TreeNode* root) {
        if (!root)return 0;

        int left = cal_node_num(root->left);
        int right = cal_node_num(root->right);
        return 1 + left + right;
    }
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    int n = 11, x = 3;
    bool res = mysolu.btreeGameWinningMove(root, n, x);
    return 0;
}