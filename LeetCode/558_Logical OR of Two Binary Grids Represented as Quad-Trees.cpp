//
//  558_Logical OR of Two Binary Grids Represented as Quad-Trees.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/12.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(!quadTree1||!quadTree2)return nullptr;
        if(quadTree1->isLeaf&&!quadTree2->isLeaf){
            if(quadTree1->val==1){
                Node* root=new Node(1,quadTree1->val);
                return root;
            }else{
                Node* root=new Node(quadTree2->val,quadTree2->isLeaf,quadTree2->topLeft,quadTree2->topRight,quadTree2->bottomLeft,quadTree2->bottomRight);
                return root;
            }
           
        }
        else if(quadTree2->isLeaf&&!quadTree1->isLeaf){
            if(quadTree2->val==1){
                Node *root=new Node(1,quadTree2->val);
                return root;
            }else{
                Node *root=new Node(quadTree1->val,quadTree1->isLeaf,quadTree1->topLeft,quadTree1->topRight,quadTree1->bottomLeft,quadTree1->bottomRight);
                return root;
            }
            
        }
        else if(quadTree1->isLeaf&&quadTree2->isLeaf){
            Node *root=new Node(quadTree1->val|quadTree2->val,true);
            return root;
        }
        else{
            Node *root=new Node(0,0);
            root->topLeft=intersect(quadTree1->topLeft, quadTree2->topLeft);
            root->topRight=intersect(quadTree1->topRight, quadTree2->topRight);
            root->bottomLeft=intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            root->bottomRight=intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            if((root->topLeft->val==root->topRight->val)&&(root->topRight->val==root->bottomLeft->val)&&(root->bottomLeft->val==root->bottomRight->val)
               &&root->topLeft->isLeaf&&root->topRight->isLeaf&&root->bottomLeft->isLeaf&&root->bottomRight->isLeaf){
                //do not use the root->topLeft->val==root->topRight==root->bottomLeft->val==root->bottomRight->val
                //this can lead to wrong answer!!!
                root->val=root->topLeft->val;
                root->isLeaf=true;
                root->topLeft=nullptr;
                root->topRight=nullptr;
                root->bottomLeft=nullptr;
                root->bottomRight=nullptr;
            }else{
                root->isLeaf=false;
            }
            return root;
        }
        
    }
private:
    
};



int main(){
    //        quadTree1 = [[0,1],[1,1],[1,1],[1,0],[1,0]]
    //        , quadTree2 = [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
    
    //Output: [[0,0],[1,1],[1,1],[1,1],[1,0]]
    
//    Node(bool _val, bool _isLeaf)
    Solution mysolu;
    Node *root1=new Node(1,0);
    root1->topLeft=new Node(1,1);
    root1->topRight=new Node(1,1);
    root1->bottomLeft=new Node(0,1);
    root1->bottomRight=new Node(0,1);
    
    Node *root2=new Node(1,0);
    root2->topLeft=new Node(1,1);
    root2->topRight=new Node(1,0);
    root2->bottomLeft=new Node(1,1);
    root2->bottomRight=new Node(0,1);
    root2->topRight->topLeft=new Node(0,1);
    root2->topRight->topRight=new Node(0,1);
    root2->topRight->bottomLeft=new Node(1,1);
    root2->topRight->bottomRight=new Node(1,1);
    
    Node *res=mysolu.intersect(root1, root2);
    return 0;
    
}
