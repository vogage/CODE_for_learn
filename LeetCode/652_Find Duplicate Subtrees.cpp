//
//  652_Find Duplicate Subtrees.cpp
//  leetcode
//
//  Created by qiandehou on 2021/12/12.
//

#include <stdio.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
      
  };

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> SubTreeMap;
        vector<TreeNode*> res;
        auxfindDup(root,SubTreeMap,res);
        return res;
        
    }
    string auxfindDup(TreeNode* root,unordered_map<string, int> &SubTreeMap,vector<TreeNode*> &res){
        if(root==NULL) return "#";
        string serial=to_string(root->val)+","+auxfindDup(root->left, SubTreeMap, res)+","+auxfindDup(root->right, SubTreeMap, res);
        if(SubTreeMap.find(serial)!=SubTreeMap.end())SubTreeMap[serial]++;
        else{
            SubTreeMap[serial]=1;
        }
        if(SubTreeMap[serial]==2) res.push_back(root);
        return serial;
        
    }
  
};


//public List<TreeNode> findDuplicateSubtrees(TreeNode root) {
//    Map<String, Integer> serialToId = new HashMap<>();
//    Map<Integer, Integer> idToCount = new HashMap<>();
//    List<TreeNode> res = new LinkedList<>();
//    postorder(root, serialToId, idToCount, res);
//    return res;
//}
//
//private int postorder(TreeNode root, Map<String, Integer> serialToId, Map<Integer, Integer> idToCount, List<TreeNode> res) {
//    if (root == null) return 0;
//    int leftId = postorder(root.left, serialToId, idToCount, res);
//    int rightId = postorder(root.right, serialToId, idToCount, res);
//    String curSerial = leftId + "," + root.val + "," + rightId;
//    int serialId = serialToId.getOrDefault(curSerial, curId);
//    if (serialId == curId) curId++;
//    serialToId.put(curSerial, serialId);
//    idToCount.put(serialId, idToCount.getOrDefault(serialId, 0) + 1);
//    if (idToCount.get(serialId) == 2) res.add(root);
//    return serialId;
//}


class Solution2{
public:
    int curId=1;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> serialToId;
        unordered_map<int, int> idToCount;
        vector<TreeNode*> res;
        postorder(root,serialToId,idToCount,res);
        return res;
    }
    int postorder(TreeNode* root,unordered_map<string, int>& serialToId,unordered_map<int, int>& idToCount,vector<TreeNode*>& res){
        if(root==nullptr) return 0;
        int leftId=postorder(root->left, serialToId, idToCount, res);
        int rightId=postorder(root->right, serialToId, idToCount, res);
        string curSerial=to_string(leftId)+","+to_string(root->val)+","+to_string(rightId);
        int serialId=0;
        if(serialToId.find(curSerial)!=serialToId.end()){
            serialId=serialToId[curSerial];
        }else{
            serialId=curId;
        }
        if(serialId==curId)curId++;
        serialToId[curSerial]=serialId;
        if(idToCount.find(serialId)!=idToCount.end()){
            idToCount[serialId]++;
        }else{
            idToCount[serialId]=1;
        }
        if(idToCount[serialId]==2) res.push_back(root);
        return serialId;
        
    }
};






int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->right->left=new TreeNode(2);
    root->right->left->left=new TreeNode(4);
    root->right->right=new TreeNode(4);
    Solution2 mysolu;
    vector<TreeNode*> res=mysolu.findDuplicateSubtrees(root);
    return 0;
    
}
