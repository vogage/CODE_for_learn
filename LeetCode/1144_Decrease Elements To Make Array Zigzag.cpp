#include <vector>

using namespace std;

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // case 1 : A0>A1<A2
        // case 2 : A0<A1>A2
        int c1 = 0;
        int c2 = 0;
       
        vector<int> c1nums = nums;
        vector<int> c2nums = nums;
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2 == 1) {
                if (c1nums[i] >=c1nums[i - 1]) {
                    c1 += c1nums[i] - c1nums[i - 1]+1;
                    c1nums[i] = c1nums[i - 1] - 1;
                }
            }
            else {
                if (c1nums[i] <= c1nums[i - 1]) {
                    c1 += c1nums[i - 1] - c1nums[i] + 1;
                    c1nums[i - 1] = c1nums[i] - 1;
                }
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (i % 2 == 1) {
                if (c2nums[i] <= c2nums[i - 1]) {
                    c2 += c2nums[i - 1] - c2nums[i] + 1;
                    c2nums[i-1] = c2nums[i] - 1;
                }
            }
            else {
                if (c2nums[i] >= c2nums[i - 1]) {
                    c2 += c2nums[i] - c2nums[i - 1] + 1;
                    c2nums[i] = c2nums[i - 1] - 1;
                }
            }
        }
        return min(c1, c2);
    }
};

int main() {
    Solution mysolu;
    vector<int> nums = { 9,6,1,6,2 };
    vector<int> nums1 = { 10,4,4,10,10,6,2,3 };
    int res = mysolu.movesToMakeZigzag(nums1);
    return 0;
}