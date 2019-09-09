#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;





class Solution {
public:
	vector<string> wordBreak(string s, vector<string> &wordDict) {
		vector<string> res;
		string temp;
		vector<vector<string>> dp(s.size()+1, vector<string>());
		dp[0] = vector<string>{ "" };
		
		for (int i = 1; i < s.size()+1; i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (dp[j].size() != 0) {
					string temp = s.substr(j, i - j);
					if (find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()) {
						for (int k = 0; k < dp[j].size(); k++) {
							string new_temp = dp[j][k] +" "+temp;
							dp[i].push_back(new_temp);
						}
					}
				}
			}
		}
		res = dp[s.size()];
		for (int i = 0; i < res.size(); i++) {
			res[i] = res[i].substr(1, res[i].size());
		}
		
		return res;
	}

	void BFS(vector<string>&res, string& temp,string s, vector<string>& wordDict) {
		if (s == "") {
			res.push_back(temp.substr(0,temp.size()-1));
			temp = "";
			return;
		}
		for (int i = 1; i <= s.size(); i++) {
			string segment = s.substr(0,i);
			if (find(wordDict.begin(), wordDict.end(), segment) != wordDict.end()) {
				string temp2 = temp;
				temp = temp + segment + " ";
				BFS(res, temp, s.substr(i), wordDict);
				temp = temp2;
			}
		}
	}
};

class Solution3 {
public:

	bool is_same_configuration(unordered_map<string, int>&m1, unordered_map<string, int>&m2) {
		for (pair<string,int> str : m1) {
			if (m2.find(str.first) != m2.end()) {
				if (str.second != m2[str.first])return false;
			}
			else {
				return false;
			}
		}
		return true;
	}
	vector<string> wordBreak(string s, vector<string> &wordDict) {
		vector<string> res;
		string temp;
		vector<vector<string>> dp(s.size() + 1, vector<string>());
		unordered_map<string, vector<unordered_map<string,int>>> map;
		dp[0] = { "" };

		
	
		
		for (int i = 1; i < s.size() + 1; i++) {
			
	
			for (int j = i - 1; j >= 0; j--) {
				
					string temp = s.substr(j, i - j);
					string prev = s.substr(0, j);
					vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), temp);
					
					if (it != wordDict.end()) {
						unordered_map<string, int> map_temp;
						vector<unordered_map<string, int>> vector_temp;
						if (prev.size() == 0) {
							map_temp[temp] = 1;
							vector_temp.push_back(map_temp);
							map[temp] = vector_temp;
						}

						for (unordered_map<string,int>map_str : map[prev]) {
							
							string push_str = prev + temp;
							map_temp = map_str;
							map_temp[temp]++;
							if (map.find(push_str) == map.end()) map[push_str].push_back(map_temp);
							for (unordered_map<string, int>map_str2 : map[push_str]) {
								if (!is_same_configuration(map_temp, map_str2)) {
									map[push_str].push_back(map_temp);
								}
							}
						}
					
						
					}
				
			}
			





		}
		
		
		return res;
	}

};



class Solution2 {

	unordered_map<string, vector<string>>m;

	vector<string> combine(string word, vector<string> prev) {
		for (int i = 0; i < prev.size(); i++) {
			prev[i] += " " + word;
		}
		return prev;
	}

public:
	vector<string> wordBreak(string s, vector<string>& dict) {
		if (m.count(s))return m[s];
		vector<string> result;
		if (find(dict.begin(), dict.end(), s) != dict.end()) {
			result.push_back(s);
		}
		for (int i = 1; i < s.size(); i++) {
			string word = s.substr(i);
			if (find(dict.begin(), dict.end(), word) != dict.end()) {
				string rem = s.substr(0, i);
				vector<string>prev = combine(word, wordBreak(rem, dict));
				result.insert(result.end(), prev.begin(), prev.end());
			}
		}
		m[s] = result;
		return result;
	}
};
int main() {
	string s = "catsanddog";
	vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
	string s1 = "aaaaaaaaaaaaaaaaaaa";
	vector<string> wordDict2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
	Solution3 mysolu;
	vector<string> res = mysolu.wordBreak(s1, wordDict2);
	return 0;

}