//
//  662_Maximum Width of Binary Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/20.
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
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //pair <treeNode , index>
        pair<TreeNode*,long long> rp(root,0);
        queue<pair<TreeNode*,long long>> q1;
        q1.push(rp);
        int res=0;
        while(!q1.empty()){
            long long Left=INT_MAX;
            long long Right=INT_MIN;
            queue<pair<TreeNode*,long long>> q2;
            while(!q1.empty()){
                pair<TreeNode*,long long> temp=q1.front();
                q1.pop();
                Left=min(Left,temp.second);
                Right=max(Right,temp.second);
                q2.push(temp);
            }
            res=max(res,(int)(Right-Left+1));
            while(!q2.empty()){
                pair<TreeNode*,long long> temp=q2.front();
                q2.pop();
                if(temp.first->left) q1.push(pair<TreeNode*,long long>(temp.first->left,2*(temp.second-Left)));
                if(temp.first->right) q1.push(pair<TreeNode*,long long>(temp.first->right,2*(temp.second-Left)+1));
                
            }
        }
        return res;
    }
};
       






























class Solution2 {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, pair<int,int>> FloorIndexMap;
        bfs(root,0,0,FloorIndexMap);
        int maxWidth=0;
      
        for(auto m:FloorIndexMap){
            
                maxWidth=max(maxWidth,m.second.second-m.second.first+1);
                
            
        }
        return maxWidth;
    }
private:
    void bfs(TreeNode *root,int index,int depth,unordered_map<int, pair<int,int>> &FloorIndexMap){
        if(FloorIndexMap.find(depth)==FloorIndexMap.end()) FloorIndexMap[depth]=pair<int,int>(index,index);
        else {
            FloorIndexMap[depth].first=min(FloorIndexMap[depth].first,index);
            FloorIndexMap[depth].second=max(FloorIndexMap[depth].second,index);
        }
        //[begin,end)
        if(root->left)bfs(root->left,index*2,depth+1,FloorIndexMap);
        if(root->right)bfs(root->right,index*2+1,depth+1,FloorIndexMap);
    }
};


int main(){
    Solution mysolu;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(5);
    root->left->left->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    root->right->right->left=new TreeNode(7);
    int res=mysolu.widthOfBinaryTree(root);
    return 0;
}
