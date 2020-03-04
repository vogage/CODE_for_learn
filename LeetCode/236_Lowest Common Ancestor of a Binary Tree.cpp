#include<stdio.h>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	stack<TreeNode*> st;
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*> tempst;
		searchp(root, p, tempst);
		unordered_set<TreeNode*> set;
		while (!st.empty()) {
			TreeNode* temp = st.top();
			st.pop();
			if (searchq(temp, q,set)) return temp;
		}
		return nullptr;
	}
	void searchp(TreeNode* root, TreeNode* p, stack<TreeNode*> tempst) {
		if (!root)return;		
		tempst.push(root);
		if (root->val == p->val) {
			st = tempst;
			return;
		}
		if (st.empty()) {
			searchp(root->left, p, tempst);
			searchp(root->right, p, tempst);
		}
		tempst.pop();
	}
	bool searchq(TreeNode* temp, TreeNode* q,unordered_set<TreeNode*>& set) {
		stack<TreeNode*> sta;
		sta.push(temp);
		while (!sta.empty()) {
			TreeNode* tp = sta.top();
			set.insert(tp);
			sta.pop();
			if (tp->val == q->val) return true;
			//if (tp->left)sta.push(tp->left);
			//if (tp->right)sta.push(tp->right);
			if (tp->left&&set.find(tp->left) == set.end())sta.push(tp->left);
			if (tp->right&&set.find(tp->right)== set.end())sta.push(tp->right);
		}
		return false;
	}
};


class Solution2 {
	vector<TreeNode*> que_p;
	vector<TreeNode*> que_q;

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> temp_que_p;
		vector<TreeNode*> temp_que_q;
		searchp(root, p, q, temp_que_p, temp_que_q);
		int i = 0;
		for (; i < que_p.size() && i < que_q.size(); i++) {
			if (que_p[i] != que_q[i])break;
		}
		return i==0?nullptr:que_p[i-1];

	}
	void searchp(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*> temp_que_p, vector<TreeNode*> temp_que_q) {		
		if (que_p.empty())
		{
			temp_que_p.push_back(root);
			if (root->val == p->val) {
				que_p = temp_que_p;
			}
		}
		if (que_q.empty()) {
			temp_que_q.push_back(root);
			if (root->val == q->val) {
				que_q = temp_que_q;
			}
		}
		if (!que_q.empty() && !que_p.empty()) return;
		if (que_q.empty()||que_p.empty()) {
			if(root->left)searchp(root->left, p,q,temp_que_p,temp_que_q);
			if(root->right)searchp(root->right, p, q, temp_que_p, temp_que_q);
		}
		temp_que_p.pop_back();
		temp_que_q.pop_back();
	}

};
int main() {
	Solution2 mysolu;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(6);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(4);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(8);
	
	TreeNode *p = new TreeNode(5);
	TreeNode *q = new TreeNode(1);

	TreeNode *root1 = new TreeNode(1);
	root1->left = new TreeNode(2);

	TreeNode *p1 = new TreeNode(1);
	TreeNode* q1 = new TreeNode(2);

	TreeNode * res = mysolu.lowestCommonAncestor(root, p, q);

	return 0;
}