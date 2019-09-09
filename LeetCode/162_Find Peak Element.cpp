#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>&nums) {
		vector<int> dif;
		dif.push_back(1);
		if (nums.size() == 1)return nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dif.push_back(nums[i] - nums[i - 1]);
		}
		dif.push_back(-1);
		for (int j = 1; j < dif.size();j++) {
			if (dif[j - 1] > 0 && dif[j] < 0)return nums[j - 1];
		}
	}
};

int main() {
	vector<int> input = { 1,2,3,1 };
	Solution mysolu;
	int res = mysolu.findPeakElement(input);
	return 0;
}