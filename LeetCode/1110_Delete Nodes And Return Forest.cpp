#include<vector>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

//Given the root of a binary tree, each node in the tree has a distinct value.
//
//After deleting all nodes with a value in to_delete,
//we are left with a forest(a disjoint union of trees).
//
//Return the roots of the trees in the remaining forest.
//You may return the result in any order


// Definition for a binary tree node.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs(root, to_delete);
        return forest;
    }

    void dfs(TreeNode* root, vector<int>& to_delete) {
        if (root->left) {
            if (find_val(root->left,to_delete)) {
                if (is_leaf(root->left)) forest.push_back(root->left);
                else {
                    
                }
            }
        }
    }

    bool find_val(TreeNode* root, vector<int>& to_delete) {     
        vector<int>::iterator iter = find(to_delete.begin(), to_delete.end(), root->val);
        return !(iter == to_delete.end());
    }

    bool is_leaf(TreeNode* root) {
        return !root->left && !root->right;
    }

private:
    vector<TreeNode*> forest;
    
};

class Solution2 {
public:
    vector<TreeNode*> result;
    set<int> to_delete_set;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i : to_delete)
            to_delete_set.insert(i);
        helper(root, result, to_delete_set, true);
        return result;
    }

    TreeNode* helper(TreeNode* node, vector<TreeNode*>& result, set<int>& to_delete_set, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted = to_delete_set.find(node->val) != to_delete_set.end();
        if (is_root && !deleted) result.push_back(node);
        node->left = helper(node->left, result, to_delete_set, deleted);
        node->right = helper(node->right, result, to_delete_set, deleted);
        return deleted ? NULL : node;
    }
};


int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> to_delete = { 3,5 };
    vector<TreeNode*> res = mysolu.delNodes(root, to_delete);
    return 0;
}