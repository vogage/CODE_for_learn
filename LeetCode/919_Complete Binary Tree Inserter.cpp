//
//  919_Complete Binary Tree Inserter  * TreeNode* param_2 = obj->get_root();  *.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/26.
//

#include <stdio.h>
#include <vector>
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

//A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
//
//Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.
//
//Implement the CBTInserter class:
//
//CBTInserter(TreeNode root) Initializes the data structure with the root of the complete binary tree.
//int insert(int v) Inserts a TreeNode into the tree with value Node.val == val so that the tree remains complete, and returns the value of the parent of the inserted TreeNode.
//TreeNode get_root() Returns the root node of the tree.

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x,TreeNode *left,TreeNode *right):val(x),left(left),right(right){}
};


class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        treeroot=new TreeNode(root->val);
        treeNodeque.push(treeroot);
        queue<TreeNode*> que;
        if(root->left) que.push(root->left);
        if(root->right) que.push(root->right);
        while(!que.empty()){
            TreeNode *temp=que.front();
            que.pop();
            insert(temp->val);
            if(temp->left)que.push(temp->left);
            if(temp->right) que.push(temp->right);
        }
      
    }
    
    int insert(int val) {
        TreeNode *temp=treeNodeque.front();
      
        if(!temp->left){
            temp->left=new TreeNode(val);
          
        }else{
            treeNodeque.pop();
            temp->right=new TreeNode(val);
            treeNodeque.push(temp->left);
            treeNodeque.push(temp->right);
           
        }
        return temp->val;
    }
    
    TreeNode* get_root() {
        return treeroot;
    }
private:
    TreeNode* treeroot;
    queue<TreeNode* > treeNodeque;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */


int main(){
//    Input
//    ["CBTInserter", "insert", "insert", "get_root"]
//    [[[1, 2]], [3], [4], []]
//    Output
//    [null, 1, 2, [1, 2, 3, 4]]
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    CBTInserter *obj=new CBTInserter(root);
    int res1=obj->insert(3);
    int res2=obj->insert(4);
    TreeNode *res3=obj->get_root();
    
    
//    ["CBTInserter","insert","insert","insert","insert","get_root"]
//    [[[1,2]],[3],[4],[5],[6],[]]
    TreeNode *root1=new TreeNode(1);
    root1->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);
    CBTInserter *obj1=new CBTInserter(root1);
    int res31=obj1->insert(5);
    int res41=obj1->insert(6);
    int res51=obj1->insert(7);
    int res61=obj1->insert(8);
    int res71=obj1->insert(9);
    int res81=obj1->insert(10);
    TreeNode *res91=obj1->get_root();
    return 0;
}
