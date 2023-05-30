#include<stdio.h>
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int temp_depth =1;
        if (temp_depth == depth) {
            TreeNode* temp = root;
            root = new TreeNode(val);
            root->left = temp;
            return root;
        }
        support_add(root, val, temp_depth+1, depth);
        return root;
    }
    void support_add(TreeNode* root, int val, int temp_depth, int depth) {
        if (!root)return;
        if (temp_depth == depth) {
    
                TreeNode* temp_left = root->left;
                root->left = new TreeNode(val);
                root->left->left = temp_left;
   
     
                TreeNode* temp_right = root->right;
                root->right = new TreeNode(val);
                root->right->right = temp_right;
      
        }
        if (temp_depth <= depth) {
            if (root->left) support_add(root->left, val, temp_depth + 1, depth);
            if (root->right) support_add(root->right, val, temp_depth + 1, depth);
        }
      
        return;
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right= new TreeNode(3);
    root2->left->left= new TreeNode(4);

    Solution mysolu;
    int val = 5;
    int depth = 4;

    TreeNode* res = mysolu.addOneRow(root2, val, depth);
    return 0;
}