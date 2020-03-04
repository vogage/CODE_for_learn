#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		unordered_map<int, int> m;
		vector<int> res;
		if (nums.size() == 0)return res;
		int n = nums.size() / 3;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
		}
		for (auto p : m) {
			if (p.second > n) res.push_back(p.first);
		}
		return res;
	}
};



int main() {
	Solution mysolu;
	vector<int> input = { 1, 1, 1, 3, 3, 2, 2, 2 };
	vector<int> res = mysolu.majorityElement(input);
	return 0;
}