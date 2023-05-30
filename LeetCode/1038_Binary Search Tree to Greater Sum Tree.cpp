#include<stdio.h>
#include<stack>
#include<unordered_set>
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
 

//Given the root of a Binary Search Tree(BST), 
//convert it to a Greater Tree such that every key of the original BST is changed to
//the original key plus the sum of all keys greater than the original key in BST.
//
//As a reminder, a binary search tree is a tree that satisfies these constraints :
//
//1. The left subtree of a node contains only nodes with keys less than the node's key.
//2. The right subtree of a node contains only nodes with keys greater than the node's key.
//3. Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> st_tree;
        unordered_set<TreeNode*> st_set;
        st_tree.push(root);
        int res = 0;
        while (!st_tree.empty()) {
            TreeNode* temp = st_tree.top();
            while (temp->right&&st_set.find(temp->right)==st_set.end()){
                st_tree.push(temp->right);
                temp = temp->right;
            }
            TreeNode* temp2 = st_tree.top();
            st_tree.pop();
            res += temp2->val;
            st_set.insert(temp2);
            temp2->val = res;
            if (temp2->left)st_tree.push(temp2->left);

        }
        return root;
    }
};


int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution mysolu;
    TreeNode* res = mysolu.bstToGst(root);
    return 0;
}