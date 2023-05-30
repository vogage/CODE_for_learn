#include<vector>

using namespace std;

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		// subarray_min
		//  subarray_max
		//  sum
		int sub_max = INT_MIN;
		int sub_min = INT_MAX;
		int temp_sub_max = INT_MIN;
		int temp_sub_min = INT_MAX;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			if (temp_sub_max >= 0) temp_sub_max += nums[i];
			else temp_sub_max = nums[i];
			if (temp_sub_min <= 0) temp_sub_min += nums[i];
			else temp_sub_min = nums[i];
			sub_max = max(sub_max, temp_sub_max);
			sub_min = min(sub_min, temp_sub_min);
		}
		return sum==sub_min?sub_max:max(sub_max,sum-sub_min);
	}
};

class Solution2 {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size();
		int res = INT_MIN;
		for (int i = 0; i < n; i++) {
			int temp_res = INT_MIN;
			int temp = 0;
			for (int k = i; k < i + n; k++) {
				int index = k % n;
				if (temp < 0) temp = nums[index];
				else temp += nums[index];
				temp_res = max(temp_res, temp);
			}
			res = max(res, temp_res);
		}
		return res;
	}
};


int main() {
	Solution mysolu;
	vector<int> nums = { 1, -2, 3, -2 };
	vector<int> nums1 = { 5,-3,5 };
	vector<int> nums2 = { -3,-2,-3 };
	vector<int> nums3 = { 0,5,8,-9,9,-7,3,-2 };
	vector<int> nums4 = { 9,7,-6,7,9,-10,5,9,0,-1 };
	vector<int> nums5 = { -3,-2,-3 };
	int res = mysolu.maxSubarraySumCircular(nums5);
	return 0;
}