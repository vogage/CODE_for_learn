#include<vector>

using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sums = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sums += nums[i];
        }
        int average = sums / n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += abs(nums[i] - average);
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    vector<int> nums = { 1,10,2,9 };
    int res = mysolu.minMoves2(nums);

    return 0;
}