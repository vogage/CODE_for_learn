#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	/*
	int numDecodings(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				if (i < s.size() - 1 && s[i + 1] == '0')return 0;
			}
		}
		return sub_numDecodings(s);
	}
	*/
	/*
	int numDecodings(string s) {

		
		int n = s.size();
		
		if (n == 1) {
			if (s[0] > '0'&&s[0] <= '26')return 1;
			else return 0;
		}
	     

		if (n == 0)return 0;



		int cmp;
		string str = s.substr(0, 2);
		string str2 = s.substr(1);
		cmp = (str[0] - '0') * 10 + str[1] - '0';



		if (s[0] != '0') {
			if (s[1] != '0') {
				if (cmp <= 26) return 1 +numDecodings(s.substr(1));
				else return numDecodings(s.substr(1));
			}
			else {
				return numDecodings(s.substr(2));
			}
		}
		else {
			return 0;
		}
	}
	*/
	/*
	int numDecodings(string s) {
		int n = s.size();
		if (n == 0)return 0;
		vector<int> list(n+1);
		list[n] = 1;
		list[n - 1] = s[n - 1] == '0' ? 0 : 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] == '0')continue;
			else {
				string str = s.substr(i, i + 2);
				int str_to_nums = (str[0] - '0') * 10 + str[1] - '0';
				if (str_to_nums<=26) {
					list[i] = list[i + 1] + list[i + 2];

				}
				else {
					list[i] = list[i + 1];
				}
			}
		}
		return list[0];
	}
	*/
	int numDecodings(string s) {
		return s.empty() ? 0 : numDecodings(0, s);
	}
	int numDecodings(int p, string& s) {
		int n = s.size();
			if (p == n) return 1;
		if (s[p] == '0') return 0;
		int res = numDecodings(p + 1, s);
		if (p < n - 1 && (s[p] == '1' || (s[p] == '2'&& s[p + 1] < '7'))) res += numDecodings(p + 2, s);
		return res;
	}

};

int main() {
	Solution  mysolu;
	string str = "226";
	int ans = mysolu.numDecodings(str);
	return 0;
}