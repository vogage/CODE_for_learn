#include<unordered_set>
#include<set>
#include<queue>
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
   // The node of a binary tree is a leaf ifand only if it has no children
   // The depth of the root of the tree is 0. 

   //if the depth of a node is d, the depth of each of its children is d + 1.

   // The lowest common ancestor of a set S of nodes, 
   //    is the node A with the largest depth such that every node in S is
   //    in the subtree with root A.

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        res = NULL;
        vector<TreeNode*> q_root;
        q_root.push_back(root);
        while (1) {
            vector<TreeNode*> temp_q_root;
            for (int i = 0; i < q_root.size(); i++) {
                TreeNode* temp = q_root[i];
                if (temp->left) temp_q_root.push_back(temp->left);
                if (temp->right) temp_q_root.push_back(temp->right);
            }
            if (temp_q_root.size() == 0) break;
            else {
                q_root = temp_q_root;
            }
        }
 
        if (q_root.size() == 1)return q_root.back();
        dfs(root, q_root);
        return res;
    }
private:
    int dfs(TreeNode* root,vector<TreeNode*> q_root) {
        if (res)return 0;
        if (!root)return 0;
        if (find_node(root, q_root)) return 1;
        int left = dfs(root->left,q_root);
        int right = dfs(root->right,q_root);
        int total = left + right; 
        if (total == q_root.size()) {
            res = root;
            return 0;
        }
        return total;
    }

    bool find_node(TreeNode* root, vector<TreeNode*> q_root) {
        vector<TreeNode*>::iterator iter = find(q_root.begin(), q_root.end(), root);
        return iter != q_root.end();
    }
private:
    TreeNode* res;
};


class Solution2 {
public:
    pair<TreeNode*, int> helper(TreeNode* root) {
        if (!root) return { NULL, 0 };
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.second > right.second)
            return { left.first, left.second + 1 };
        if (left.second < right.second)
            return { right.first, right.second + 1 };
        return { root, left.second + 1 };

    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};

int main() {
    Solution2 mysolu;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode* res = mysolu.lcaDeepestLeaves(root);
    return 0;
}