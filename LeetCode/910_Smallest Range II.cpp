//
//  910_Smallest Range II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int right=nums.back()-k;
        int left=nums[0]+k;
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int maxi=max(nums[i]+k,right);
            int mini=min(nums[i+1]-k,left);
            res=min(res,maxi-mini);
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    //nums = [1,3,6], k = 3
    vector<int> nums={1,3,6};
    int k=3;
    int res=mysolu.smallestRangeII(nums, k);
    return 0;
}
