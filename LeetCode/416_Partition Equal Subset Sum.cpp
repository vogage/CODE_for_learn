#include<vector>
#include<algorithm>

using namespace std;

//Given a non - empty array nums containing only positive integers, 
//find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

class Solution {
public:
    //      This problem is essentially let us to find whether there are several numbers in a set which are able to sum to a specific value
    //     (in this problem, the value is sum / 2).

    //      Actually, this is a 0 / 1 knapsack problem, for each number, we can pick it or not.
    //      Let us assume dp[i][j] means whether the specific sum j can be gotten from the first i numbers.
    //      If we can pick such a series of numbers from 0 - i whose sum is j, dp[i][j] is true, otherwise it is false.

    //       Base case: dp[0][0] is true; (zero number consists of sum 0 is true)

    //       Transition function : For each number, 
    //       if we don't pick it, dp[i][j] = dp[i-1][j], which means if the first i-1 elements has made it to j,
    //       dp[i][j] would also make it to j (we can just ignore nums[i]). If we pick nums[i]. 
    //       dp[i][j] = dp[i-1][j-nums[i]], which represents that j is composed of the current value nums[i] 
    //       and the remaining composed of other previous numbers. 
    //       Thus, the transition function is dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int num : nums) {
            sum += num;
        }

        if ((sum & 1) == 1) {
            return false;
        }
        sum /= 2;

        int n = nums.size();
        vector<vector<bool>> dp(n + 1,vector<bool>(sum + 1,false);


        dp[0][0] = true;

        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j < sum + 1; j++) {
            dp[0][j] = false;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < sum + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]);
                }
            }
        }

        return dp[n][sum];
    }
    bool canPartition2(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 2 == 1)return false;
        int target = sum / 2;
        int cur = nums.back();
        return helper(nums, nums.size() - 2, cur, target);

    }
    bool helper(vector<int>& nums, int index, int cur, int target) {
        if (cur == target) return true;
        if (index < 0)return false;
        return helper(nums, index - 1, cur, target) || helper(nums, index - 1, cur + nums[index], target);
    }
};



int main() {
    vector<int> nums = { 2,2,1,1 };
    Solution mysolu;
    bool res = mysolu.canPartition(nums);
    return 0;

}