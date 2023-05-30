#include<stdio.h>
#include<string>
#include<math.h>
#include<queue>
#include<sstream>
using namespace std;




 struct TreeNode {
     int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        if (!root) return res;
        queue<TreeNode*> TN;
        TN.push(root);
        while (!TN.empty()) {
            TreeNode* top = TN.front();
            TN.pop();
            if (top == nullptr) {
                res += "n"; continue;
            }
            else {
                res += to_string(top->val);
            }
            TN.push(top->left);
            TN.push(top->right);
            
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0)return nullptr;
        queue<TreeNode*> TN;
        TreeNode* root = new TreeNode(data[0] - '0');

        TN.push(root);
        
        int i = 1;
        while(i<data.size()&&!TN.empty()){
            TreeNode* top = TN.front();
            TN.pop();
            top->left = data[i] == 'n' ? nullptr : new TreeNode(data[i] - '0');
            if (top->left) TN.push(top->left);
            i++;
            if (i == data.size()) break;
            top->right = data[i] == 'n' ? nullptr : new TreeNode(data[i] - '0');
            if (top->right) TN.push(top->right);
            i++;
        }

        return root;
    }


};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

class Codec2 {
public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string res = "";

        queue<TreeNode*> q;
        q.push(root);

        // insert root -> val
        res += to_string(root->val) + " ";

        // BFS
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();

            // insert root -> left
            if (cur->left)
                q.push(cur->left), res += to_string(cur->left->val) + " ";

            // insert root -> right
            if (cur->right)
                q.push(cur->right), res += to_string(cur->right->val) + " ";
        }

        return res;
    }

    TreeNode* insertToBST(TreeNode* root, int data)
    {
        if (!root) return new TreeNode(data);

        TreeNode* cur = root;
        while (1)
        {
            // if data is lesser than cur
            // then go left
            if (cur->val > data)
            {
                if (cur->left) cur = cur->left;
                else
                {
                    cur->left = new TreeNode(data);
                    break;
                }
            }
            // if data is greater than cur
            else
            {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new TreeNode(data);
                    break;
                }
            }
        }

        return root;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        TreeNode* root = NULL;

        // using stringstream, we can easily get the node values
        // once we get the value insert into bst
        stringstream ss(data);
        string str;

        while (ss >> str)
        {
            // update in root
            root = insertToBST(root, stoi(str));

        }


        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);

    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    root->left->left->left = new TreeNode(1);


     Codec2* ser = new Codec2();
     Codec2* deser = new Codec2();
     string tree = ser->serialize(root);
     TreeNode* ans = deser->deserialize(tree);
     return 0;
}