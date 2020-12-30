#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		int count_left = 0;
		int count_right = 0;
		vector<string> res;
		res.push_back(s);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				count_left++;
			}
			else if (s[i] == ')') {
				count_right++;
			}
			else {
				continue;
			}
			if (count_right > count_left) {
				res.pop_back();
				deal(res, s, i); 
				count_right=count_right - 1;
			}
		}
		if (count_left > count_right) {
			
			deal2(res);
		}
		/*if (res.size() == 0)res.push_back("");*/
		
		return res;
	}
	void deal(vector<string>& res,string &s, int end) {
		/*string s1 = s.substr(0, end);
		string s2 = s.substr(end);*/
		for (int i = 0; i < end; i++) {
			if (s[i] == ')') {
				string temp = s.substr(0, i) + s.substr(i + 1);
				res.push_back(temp);
				continue;
			}
		}
	}
	void deal2(vector<string> & res) {
		vector<string> res2;
		for (auto str : res) {
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == ')') {
					string temp = str.substr(0, i) + str.substr(i + 1);
					res2.push_back(temp);
				}
			}
		}
		res = res2;
	}
};

class Solution2 {
public:
	vector<string> removeInvalidParentheses(string s) {
		pair<char, char> p('(', ')');
		vector<string> res;
		remove(s, res, 0, 0, p);
		return res;
	}
	void remove(string s, vector<string>& res, int i_last, int j_last, pair<char, char>& p) {
		int count_left = 0;
		int count_right = 0;

		for (int i = i_last; i < s.size(); i++) {
			if (s[i] == p.first) count_left++;
			if (s[i] == p.second)count_right++;
			if (count_left >= count_right)continue;
			for (int j = j_last; j <= i; j++) {
				if (s[j] == p.second&&(j==j_last||s[j] != s[j - 1])) {
					remove(s.substr(0, j) + s.substr(j + 1), res, i, j, p);
				}
			}
			return;
		}
		string restr = s;
		reverse(restr.begin(), restr.end());
		if (p.first == '(') {
			//left is down ,do the right
			pair<char, char> resp(')', '(');
			remove(restr, res, 0, 0, resp);
		}
		else {
			//reverse twice left and right all down
			res.push_back(restr);
		}
	
	}

};

class Solution3 {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		queue<string> que;
		unordered_set<string> restrset;
		que.push(s);
		restrset.insert(s);
		bool found = false;
		while (!que.empty()) {
			string temp = que.front();
			que.pop();
			if (isValid(temp)) {
				res.push_back(temp);
				found = true;
			}
			if (found) continue;
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == '(' || temp[i] == ')') {
					string temp2 = temp.substr(0, i) + temp.substr(i + 1);
					if (restrset.find(temp2) == restrset.end()) {
						que.push(temp2);
						restrset.insert(temp2);
					}
				}
			}

		}
		return res;
	}

	bool isValid(string str) {
		int count_left = 0;
		int count_right = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(')count_left++;
			if (str[i] == ')')count_right++;
			if (count_right > count_left) return false;
		}
		return count_left == count_right;
	}
};
int main() {
	Solution3 mysolu;
	string input = "()())()";
	string input2 = "n";
	string input3 = ")(";
	vector<string> res = mysolu.removeInvalidParentheses(input);
	return 0;
}