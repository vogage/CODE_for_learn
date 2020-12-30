#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		unordered_map<char, int> c_map;
		for (int i = 0; i < secret.size(); i++) {
			c_map[secret[i]]++;
		}
		int count_same_char = 0;
		int count_same_all = 0;
		for (int i = 0; i < guess.size(); i++) {
			if (c_map[guess[i]]) {
				count_same_char++;
				c_map[guess[i]]--;
			}
			if (guess[i] == secret[i]) count_same_all++;
		}
		
		return to_string(count_same_all) + "A" + to_string(count_same_char - count_same_all) + "B";
	}
}; 

int main() {
	Solution mysolu;

	string secret = "1807";
	string guess = "7810";
	string res = mysolu.getHint(secret, guess);

	return 0;
}