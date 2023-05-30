#include<vector>

using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int total = 0;
        int max_temp = 0;
        int max_result = INT_MIN;
        int n = nums.size();
        for (int i : nums) total += i;
        for (int j = 0; j < nums.size(); j++) max_temp += j * nums[j];
        for (int i : nums) {
            max_temp=max_temp - total + i * n;
            max_result = max(max_result, max_temp);
        }
        return max_result;
    }
};

int main() {
    vector<int> nums = { 4, 3, 2, 6 };
    Solution mysolu;
    int res = mysolu.maxRotateFunction(nums);
    return 0;
}