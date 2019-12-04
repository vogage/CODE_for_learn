#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		//Write a function to find all the 10-letter-long sequences (substrings)
		//that occur more than once in a DNA molecule.
		vector<string> res;
		if (s.size() < 10) return res;
		unordered_map<string, int> m;
		for (int i = 0; i <=s.size() - 10; i++) {
			unordered_map<string, int>::iterator it= m.end();
			string str = s.substr(i, 10);
			if (m.find(str) == it) {
				m[str] = i;
			}
			else {
				if (m[str] < i + 10) { 
					vector<string> ::iterator it2 = find(res.begin(), res.end(), str);
					if (it2 == res.end())res.push_back(str);
				}

			}
		}
		return res;
	}
};

int main() {
	string input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	string input2 = "AAAAAAAAAAAA";
	Solution mysolu;
	vector<string> res = mysolu.findRepeatedDnaSequences(input2);


	return 0;
}