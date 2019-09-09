#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
	string reverseWords(string s) {
		vector<string> res;
		string temp="";
		for (char c : s) {
			if (c == ' ') {
				if (temp.size() == 0) continue;
				else {
					res.push_back(temp);
					temp.clear(); continue;
				}
			}
			temp = temp + c;
		}
		if (temp.size())res.push_back(temp);
		if (res.size() == 0)return "";
		if (res.size() == 1)return res[0];
		reverse(res.begin(), res.end());
		string ans="";
		for (string str : res) {
			ans += str;
			ans += " ";
		}
		return ans.substr(0, ans.size() - 1);
	}
};

int main() {
	string input = "the sky is blue";
	Solution mysolu;
	string res = mysolu.reverseWords(input);
	return 0;
}