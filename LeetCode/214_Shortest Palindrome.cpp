#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

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

//class Solution3 {
//	public String shortestPalindrome(String s) {
//		String temp = s + "#" + new StringBuilder(s).reverse().toString();
//		int[] table = getTable(temp);
//
//		//get the maximum palin part in s starts from 0
//		return new StringBuilder(s.substring(table[table.length - 1])).reverse().toString() + s;
//	}
//
//	public int[] getTable(String s) {
//		//get lookup table
//		int[] table = new int[s.length()];
//
//		//pointer that points to matched char in prefix part
//
//		int index = 0;
//		//skip index 0, we will not match a string with itself
//		for (int i = 1; i < s.length(); i++) {
//			if (s.charAt(index) == s.charAt(i)) {
//				//we can extend match in prefix and postfix
//				table[i] = table[i - 1] + 1;
//				index++;
//			}
//			else {
//				//match failed, we try to match a shorter substring
//
//				//by assigning index to table[i-1], we will shorten the match string length, and jump to the 
//				//prefix part that we used to match postfix ended at i - 1
//				index = table[i - 1];
//
//				while (index > 0 && s.charAt(index) != s.charAt(i)) {
//					//we will try to shorten the match string length until we revert to the beginning of match (index 1)
//					index = table[index - 1];
//				}
//
//				//when we are here may either found a match char or we reach the boundary and still no luck
//				//so we need check char match
//				if (s.charAt(index) == s.charAt(i)) {
//					//if match, then extend one char 
//					index++;
//				}
//
//				table[i] = index;
//			}
//
//		}
//
//		return table;
//	}
//
//
//};

class Solution3 {
public:
	string shortestPalindrome(string s) {
		string s_rev = s;
		reverse(s_rev.begin(), s_rev.end());
		vector<int> table;
		string input = s + "#" + s_rev;
		table = KMP(input);
		return  s_rev.substr(0,s_rev.size() - table.back())+s;

	}
	vector<int> KMP(string input) {
		int index = 0;
		vector<int> table(input.size(), 0);
		for (int i = 1; i < input.size(); i++) {
			if (input[i] == input[index]) {
				table[i] = table[i - 1] + 1;
				index++;
			}
			else {
				index = table[i - 1];
				while (index > 0 && input[index] != input[i]) {
					index = table[index - 1];
				}

				if (input[index] == input[i]) {
					index++;
				}
				table[i] = index;
			}
		}
		return table;
	}

	void kmp_pattern_search(string str, string word) {
		vector<int> table = KMP(word);
		int index = 0;
		int i = 0;
		while(i<str.size()){
			if (str[i] == word[index]) {
				index++;
				i++;
			
				if (index == word.size()) {
					cout << "find" << i << endl;
					index = table[index - 1];
				}
			}
			else {
				if (index == 0) i++;
				else {
					index = table[index - 1];
				}
			}
				
		}
	}


};

int main() { 
	Solution3 mysolu;

	string input = "aacecaaa";
	string input2 = "abcd";
	string input3 = "a";
	string res = mysolu.shortestPalindrome(input);

	string W = "acabacacd";
	string T = "acfacabacabacacdk";
	mysolu.kmp_pattern_search(T, W);
	return 0;
}