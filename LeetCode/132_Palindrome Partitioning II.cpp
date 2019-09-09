#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minCut(string s) {
		if (s.size() == 0)return 0;
		vector<vector<string>> res = getCutString(s);
		int m = s.size() - 1;
		for (int i = 0; i < res.size(); i++) {
			m = min(m, (int)res[i].size() - 1);
		}
		return m;
	}
	vector<vector<string>> getCutString(string s) {
		vector<vector<string> >res;
		vector<string> temp;
		dfs(res, temp, s, 0);
		return res;
	}

	void dfs(vector<vector<string>> &res, vector<string>& temp, string &s, int i) {
		if (i == s.size()) {
			res.push_back(temp);
			return;
		}
		for (int j = i; j < s.size(); j++) {
			if (isPalindrome(s, i, j)) {
				temp.push_back(s.substr(i, j - i + 1));
				dfs(res, temp, s, j + 1);
				temp.pop_back();
			}
		}
	}
	bool isPalindrome(string &s, int i, int j) {
		while (i <= j) {
			if (s[i] != s[j])return false;
			i++;
			j--;
		}
		return true;
	}
};

int main() {
	Solution mysolu;
	string str = "aab";
	int res = mysolu.minCut(str);
	return res;
}