//
//  654_Maximum Binary Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
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
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode *left,TreeNode *right):val(val),left(left),right(right){}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return help(nums, 0, nums.size());
    }
private:
    TreeNode *help(vector<int>nums,int begin,int end){
        //[begin,end)
        if(begin==end)return nullptr;
        int index=begin;
        for(int i=index+1;i<end;i++){
            if(nums[i]>nums[index]) index=i;
        }
        TreeNode *temp=new TreeNode(nums[index]);
        temp->left=help(nums, begin, index);
        temp->right=help(nums, index+1, end);
        return temp;
    }
};


int main(){
    Solution mysolu;
    vector<int>nums={3,2,1,6,0,5};
    TreeNode *res=mysolu.constructMaximumBinaryTree(nums);
    return 0;
}
