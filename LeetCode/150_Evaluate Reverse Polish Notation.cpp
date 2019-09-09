#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<string>
#include<stdlib.h>
#include<cstdlib>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		int n = tokens.size();
		if (n < 3)return 0;
		if (n == 3) {
			return cal(tokens);
		}
		unordered_set<string> op;
		op.insert("+");
		op.insert("-");
		op.insert("*");
		op.insert("/");
		//search for number of format {num,num,operator}
		return eval(tokens, op);

	}
	int eval(vector<string>& tokens, unordered_set<string>& op) {
		int n = tokens.size();
		if (n < 3)return 0;
		if (n == 3) {
			return cal(tokens);
		}
		int res = 0;
		int i=2;
		unordered_set<string>::iterator it;
		for (; i < tokens.size(); i++) {
			it = op.find(tokens[i]);
			if (it != op.end()) {
				if (op.find(tokens[i - 1]) == op.end() && op.find(tokens[i - 2]) == op.end()) {
					vector<string> temp;
					temp.push_back(tokens[i - 2]);
					temp.push_back(tokens[i - 1]);
					temp.push_back(tokens[i]);
					res = cal(temp);
					break;
				}
			}
		}
		tokens[i] = to_string(res);
		//tokens[i - 1].erase();
		//tokens[i - 2].erase();
		vector<string>::iterator vt = tokens.begin();
		vector<string> v;
		if (i > 2) { 
			vector<string> v1(vt, vt + i - 2); 
			vector<string>v2(vt + i + 1, tokens.end());
			v = v1;
			v.push_back(tokens[i]);
			v.insert(v.end(), v2.begin(), v2.end());
		}
		else {
			vector<string>v2(vt + i + 1, tokens.end());
			v.push_back(tokens[i]);
			v.insert(v.end(), v2.begin(), v2.end());
		}
		return eval(v, op);

	}
	int cal(vector<string>&tokens) {
		int left = atoi(tokens[0].c_str());
		int right = atoi(tokens[1].c_str());
		if (tokens[2] == "+") {
			return left + right;
		}
		else if (tokens[2] == "-") {
			return left - right;
		}
		else if (tokens[2] == "*") {
			return left * right;
		}
		else if (tokens[2] == "/") {
			return left / right;
		}
	}
};


class Solution2 {
	struct ListNode {
		string val;
		ListNode *next;
		ListNode(string x) :val(x), next(NULL) {}
	   
	};
public:
	int evalRPN(vector<string>& tokens) {
		int n = tokens.size();
		if (n == 0)return 0;
		if (n == 1)return atoi(tokens[0].c_str());
		ListNode *head = new ListNode(tokens[0]);
		ListNode *p = new ListNode("en");
		ListNode *b = new ListNode("b");
		b->next = head;
		p->next = head;
		for (int i = 1; i < n; i++) {
			p = p->next;
			p->next = new ListNode(tokens[i]);
		}
		unordered_set<string> op;
		op.insert("+");
		op.insert("-");
		op.insert("*");
		op.insert("/");
		return evallist(head, op);

	}
	int evallist(ListNode* head, unordered_set<string>& op) {
		ListNode* p1 = head;
		ListNode* p2 =p1->next;
		ListNode* p3 =p2->next;
		if (p3->next == NULL) {
			vector<string> temp = { p1->val,p2->val,p3->val };
			return cal(temp);
		}
		while (p3->next != NULL) {
			if (op.find(p3->val) != op.end()) {
				if (op.find(p2->val) == op.end() && op.find(p1->val) == op.end()) {
					vector<string> temp = { p1->val,p2->val,p3->val };
					p1->val = to_string(cal(temp));
					break;
				}
			}
			p1 = p1->next;
			p2 = p2->next;
			p3 = p3->next;
		}
		p1->next = p3->next;
		return evallist(head, op);
	}

	int cal(vector<string>&tokens) {
		int left = atoi(tokens[0].c_str());
		int right = atoi(tokens[1].c_str());
		if (tokens[2] == "+") {
			return left + right;
		}
		else if (tokens[2] == "-") {
			return left - right;
		}
		else if (tokens[2] == "*") {
			return left * right;
		}
		else if (tokens[2] == "/") {
			return left / right;
		}
		return 0;
	}
};

int main() {
	vector<string> input = { "2","1","+","3","*" };
	vector<string> input2 = { "4","13","5","/","+" };
	Solution2 mysolu;
	int res = mysolu.evalRPN(input2);
	return res;
}