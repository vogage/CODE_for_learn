#include<vector>
#include<unordered_map>

using namespace std;

//Given an integer array nums, return the number of all the arithmetic subsequences of nums.
//
//A sequence of numbers is called arithmetic if it consists of at least three elements and 
//if the difference between any two consecutive elements is the same.
//
//For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences.
//For example, [1, 1, 2, 5, 7] is not an arithmetic sequence.
//A subsequence of an array is a sequence that can be formed by removing some elements(possibly none) of the array.
//
//For example, [2, 5, 10] is a subsequence of[1, 2, 1, 2, 4, 1, 5, 10].
//The test cases are generated so that the answer fits in 32 - bit integer.

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> index_diff_map(n, unordered_map<int, int>());
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff_temp = (long)nums[i] - nums[j];
                if (diff_temp >= INT_MAX || diff_temp <= INT_MIN) continue;
                int diff = (int)diff_temp;
                int c1 = 0;
                if (index_diff_map[i].find(diff) != index_diff_map[i].end()) {
                    c1 = index_diff_map[i][diff];
                }
                int c2 = 0;
                if (index_diff_map[j].find(diff) != index_diff_map[j].end()) {
                    c2 = index_diff_map[j][diff];
                }
                res += c2;
                index_diff_map[i][diff] = c1 + c2 + 1;
            }
        }
        return res;
    }
};


int main() {
    vector<int> nums = { 2, 4, 6, 8, 10 };
    Solution mysolu;
    int res = mysolu.numberOfArithmeticSlices(nums);
    return 0;
}