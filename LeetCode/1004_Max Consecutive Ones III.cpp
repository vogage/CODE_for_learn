#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int> kinitial;
        kinitial.push_back(-1);
        nums.push_back(0);
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                kinitial.push_back(i);
                int n = kinitial.size();
                if (n > k+1) {
                    res = max(res, i - kinitial[n - k-2]-1);
                }
            }
        }
        
        if (kinitial.size() <= k+1)return nums.size();
       
    }
};

int main() {
    Solution mysolu;
	vector<int> nums = { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 };
    vector<int> nums1 = { 1,1,1,0,0,0,1,1,1,1,0 };
    int k1 = 2;
    int k = 3;
    int res = mysolu.longestOnes(nums1,k1);
    return 0;
}