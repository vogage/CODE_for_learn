//
//  889_Construct Binary Tree from Preorder and Postorder Traversal.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/18.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            PostIndexMap[postorder[i]]=i;
            preIndexMap[preorder[i]]=i;
        }
        return help(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
private:
    TreeNode* help(vector<int>& preorder,int prebegin,int preend,vector<int>& postorder,int postbegin,int postend){
       
        TreeNode *root=new TreeNode(preorder[prebegin]);
        int leftroot,leftlen,rightroot,rightlen;
        if(prebegin<preend){
            int leftroot=preorder[prebegin+1];
            int leftlen=PostIndexMap[leftroot]-postbegin+1;
            root->left=help(preorder, prebegin+1, prebegin+leftlen, postorder, postbegin, postbegin+leftlen-1);
            
            if(prebegin+leftlen<preend){
                int rightroot=postorder[postend-1];
                int rightlen=preend-preIndexMap[rightroot]+1;
                
                root->right=help(preorder, preend-rightlen+1, preend, postorder, postend-rightlen, postend-1);
            }
        }
       
        return root;
    }
private:
    unordered_map<int,int> PostIndexMap;
    unordered_map<int,int> preIndexMap;
};

int main(){
    Solution mysolu;
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    vector<int> preorder1={1,2};
    vector<int> postorder1={2,1};
    TreeNode *res=mysolu.constructFromPrePost(preorder1, postorder1);
    return 0;
}

