#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		// nums = [3, 1, 5, 8] -- > [3, 5, 8] -- > [3, 8]   -- > [8]  -- > []
		//	coins = 3 * 1 * 5 + 3 * 5 * 8 + 1 * 3 * 8 + 1 * 8 * 1 = 167
		vector<int> nums2;
		nums2.push_back(1);
		nums2.insert(nums2.end(), nums.begin(), nums.end());
		nums2.push_back(1);
		int n = nums2.size();
		vector<vector<int>>dp(n, vector<int>(n, 0));
		for (int right= 1; right< nums2.size()-1;right++) {
			for (int left = right; left>=1; left--) {
				for (int k =left ; k <=right; k++) {
					int origin = dp[left][right];
					int left_side_burned = dp[left][k - 1];
					int the_one_burned = nums2[left - 1] * nums2[k] * nums2[right + 1];
					int right_side_burned = dp[k + 1][right];
					dp[left][right] = max(dp[left][right], nums2[left - 1] * nums2[k] * nums2[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
				}
			}

		}
		return dp[1][n-2];
	}
};

int main() {
	Solution mysolu;
	vector<int> nums = { 3,1,5,8 };
	int res = mysolu.maxCoins(nums);
	return 0;
}

	
