//
//  701_Insert into a Binary Search Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/28.
//

#include <stdio.h>


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //calculate the upper bound
        TreeNode *temp=root;
        TreeNode *pre=temp;
        while(temp){
            pre=temp;
            if(temp->val>val){temp=temp->left;}
            else{
                temp=temp->right;
            }
        }
        if(pre->val>val){
            temp=pre->left;
            pre->left=new TreeNode(val);
            pre->left->left=temp;
        }else{
            temp=pre->right;
            pre->right=new TreeNode(val);
            pre->right->right=temp;
        }
        return root;
        
    }
};


int main(){
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right=new TreeNode(7);
    Solution mysolu;
    TreeNode *res=mysolu.insertIntoBST(root, 5);
    return 0;
}
