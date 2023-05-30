#include<vector>

using namespace std;

//An integer array is called arithmetic if it consists of at least three elements and 
//if the difference between any two consecutive elements is the same.
//
//For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
//Given an integer array nums, return the number of arithmetic subarrays of nums.
//
//A subarray is a contiguous subsequence of the array.

//Input: nums = [1, 2, 3, 4]
//Output : 3
//Explanation : We have 3 arithmetic slices in nums : [1, 2, 3] , [2, 3, 4] and [1, 2, 3, 4] itself.

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums) {
		if (nums.size() < 3)return 0;
		vector<pair<int, pair<int, int>>> vec_p;
		for (int i = 0; i <= nums.size() - 3; i++) {
			if ((nums[i + 2] - nums[i + 1]) == (nums[i + 1] - nums[i])) {
				pair<int, pair<int, int>> p(nums[i + 1] - nums[i], pair<int, int>(i, i + 2));
				vec_p.push_back(p);
			}
		}
		if (vec_p.size() <=1)return vec_p.size();
	
		int res = 0;
		int count = 1;
		for (int i = 0; i < vec_p.size()-1; i++) {
			
			if (vec_p[i].first == vec_p[i + 1].first&&(vec_p[i+1].second.first-vec_p[i].second.first==1)) {
				count++; continue;
			}
			else {
				res += (count + 1) * count / 2;
				count = 1;
			}

		}
		res += (count + 1) * count / 2;
		return res;
	}
};


int main() {
	vector<int> input = { 1,2,3,4,5,6};
	Solution mysolu;
	int res = mysolu.numberOfArithmeticSlices(input);
	return 0;
}