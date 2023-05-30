




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
    //    Given the root of a binary treeand an integer limit, 
    //    delete all insufficient nodes in the tree simultaneously, 
    //    and return the root of the resulting binary tree.

    //    A node is insufficient if every root to leaf path intersecting 
    //     this node has a sum strictly less than limit.

    //    A leaf is a node with no children.

    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        //    Given the root of a binary treeand an integer limit, 
        //    delete all insufficient nodes in the tree simultaneously, 
        //    and return the root of the resulting binary tree.

        //    A node is insufficient if every root to leaf path intersecting 
        //    this node has a sum strictly less than limit.

        //    A leaf is a node with no children.
        dfs(root,root->val,limit);
        if (!root->left && !root->right) return nullptr;
        return root;
    }

   bool dfs(TreeNode* root,int temp, int limit) {
       if (!root->left && !root->right) {
           if (temp < limit) return false;
           else {
               return true;
           }
       }

       bool left = false;
       bool right = false;
       if (root->left) left = dfs(root->left, temp+root->left->val, limit);
       if (root->right) right = dfs(root->right, temp+root->right->val, limit);
       if (!left) root->left = nullptr;
       if (!right) root->right = nullptr;
       return left || right; 
    }
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(-5);
    root->right = new TreeNode(-3);
    root->right->left = new TreeNode(4);

    TreeNode* root1 = new TreeNode(10);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(10);

    int limit = -1;
    int limit1 = 21;
    TreeNode* res = mysolu.sufficientSubset(root1, limit1);
    return 0;

}