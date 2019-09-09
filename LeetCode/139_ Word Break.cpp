#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		bool res = false;
		BFS(s, wordDict, res);
		return res;
	}
	void BFS(string s, vector<string>&wordDict, bool &res) {
		if (s == "") {
			res = true;
			return;
		}
		int n = s.size();
		for (string str : wordDict) {
			if (str.size() <= n) {
				string temp = s.substr(0,str.size());
				string next_s = s.substr(str.size());
				if (temp == str) BFS(next_s, wordDict, res);
			}
		}
		return;
	}
};

class Solution2 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (dp[j]) {
					string temp = s.substr(j, i - j);
					if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end())
					{	
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[s.size()];
	}
	
};

int main() {
	string s = "aaaaaaa";
	vector<string> wordDict = { "aaaa","aaa"};
	Solution2 mysolu;
	bool res = mysolu.wordBreak(s, wordDict);
	return 0;
}