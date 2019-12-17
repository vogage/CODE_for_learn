#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	string shortestPalindrome(string s) {
		string s2 = s;
		reverse(s2.begin(), s2.end());
		int i = 0;
		for (; i < s.size(); i++) {
			string temp1 = s.substr(0,s.size()-i);
			string temp2 = s2.substr(i,s2.size()- i);
			if (temp1 == temp2)break;
		}
		return s2.substr(0, i)+s;

	}
};

class Solution2 {
public:
	string shortestPalindrome(string s) {
		int i = 0;
		for (; i < s.size(); i++) {
			if (compare(s, i))break;
		}
		string temp= s.substr(s.size() - i+1, i-1);
		reverse(temp.begin(), temp.end());
		return temp + s;
	}
	bool compare(string& s, int i) {
		for (int j = 0; j < s.size() - i; j++) {
			if (s[j] != s[s.size() - i - j])return false;
		}
		return true;
	}
};
int main() { 
	Solution2 mysolu;

	string input = "aacecaaa";
	string input2 = "abcd";
	string input3 = "a";
	string res = mysolu.shortestPalindrome(input3);
	return 0;
}