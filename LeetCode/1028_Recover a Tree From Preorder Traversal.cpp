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
    TreeNode* recoverFromPreorder(string traversal) {
        
        vector<pair<int, int>> vec_pair = change_str_vecPair(traversal);
        stack<pair<TreeNode*, int>> st_tree;
        TreeNode* root = new TreeNode(vec_pair[0].first);
        pair<TreeNode*, int> root_pair(root, vec_pair[0].second);
        st_tree.push(root_pair);
        for (int i = 1; i < vec_pair.size(); i++) {
            if (vec_pair[i].second == st_tree.top().second+1) {
                st_tree.top().first->left = new TreeNode(vec_pair[i].first);
                st_tree.push(pair<TreeNode*, int>(st_tree.top().first->left, vec_pair[i].second));
            }
            else {
                while (st_tree.top().second != vec_pair[i].second - 1) {
                    st_tree.pop();
                }
                st_tree.top().first->right = new TreeNode(vec_pair[i].first);
                st_tree.push(pair<TreeNode*, int>(st_tree.top().first->right, vec_pair[i].second));
            }
        }
        return root;
    }
private:
    vector<pair<int, int>> change_str_vecPair(string traversal) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < traversal.size();) {
            int count = 0;
            pair<int, int> v_p;
            while (traversal[i] == '-'&&i<traversal.size()) {
                count++;
                i++;
            }
            int j = i;
            

            while (traversal[i] != '-' && i < traversal.size()) {
                i++;
            }
            v_p.first = stoi(traversal.substr(j, i - j + 1));
            v_p.second = count;
            vec.push_back(v_p);
          }
        return vec;
    }
};
int main() {
    Solution mysolu;
    string traversal = "1-2--3--4-5--6--7";
    string traversal1 = "1-2--3---4-5--6---7";
    string traversal2 = "1-401--349---90--88";
    TreeNode* res = mysolu.recoverFromPreorder(traversal2);
    return 0;
}