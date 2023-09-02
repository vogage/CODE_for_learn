//
//  891_Sum of Subsequence Widths.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/21.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        if(nums.size()<=1)return 0;
        if(nums.size()==2)return abs(nums[1]-nums[0]);
        long long res=0;
        int mod=1000000007;
        sort(nums.begin(),nums.end());
        
        return res%mod;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums = {2,1,3};
    int res=mysolu.sumSubseqWidths(nums);
    return 0;
}
