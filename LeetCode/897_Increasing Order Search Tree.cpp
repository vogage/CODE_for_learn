#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution {
public:
	TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while (root->left) {
            st.push(root->left);
            root = root->left;
        }
        TreeNode* nt = root;
        st.pop();

        while (!st.empty()||nt->right) {
            if (nt->right) {
                nt->right = increasingBST(nt->right);
                nt->left = NULL;
                nt = nt->right;
                while (nt->right) nt = nt->right;
                continue;
            }
            if (nt) {
                nt->right = st.top();
               
                st.pop();  
                nt = nt->right;
                nt->left = NULL;
            }
          

            
        }
        return root;
    }
};

int main() {
    Solution mysolu;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    
    root->right = new TreeNode(6);
    
    root->right->right = new TreeNode(8);
    root->right->right->left= new TreeNode(7);
    root->right->right->right = new TreeNode(9);


    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->right->left = new TreeNode(3);


    TreeNode* res = mysolu.increasingBST(root);
    return 0;
}