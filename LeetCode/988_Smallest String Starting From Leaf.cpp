#include<string>
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
    string smallestFromLeaf(TreeNode* root) {
        vector<int> res;
        if (!root)return "";
        stack<TreeNode*> st_tree;
        vector<int> temp;
        dfs(root, temp, res);
        reverse(res.begin(), res.end());
        string output = "";
        for (int i = 0; i < res.size(); i++) {
            output += res[i] + 'a';
        }
        return output;
    }

    string smallestFromLeaf2(TreeNode* r) {
        if (r == nullptr) return "|";
        auto s = string(1, 'a' + r->val);
        return r->left == r->right ? s : min(smallestFromLeaf2(r->left) + s, smallestFromLeaf2(r->right) + s);
    }

private:
    void dfs(TreeNode* root, vector<int> temp, vector<int>& res) {
        temp.push_back(root->val);
        if (!root->left&&!root->right) {
            if (res.size() == 0) res = temp;
            if (cmp(temp, res)) {
                res = temp;
            }
            return;
        }
        
        if(root->left)dfs(root->left, temp, res);
        if(root->right)dfs(root->right, temp, res);
    }

    bool cmp(vector<int>& v1, vector<int>& v2) {
        int total= min(v1.size(), v2.size());
        int n = v1.size();
        int m = v2.size();
        for (int i = 1; i <= total; i++) {

            if (v1[n-i] < v2[m-i])return true;
            if (v1[n-i] > v2[m-i])return false;
        }
        if (v1.size() < v2.size())return true;
        else return false;
    }
};
int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);

    TreeNode* root1 = new TreeNode(25);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(2);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(1);
    root2->left->right = new TreeNode(1);
    root2->left->right->left = new TreeNode(0);
    root2->right->left = new TreeNode(0);

    string res = mysolu.smallestFromLeaf2(root);
	return 0;
}