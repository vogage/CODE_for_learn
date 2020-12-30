#include<stdio.h>
#include<vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


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
    TreeNode* sortedListToBST(ListNode* head) {
        //convert to vector
        ListNode* p = head;
        vector<int> nodes;
        while (p) {
            nodes.push_back(p->val);
            p = p->next;
        }
        return dfs(nodes, 0, nodes.size() - 1);
    }
    TreeNode* dfs(vector<int>& nodes, int begin, int end) {
        if (begin > end)return nullptr;
        int mid = (begin + end + 1) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = dfs(nodes, begin, mid - 1);
        root->right = dfs(nodes, mid + 1, end);
        return root;
    }

};

int main() {
    Solution mysolu;
    ListNode* p1 = new ListNode(-10);
    p1->next = new ListNode(-3);
    p1->next->next = new ListNode(0);
    p1->next->next->next = new ListNode(5);
    p1->next->next->next->next = new ListNode(9);
    TreeNode* res = mysolu.sortedListToBST(p1);
    return 0;
}