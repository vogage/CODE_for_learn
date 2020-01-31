#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> temp(k, 0);
		for (int i = 0; i < k; i++) {
			temp[i] = nums[i];
		}
		sort(temp.begin(), temp.end(),greater<int>());
		for (int i = k; i < nums.size(); i++) {
			if (temp.back() < nums[i]) {
				temp.back() = nums[i];
				sort(temp.begin(), temp.end(), greater<int>());
			}
		}
		return temp.back();
	}
};

int main() {
	Solution mysolu;
	vector<int> input0 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
	int res = mysolu.findKthLargest(input0, 4);

	return 0;

}