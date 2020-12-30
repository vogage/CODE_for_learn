#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
       
        if (nums.size() == 0)return false;
        long total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        if (total % 4 != 0)return false;
        vector<long> buckets(4, total / 4);

        sort(nums.begin(), nums.end(),greater<int>());
        return put_buckets(nums, buckets, 0);
    }
    bool put_buckets(vector<int>& nums, vector<long>& buckets, int i) {
        if (i == nums.size()) {
            if (buckets[0] == 0 && buckets[1] == 0 && buckets[2] == 0 && buckets[3] == 0) return true;
            return false;
        }
        for (int j = 0; j < 4; j++) {
            int res = buckets[j] - nums[i];
            if (res < 0)continue;
            buckets[j] = res;
            if (put_buckets(nums, buckets, i + 1))return true;
            buckets[j] = res + nums[i];


        }
        return false;

    }

};


int main() {
    Solution mysolu;
    vector<int> input = { 1,1,2,2,2 };
    vector<int> input2 = { 5,5,5,5,4,4,4,4,3,3,3,3 };
    vector<int> input3 = { 12,12,12,16,20,24,28,32,36,40,44,48,52,56,60 };
    bool res = mysolu.makesquare(input3);
    return 0;
}