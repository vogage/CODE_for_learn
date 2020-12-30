#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first > p2.first;
}

class Solution {
public:





    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k,0);
        int m = nums1.size();
        int n = nums2.size();
        for (int i = max(0, k - n); i <= k && i <= m; i++) {
            vector<int> temp = merge(maxknums(nums1, i), maxknums(nums2, k - i), k);
            if (greater(temp, 0, res, 0)) res = temp;
        }
        return res;
    }

    bool greater(vector<int>& nums1, int i, vector<int>& nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) { 
            i++; j++;
        }
        return j == nums2.size() || (i<nums1.size() && nums1[i]>nums2[j]);

    }

    vector<int> maxknums(vector<int>& nums, int k) {
        vector<int> ans(k, 0);
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (nums.size() -i+ j > k && j > 0 && ans[j-1] < nums[i]) j--;
            if(j<k)    ans[j++] = nums[i];
            
        }
        return ans;
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2,int k) {
        vector<int> res(k,0);
        for (int i = 0, j = 0, r = 0; r < k; r++) {
            res[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    //vector<int> nums1 = { 3, 4, 6, 5 };
    //vector<int> nums2 = { 9, 1, 2, 5, 8, 3 };

    vector<int> nums1 = { 1,2 };
    vector<int> nums2 ;

    vector<int> res = mysolu.maxNumber(nums1, nums2,2);
    vector<int> maxknums = mysolu.maxknums(nums1, 2);
    return 0;
}