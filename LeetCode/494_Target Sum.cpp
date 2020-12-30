#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        vector<long> sum;
        int temp = 0;
        for (int i = nums.size()-1; i >=0; i--) {
            temp += nums[i];
            sum.push_back(temp);
        }
        reverse(sum.begin(), sum.end());
        dsf(nums, sum, 0, 0,S, res);
        return res;
        
    }
    void dsf(vector<int>& nums, vector<long>& sum,int index,int temp, int& S, int& res) {
        if (index == nums.size()) {
            if (S == temp) res++;
            return;
       }

        int temp_plus = temp +2* nums[index]-sum[index];
        if (temp_plus <= S) dsf(nums, sum, index + 1, temp + nums[index], S, res);
        int temp_decrease = temp - 2 * nums[index] + sum[index];
        if (temp_decrease >= S) dsf(nums, sum, index + 1, temp - nums[index], S, res);
    }
};

int main() {
    Solution mysolu;
    int S = 3;
    vector<int> nums = { 1, 1, 1, 1, 1 };
    int ans = mysolu.findTargetSumWays(nums, S);

    return 0;
}