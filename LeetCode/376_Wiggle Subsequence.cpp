//
//  376_Wiggle Subsequence.cpp
//  leetcode
//
//  Created by qiandehou on 2021/5/24.
//

#include <stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> down(n,1);
        vector<int> up(n,1);
        for (int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                up[i]=down[i-1]+1;
                down[i]=down[i-1];
            }else if(nums[i]<nums[i-1]){
                up[i]=up[i-1];
                down[i]=up[i-1]+1;
            }else{
                down[i]=down[i-1];
                up[i]=up[i-1];
            }
        }
        return max(down[n-1],up[n-1]);
    }
};


int main(){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    vector<int> nums2={1,2,3,4,5,6,7,8,9};
    vector<int> nums3={0,0,0};
    vector<int> nums4={3,3,3,2,5};
    vector<int> nums5={1,17,5,10,13,15,10,5,16,8};
    Solution mysolu;
    int res=mysolu.wiggleMaxLength(nums5);
    return res;
}
