#include<vector>
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

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> vec_node;
        if (!root)return 0;
        vec_node.push_back(root);
        vector<int> vec_sum;
        while (!vec_node.empty()) {
            vector<TreeNode*> temp_vec_node;
            int level_sum = 0;
            for (int i = 0; i < vec_node.size(); i++) {
                level_sum += vec_node[i]->val;
                if (vec_node[i]->left) temp_vec_node.push_back(vec_node[i]->left);
                if (vec_node[i]->right)temp_vec_node.push_back(vec_node[i]->right);
            }
            vec_sum.push_back(level_sum);
            vec_node = temp_vec_node;
        }
        vector<int>::iterator iter_max = max_element(vec_sum.begin(), vec_sum.end());
        return 1 + distance(vec_sum.begin(), iter_max);

    }
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right = new TreeNode(0);

    int res = mysolu.maxLevelSum(root);
    return 0;
        
}