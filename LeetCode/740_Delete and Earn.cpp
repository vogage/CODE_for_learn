#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;
//
//You are given an integer array nums.You want to maximize the number of points you get 
//by performing the following operation any number of times :
//
//Pick any nums[i] and delete it to earn nums[i] points.Afterwards, 
//you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
//Return the maximum number of points you can earn by applying the above operation some number of times.


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            nums_map[nums[i]]++;
        }
        vector<int> nums_vec;
        for (auto m : nums_map) {
            nums_vec.push_back(m.first);
        }
  
        sort(nums_vec.begin(), nums_vec.end());
        int n = nums_vec.size();
        vector<int> dp;
        for (int i = 0; i < n; i++) {
            dp.push_back(nums_vec[i] * nums_map[nums_vec[i]]);
        }
        int pre_max2 = 0;
        int pre_max1 = dp[0];
        for (int i = 1; i <n; i++) {
            if (nums_vec[i] == nums_vec[i - 1] + 1) {            
                dp[i] = dp[i] + pre_max2;
               
                
            }
            else {
                dp[i] = dp[i] + pre_max1;
            }
            pre_max2 = max(dp[i - 1], pre_max2);
            pre_max1 = max(pre_max1, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
//Input: nums = [2, 2, 3, 3, 3, 4]
//Output : 9
//Explanation : You can perform the following operations :
//-Delete a 3 to earn 3 points.All 2's and 4's are also deleted.nums = [3, 3].
//- Delete a 3 again to earn 3 points.nums = [3].
//- Delete a 3 once more to earn 3 points.nums = [].
//You earn a total of 9 points.
    vector<int> nums1 = { 1,1,1,2,4,5,5,5,6 };
    vector<int> nums = { 2, 2, 3, 3, 3, 4 };
    vector<int> nums2 = { 1,6,3,3,8,4,8,10,1,3 };

    Solution mysolu;
    int res = mysolu.deleteAndEarn(nums1);
	return 0;
}