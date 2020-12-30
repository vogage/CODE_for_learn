#include<stdio.h>
#include<vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)   return NULL;
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,
        int left_pre, int right_pre, int left_in, int right_in) {
        if (left_pre > right_pre||left_in>right_in)return nullptr;
        TreeNode* root = new TreeNode(preorder[left_pre]);
        int root_index = left_in;
        for (; root_index < right_in;root_index++) {
            if (inorder[root_index] == preorder[left_pre])
            break;
        }
        //left node
       
        root->left = dfs(preorder, inorder, left_pre+1,left_pre+root_index-left_in, left_in, root_index-1);
        //right node
        root->right = dfs(preorder, inorder, right_pre-(right_in-root_index)+1, right_pre, root_index + 1, right_in);
        return root;
    }
};



int main() {
    Solution mysolu;
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    vector<int> preorder2 = { 1,2,3 };
    vector<int> inorder2 = { 3,2,1 };
    TreeNode* res = mysolu.buildTree(preorder2, inorder2);
    return 0;
}