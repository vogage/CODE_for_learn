#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> temp;
		backTrack(res, temp, s,0);
		return res;
	}
	void backTrack(vector<vector<string>>& res, vector<string> &temp,string s, int i) {
		if (i == s.size()) {
			res.push_back(temp);
			return;
		}
		for (int j = i; j < s.size(); j++) {
			if (isPalindrome(s, i, j)) {
			
				
					temp.push_back(s.substr(i, j-i+1));
				
				backTrack(res, temp, s,j+ 1);
				temp.pop_back();
			}
		}
	}

	bool isPalindrome(string str, int l, int r) {
	
		while (l <= r) {
			if (str[l] != str[r])return false;
			l++;
			r--;
		}
		return true;
	}
};

class Solution2 {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		if (s.empty()) return ret;

		vector<string> path;
		dfs(0, s, path, ret);

		return ret;
	}

	void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
		if (index == s.size()) {
			ret.push_back(path);
			return;
		}
		for (int i = index; i < s.size(); ++i) {
			if (isPalindrome(s, index, i)) {
				path.push_back(s.substr(index, i - index + 1));
				dfs(i + 1, s, path, ret);
				path.pop_back();
			}
		}
	}

	bool isPalindrome(const string& s, int start, int end) {
		while (start <= end) {
			if (s[start++] != s[end--])
				return false;
		}
		return true;
	}
};
int main() {
	string input = "aab";
	Solution mysolu;
	vector<vector<string>> res = mysolu.partition(input);
	return 0;
}