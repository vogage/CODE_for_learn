#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, int target) {
		vector<string> res;
		string str="";
		int temp = 0;
		// num=123 
		//target=6
		//["1+2+3", "1*2*3"] 
	
	}
	void dp(vector<string>& res, string str, string num, int target) {

	}
};


int main() {
	string num = "123";
	int target = 6;
	Solution mysolu;
	vector<string> res = mysolu.addOperators(num, target);
	return 0;
}