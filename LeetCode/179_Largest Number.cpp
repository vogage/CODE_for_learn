#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string &s1, string &s2) {
	return s1 + s2 > s2 + s1;
}
class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string res = "";
		vector<string> v;
		for (int i = 0; i < nums.size(); i++) {
			v.push_back(to_string(nums[i]));
		}
		sort(v.begin(), v.end(), cmp);
		for (auto s : v) {
			res += s;
		}
		while (res[0] == '0'&&res.size() > 1) {
			res = res.substr(1, res.size() - 1);
		}
		return res;
	}
};

int main() {
	vector<int> input = { 3,30,34,5,9 };
	vector<int> input2 = { 0,0 };
	Solution mysolu;
	string res = mysolu.largestNumber(input2);
	return 0;
}