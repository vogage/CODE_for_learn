//
//  611_Valid Triangle Number.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/16.
//

#include <stdio.h>
#include <vector>

using namespace std;

//Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),less<int>());
        if(nums.size()<3)return 0;
        int cnt=0;
        for(int ThirdEdge=2;ThirdEdge<nums.size();ThirdEdge++){
            for(int SecondEdge=ThirdEdge-1;SecondEdge>0;SecondEdge--){
                int val=nums[ThirdEdge]-nums[SecondEdge];
                vector<int>::iterator itFirstEdge=upper_bound(nums.begin(), nums.end(),val);
                int FirstEdge=itFirstEdge-nums.begin();
                cnt+=SecondEdge>FirstEdge?SecondEdge-FirstEdge:0;
            }
        }
        return cnt;
    }
};

int main(){
    Solution mysolu;
    
//Input: nums = [2,2,3,4]
//Output: 3
//Explanation: Valid combinations are:
//2,3,4 (using the first 2)
//2,3,4 (using the second 2)
//2,2,3
    
    vector<int> nums={2,2,3,4};
    int res=mysolu.triangleNumber(nums);
    return 0;
}
