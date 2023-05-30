#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int res = 0;
        for (int i = n1-1; i >= 0;i--) {
            for (int j = n2-1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                   dp[i][j] = dp[i + 1][j + 1] + 1;       
                   res = max(res, dp[i][j]);
                }
                else {
                    //dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = { 1, 2, 3, 2, 1 };
    vector<int> nums2 = { 3, 2, 1, 4, 7 };

    vector<int> nums3 = { 1, 0, 1, 0, 0, 0, 0, 0, 1, 1 };
        
    vector<int> nums4 = { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 };
    Solution mysolu;
    int res = mysolu.findLength(nums3, nums4);
    return 0;
}