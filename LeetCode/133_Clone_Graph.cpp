#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<stack>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;

	}
};

class Solution {
public:
	Node* cloneGraph(Node* node) {
		if (!node) {
			return NULL;
		}
		
		Node* copy = new Node(node->val, {});
		copies[node] = copy;
		queue<Node*> todo;
		todo.push(node);
		while (!todo.empty()) {
			Node* cur = todo.front();
			todo.pop();
			for (Node* neighbor : cur->neighbors) {
				if (copies.find(neighbor) == copies.end()) {
					copies[neighbor] = new Node(neighbor->val, {});
					todo.push(neighbor);
				}
				copies[cur]->neighbors.push_back(copies[neighbor]);
			}
		}
		return copy;
	}
private:
	unordered_map<Node*, Node*>copies;
};


class Solution2 {
public:
	Node* cloneGraph(Node* node) {
		if (!node) {
			return NULL;
		}
		Node* first =new Node(node->val, {});
		stack<Node*>st;
		st.push(node);
		m[node]=first;
		while (!st.empty()) {
			Node * temp = st.top();
			st.pop();
			for (Node* neibour : temp->neighbors) {
				if (m.find(neibour)== m.end()) {
					m[neibour] = new Node(neibour->val, {});
					st.push(neibour);
				}
				m[temp]->neighbors.push_back(m[neibour]);
			}
		}
		return first;

	}
private:
	unordered_map<Node*, Node*> m;
};

int main() {
	Solution2 mysolu;
	Node *n1 = new Node(1, {});
	Node* n2 = new Node(2, {});
	Node* n3 = new Node(3, {});
	Node* n4 = new Node(4, {});
	vector<Node*> neibour1;
	neibour1.push_back(n2);
	neibour1.push_back(n4);
	n1->neighbors = neibour1;

	vector<Node*> neibour2;
	neibour2.push_back(n1);
	neibour2.push_back(n3);
	n2->neighbors = neibour2;

	vector<Node*> neibour3;
	neibour3.push_back(n4);
	neibour3.push_back(n2);
	n3->neighbors = neibour3;

	vector<Node*>neibour4;
	neibour4.push_back(n1);
	neibour4.push_back(n3);
	n4->neighbors = neibour4;

	Node *res = mysolu.cloneGraph(n1);


	
	return 0;

}