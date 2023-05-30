#include<unordered_set>
#include<unordered_map>
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
 
struct Node {
    int row;
    int col;
    int val;
    int sort_index;
};

class Solution {
public:
    //    Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

    //    For each node at position(row, col), 
    //    its leftand right children will be at positions(row + 1, col - 1) 
    //    and (row + 1, col + 1) respectively.The root of the tree is at(0, 0).

    //    The vertical order traversal of a binary tree is a list of top - to - bottom orderings 
    //    for each column index starting from the leftmost columnand ending on the rightmost column.
    //    There may be multiple nodes in the same rowand same column.In such a case, 
    //    sort these nodes by their values.

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)return res;
          dfs(root,0,0);
          sort(tree_nodes.begin(), tree_nodes.end(), cmp);
          Node before_node = tree_nodes[0];
          res.push_back(vector<int>(1, before_node.val));
          int index = 0;
          for (int i = 1; i < tree_nodes.size(); i++) {
              if (tree_nodes[i].col == before_node.col) {
                  res[index].push_back(tree_nodes[i].val);
              }
              else {
                  vector<int> new_col_node(1, tree_nodes[i].val);
                  before_node = tree_nodes[i];
                  index++;
                  res.push_back(new_col_node);
              }
          }
          
          return res;

    }

    void dfs(TreeNode* root,int col,int row) {
        if (!root)return;
        Node temp;
        temp.col = col;
        temp.row = row;
        temp.val = root->val;
        temp.sort_index = col * 1000 * 1000 + row * 1000 + root->val;
        tree_nodes.push_back(temp);
        if (root->left) dfs(root->left, col - 1,row+1);
        if (root->right)dfs(root->right, col + 1,row+1);
        return;
    }

private:
    vector<Node> tree_nodes;
private:
    static bool cmp(Node& p1, Node& p2) {
        return p1.sort_index < p2.sort_index;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(2);
    root1->right = new TreeNode(4);
    root1->right->left = new TreeNode(2);
    Solution mysolu;
    vector<vector<int>> res = mysolu.verticalTraversal(root);
    return 0;
}