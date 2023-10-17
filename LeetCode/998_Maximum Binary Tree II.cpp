//
//  998_Maximum Binary Tree II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/20.
//

#include <stdio.h>



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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *temp=new TreeNode(val);
        if(temp->val>root->val){
            temp->left=root;
            return temp;
        }else{
            help(root,temp);
            return root;
        }
        
    }
private:
    void help(TreeNode* root,TreeNode* temp){
        if(!root->right){
            root->right=temp;
            return;
        }
        if(root->right->val<temp->val){
            temp->left=root->right;
            root->right=temp;
            return;
        }else{
            help(root->right, temp);
        }
    }
};

int main(){
    Solution mysolu;
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(1);
    root->right=new TreeNode(3);
    int val=4;
    TreeNode *res=mysolu.insertIntoMaxTree(root, val);
    return 0;
}
