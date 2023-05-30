#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)return false;
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        int m = n / 2;
        bool flag = true;
        for (int k = 1; k <= m; k++) if (total * k % n == 0) flag = false;
        if (flag)return false;
        vector<unordered_set<int>> sum_set(m + 1, unordered_set<int>());
        sum_set[0].insert(0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = m; j > 0; j--) {
                for (auto k : sum_set[j-1]) {
                    sum_set[j].insert(k + nums[i]);
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if((total*i%n==0)&&(sum_set[i].find(total*i/n)!=sum_set[i].end()))return true;
        }
        return false;
    }
private:

};


int main() {
    Solution mysolu;
    vector<int> nums = { 1,2,3,4,5,6,7,8 };
    vector<int> nums1 = { 6,8,18,3,1 };
    vector<int> nums2 = { 7,0,16,11,10,9,10,9,8 };
    vector<int> nums3 = { 1,6,1 };
    vector<int> nums4 = { 5,3,11,19,2 };
    vector<int> nums5 = { 10, 29, 13, 53, 33, 48, 76, 70, 5, 5 };
    vector<int> nums6 = { 12,1,17,8,2 };
    vector<int> nums7 = { 1,3 };
    vector<int> nums8 = { 60,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30 };
    vector<int> nums9 = { 5,3,11,19,2 };
    vector<int> nums10 = { 2, 12, 18, 16, 19, 3 };
    bool res = mysolu.splitArraySameAverage(nums9);
	return 0;
}