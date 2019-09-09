#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<string>

using namespace std;
 
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;

	}
};

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)return root;
		//ÖÐÐò±éÀú
		vector<pair<Node*, int>> v;
		v = midtraverse(root);
		for (int i = 0; i < v.size()-1; i++) {
			if (v[i].second == v[i + 1].second) v[i].first->next = v[i + 1].first;
		}
		return root;
	}

	vector<pair<Node*,int>> midtraverse(Node* root) {
		vector<pair<Node*,int>> res;
		queue<Node*> q;
		queue<pair<Node*, int>> q2;
		pair<Node*, int> temp (root, 0);
		
		q2.push(temp);
		while (!q2.empty()) {
			temp = q2.front();
			q2.pop();
			cout << temp.first->val << endl;
			res.push_back(temp);
			if (temp.first->left) q2.push(pair<Node*,int>(temp.first->left,temp.second+1));
			if (temp.first->right) q2.push(pair<Node*,int>(temp.first->right,temp.second+1));
		}
		return res;
		
	}
};

class Solution2 {
public:
	Node* connect(Node* root) {
		
		vo_connect(root);
		return root;
	}
	void vo_connect(Node* root) {
		if (root == NULL)return;
		if (root->left) {
			root->left->next = root->right;
			if (root->next) {
				root->right->next = root->next->left;
			}
		}
		
		vo_connect(root->left);
		vo_connect(root->right);
	}
};

class solution3 {
	Node* connect(Node* root) {
		vo_connect(root);
		return root;
	}
	void vo_connect(Node* root) {
		if (root == NULL)return;
		Node* pre = root;
		Node* cur;
		while (pre->left) {
			cur = pre;
			while (cur) {
				cur->left->next = cur->right;
				if (cur->next) cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}
	}
};

int main() {
	Node *root = new Node(1,NULL,NULL,NULL);
	root->left= new Node(2, NULL, NULL, NULL);
	root->right= new Node(3, NULL, NULL, NULL);
	root->left->left= new Node(4, NULL, NULL, NULL);
	root->left->right= new Node(5, NULL, NULL, NULL);
	root->right->left= new Node(6, NULL, NULL, NULL);
	root->right->right= new Node(7, NULL, NULL, NULL);
	Solution mysolu2;
	Node* res = mysolu2.connect(root);
	return 0;

}