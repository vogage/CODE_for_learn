#include<stdio.h>
#include<queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q1;
       // if (root == NULL)return root; 
      

        q1.push(root);
        while (!q1.empty()) {
            queue<Node*> q2;
            Node* temp = q1.front();
            q1.pop();
            if (temp->left) q2.push(temp->left);
            if (temp->right)q2.push(temp->right);
            while (!q1.empty()) {
                temp->next = q1.front();
                q1.pop();
                temp = temp->next;
                if (temp->left) q2.push(temp->left);
                if (temp->right)q2.push(temp->right);
            }
            temp->next = NULL;
            q1 = q2;
        }
        return root;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Solution mysolu;
    Node* res = mysolu.connect(root);
    return 0;
}