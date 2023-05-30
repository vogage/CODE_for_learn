#include<vector>

#include<stack>

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
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        stack<TreeNode*> st;
        if (!root)return res;
        st.push(root);
        int index = 0;
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if (temp->val != voyage[index])return vector<int>(1, -1);
            index++;
            if (temp->left) {
                if (temp->left->val != voyage[index]) {
                    st.push(temp->left);
                    if (temp->right) st.push(temp->right);
                   
                    res.push_back(temp->val);
                }
                else {
                   
                    if (temp->right)st.push(temp->right);
                    st.push(temp->left);
                }
            }
            else {
                if (temp->right) st.push(temp->right);
            }
            
        }
        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution mysolu;
    vector<int> voyage = { 1,3,4,5,2 };
    vector<int> res = mysolu.flipMatchVoyage(root,voyage);

	return 0;
}