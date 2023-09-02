//
//  915_Partition Array into Disjoint Intervals.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/25.
//

#include <stdio.h>
#include <vector>

using namespace std;

//Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:
//
//Every element in left is less than or equal to every element in right.
//left and right are non-empty.
//left has the smallest possible size.
//Return the length of left after such a partitioning.
//
//Test cases are generated such that partitioning exists.
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        //find the miniest index
        pair<int,int> minP(INT_MAX,-1);
        int leftmax=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(minP.first>nums[i]){
                minP.first=nums[i];
                minP.second=i;
            }
           
        }
        //iterate form the begin
        for(int i=0;i<=minP.second;i++){
            leftmax=max(leftmax,nums[i]);
        }
        //iterate from the min index
        for(int i=minP.second+1;i<nums.size();i++){
            if(nums[i]<leftmax){
                minP.second=i;
                leftmax=max(leftmax,minP.first); // minP first is value ,second is the index
            }
            minP.first=max(minP.first,nums[i]);
        }
        return minP.second+1;
    }
};

int main(){
    Solution mysolu;
//Input: nums = [5,0,3,8,6]
//Output: 3
//Explanation: left = [5,0,3], right = [8,6]
    vector<int>  nums={5,0,3,8,6};
    vector<int>  nums1={1,1};
    int res=mysolu.partitionDisjoint(nums1);
    return 0;
}
