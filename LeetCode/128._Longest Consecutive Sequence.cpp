#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>&nums) {
		sort(nums.begin(), nums.end());
		vector<pair<int, int>> v;
		if (nums.size() == 0)return 0;
		v.push_back(pair<int, int>(nums[0], nums[0]));
		for (int i = 1; i < nums.size(); i++) {
			bool isfind = false;
			for (int j = 0; j < v.size(); j++) {
				if (nums[i] == v[j].first - 1) {
					isfind = true;
					v[j].first = v[j].first - 1;
					break;	//???
				}
				if (nums[i] == v[j].second + 1) {
					isfind = true;
					v[j].second = v[j].second + 1;
				}
			}
			if (!isfind) {
				v.push_back(pair<int, int>(nums[i], nums[i]));
			}
		}
		int res = 0;
		for (int i = 0; i < v.size(); i++) {
			res = max(res, v[i].second - v[i].first + 1);
		}
		return res;
	}
};

class Solution2 {
public:
	int longestConsecutive(vector<int>&nums) {
		unordered_map<int, int> m;
		int res = 0;
		//只需要更新边界的两个值就行了，不需要更新该连续序列内每个元素对应的值
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(nums[i]) == m.end()) {
				int left = m.find(nums[i]-1) == m.end() ? 0 : m[nums[i]-1];
				int right = m.find(nums[i]+1) == m.end() ? 0 : m[nums[i]+1];
				int boundary = left + right + 1;
				m[nums[i] - left] = boundary;
				m[nums[i] + right] = boundary;
				m[nums[i]] = boundary;
				res = max(res, boundary);
			}
		}
		return res;
	}
};

int main() {
	vector<int> nums = { 4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3 };
	Solution2 mysolu;
	int res = mysolu.longestConsecutive(nums);
	return res;
}