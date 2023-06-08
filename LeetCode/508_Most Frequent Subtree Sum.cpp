//
//  508_Most Frequent Subtree Sum.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/7.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>

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
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){};
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //mid
        vector<int> res;
        GlobalMaxFreq=0;
        int sum=sub_tree_sum(root);
      
        
        for(auto m:SumFreq){
            if(m.second==GlobalMaxFreq) res.push_back(m.first);
        }
        return res;
    }
private:
    
    int sub_tree_sum(TreeNode *root){
        if(!root)return 0;
        int left=sub_tree_sum(root->left);
        int right=sub_tree_sum(root->right);
        int sum=left+right+root->val;
        SumFreq[sum]++;
        if(SumFreq[sum]>GlobalMaxFreq) GlobalMaxFreq=SumFreq[sum];
        return sum;
    }
    
private:
    int GlobalMaxFreq;
    unordered_map<int, int> SumFreq;
    
};


int main(){
    Solution mysolu;
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(2);
    root->right=new TreeNode(-3);
    TreeNode *root1=new TreeNode(3);
    root1->left=new TreeNode(1);
    root1->right=new TreeNode(5);
    root1->left->left=new TreeNode(0);
    root1->left->right = new TreeNode(2);
    root1->left->right->right=new TreeNode(3);
    root1->right->left=new TreeNode(4);
    root1->right->right=new TreeNode(6);
    
    vector<int> res=mysolu.findFrequentTreeSum(root1);
    return 0;
}

