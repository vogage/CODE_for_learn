#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

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
 

//You are given the root of a binary tree.
//We install cameras on the tree nodes where each camera at a node can monitor its parent, itself,
//and its immediate children.
//
//Return the minimum number of cameras needed to monitor all nodes of the tree.

class Solution {
private:
    int res = 0;
    int UnMonitor = 0;
    int Monitored_NoCam = 1;
    int Monitored_WithCam = 2;

public:
    int minCameraCover(TreeNode* root) {
        res = 0;
        return (dfs(root) ==0 ? 1 : 0) + res;
        return res;
    }
    int dfs(TreeNode* root) {
        if (!root)return Monitored_NoCam;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left == Monitored_NoCam && right == Monitored_NoCam) {
            return UnMonitor;
        }
        else if (left == UnMonitor || right == UnMonitor) {
            res++;
            return Monitored_WithCam;
        }
        else {
            return Monitored_NoCam;
        }
    }

};

int main() {

}