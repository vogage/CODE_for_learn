#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	Node* next;
	int val;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		left = _left;
		right = _right;
		next = _next;
		val = _val;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		vo_connect(root);
		return root;
	}
	void vo_connect(Node* root) {
		if (root == NULL)return;
		Node* pre = root;
		Node* cur = nullptr;
		if (pre->left) {
			if (pre->right) pre->left->next = pre->right;
			else {
				cur = pre->next;
				while (cur) {
					if (cur->left) {
						pre->next = cur->left; break;
					}
					else if (cur->right) {
						pre->next = cur->right; break;
					}
					else cur = cur->next;
				}
				
			}
		}
		if (pre->right) {
			cur = pre->next;
			while (cur) {
				if (cur->left) {
					pre->right->next= cur->left; break;
				}
				else if (cur->right) {
					pre->right->next = cur->right; break;
				}
				else cur = cur->next;
			}
		}
		vo_connect(root->left);
		vo_connect(root->right);

	}
};

int main() {


	Node *root = new Node(1, NULL, NULL, NULL);
	root->left = new Node(2, NULL, NULL, NULL);
	
	root->right = new Node(3, NULL, NULL, NULL);
	root->right = new Node(5, NULL, NULL, NULL);
	root->left->left = new Node(4, NULL, NULL, NULL);
	Solution mysolu;
	Node* res = mysolu.connect(root);
	return 0;
}