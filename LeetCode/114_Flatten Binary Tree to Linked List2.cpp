#include<stdio.h>
#include<stack>
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* head = new TreeNode(0);
        st.push(root);
        while (!st.empty()) {
             TreeNode* temp =st.top();
             st.pop();
             if (temp->right) st.push(temp->right);
             temp->right = NULL;
             if (temp->left)    st.push(temp->left);
             temp->left = NULL;
             head->right = temp;
             head = head->right;
             
        }
    }
};

int main() {
    Solution mysolu;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    mysolu.flatten(root);
    return 0;

}