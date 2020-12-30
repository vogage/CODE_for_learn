#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int strangePrinter(string s) {
		int n = s.size();
		if (n <= 1) return n;
		char head = s[0];
		//int res = 1;
		int temp1 =1;
		int temp2 = 1;
		for (int i = 1; i < n; i++) {
			if (s[i] != head) {
				int start = i; i++;
				while (i<n&&s[i] != head)i++;
				int end = i;
			    temp1 =temp1 + strangePrinter(s.substr(start, end - start ));
			}
		}
		
		for (int i = 1; i < n; i++) {
			if (s[i] != head) {
				int start = i;
				temp2 =temp2 + strangePrinter(s.substr(start));
				break;
			}
		}
		return  min(temp1,temp2);

	}
};


int main() {
	Solution mysolu;
	string str = "aaabbb";
	string str2 = "aabaabaa";
	string str3 = "ababc";
	string str4 = "tbgtgb";                                                                                 
	int res = mysolu.strangePrinter(str4);
	return 0;
}