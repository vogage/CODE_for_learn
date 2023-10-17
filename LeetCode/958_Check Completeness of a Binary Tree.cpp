//
//  958_Check Completeness of a Binary Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/12.
//

#include <stdio.h>
#include <queue>

using namespace std;

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
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        
        TreeNode* Node1=root;
        TreeNode* Node2=nullptr;
        que.push(Node1);
        while(!que.empty()){
            Node2=Node1;
            Node1=que.front();
            que.pop();
            if(Node1&&!Node2)return false;
            if(!Node1)continue;
            que.push(Node1->left);
            que.push(Node1->right);
        }
        return true;
    }
};
int main(){
    Solution mysolu;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(7);
    bool res=mysolu.isCompleteTree(root);
    return 0;
}

