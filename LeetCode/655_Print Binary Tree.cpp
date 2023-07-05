//
//  655_Print Binary Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
#include <vector>
#include <string>
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
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return vector<vector<string>>();
        int depth=cal_depth(root);
        vector<vector<string>> res(depth,vector<string>(pow(2,depth)-1,""));
        help(root,res,0,0,res[0].size());
        return res;
    }
private:
    int cal_depth(TreeNode *root){
        int depth=0;
        queue<TreeNode*> q1;
     
        q1.push(root);
        while(!q1.empty()){
            depth++;
            queue<TreeNode*> q2;
            while(!q1.empty()){
                TreeNode* temp=q1.front();
                q1.pop();
                if(temp->left) q2.push(temp->left);
                if(temp->right) q2.push(temp->right);
            }
            q1=q2;
            
        }
        return depth;
        
    }
    void help(TreeNode *root,vector<vector<string>> &res,int depth,int begin,int end){
        //[begin,end)
        if(begin==end) return;
        int index=(begin+end)/2;
        res[depth][index]=to_string(root->val);
        if(root->left) help(root->left, res, depth+1, begin, index);
        if(root->right) help(root->right, res, depth+1, index+1, end);
    }
};


int main(){
    Solution mysolu;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->right=new TreeNode(4);
    vector<vector<string>> res=mysolu.printTree(root);
    return 0;
}


