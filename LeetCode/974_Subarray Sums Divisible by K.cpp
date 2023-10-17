#include<vector>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sums[i + 1] = nums[i] + sums[i];
        }
        vector<int> cnts(n + 1, 0);
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if ((sums[i] - sums[j]) % k == 0) {
                    cnts[i] += cnts[j] + 1;
                    res += cnts[i];
                    break;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    vector<int> nums = { 4,5,0,-2,-3,1 };
    int k = 5;
    int res = mysolu.subarraysDivByK(nums, k);
	return 0;
}