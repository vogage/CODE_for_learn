#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int intervalCnt0 = 0;
        int temp = 0;
        int res = 0;
        queue<int> que;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                intervalCnt0++;
            }
            else {
                que.push(intervalCnt0);
                temp++;
                if (temp == goal + 1) {
                    if (goal == 0) res += (intervalCnt0 + 1) * intervalCnt0 / 2;
                    else res += (intervalCnt0 + 1) * (que.front() + 1);
                    que.pop();
                    temp--;
                }

                intervalCnt0 = 0;
            }
        }
        if (temp == goal) {
            if (!que.empty()) res += (que.front() + 1) * (intervalCnt0 + 1);
            else res += intervalCnt0*(intervalCnt0+1)/2;
        }
        return res;
    }
};

int main() {
    Solution mysolu;
//Input: nums = [1, 0, 1, 0, 1], goal = 2
//Output : 4
//Explanation : The 4 subarrays are bolded and underlined below :
//[1, 0, 1, 0, 1]
//[1, 0, 1, 0, 1]
//[1, 0, 1, 0, 1]
//[1, 0, 1, 0, 1]
    vector<int> nums = { 1, 0, 1, 0, 1 };
    int goal = 2;
    vector<int> nums1 = { 0,0,0,0,0 };
    int goal1 = 0;
    vector<int> nums2 = { 0,0,0,0,0,0,1,0,0,0 };
    int goal2 = 0;
    int res = mysolu.numSubarraysWithSum(nums2,goal2);
    return 0;
}

