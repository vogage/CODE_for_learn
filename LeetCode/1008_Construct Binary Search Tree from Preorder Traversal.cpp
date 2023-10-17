//
//  1008_Construct Binary Search Tree from Preorder Traversal.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val):val(val),left(left),right(right){}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size());
    }
private:
    TreeNode* helper(vector<int>& preorder,int begin,int end){
        if(begin==end) return nullptr;
        TreeNode* root=new TreeNode(preorder[begin]);
        int k=begin+1;
        for(;k<end;k++) if(preorder[k]>preorder[begin]) break;
        root->left=helper(preorder, begin+1, k);
        root->right=helper(preorder, k, end);
        return root;
    }
};

int main(){
    Solution mysolu;
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode *res=mysolu.bstFromPreorder(preorder);
    return 0;
}
