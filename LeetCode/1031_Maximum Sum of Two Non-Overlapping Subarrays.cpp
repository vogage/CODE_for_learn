//
//  1031_Maximum Sum of Two Non-Overlapping Subarrays.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/12.
//

#include <stdio.h>
#include <vector>

using namespace std;
//Given an integer array nums and two integers firstLen and secondLen,
//return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.
//
//The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.
//
//A subarray is a contiguous part of an array.

//1 <= firstLen, secondLen <= 1000
//2 <= firstLen + secondLen <= 1000
//firstLen + secondLen <= nums.length <= 1000
//0 <= nums[i] <= 1000

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen){
        int n=nums.size();
        vector<int> sums(n+1,0);
        for(int i=0;i<nums.size();i++){
            sums[i+1]=sums[i]+nums[i];
        }
        
        return res;
    }
};

class Solution2 {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int> firstLenSum(n,0);
        int i=0,temp=0;
        for(;i<firstLen;i++) temp+=nums[i];
        firstLenSum[i-1]=temp;
        for(;i<n;i++){
            temp+=nums[i];
            temp-=nums[i-firstLen];
            firstLenSum[i]=temp;
        }
        vector<int> leftmaxFirstSum(n,0);
        vector<int> rightmaxFirstSum(n,0);
        leftmaxFirstSum[firstLen-1]=firstLenSum[firstLen-1];
        for(int end=firstLen;end<n;end++) leftmaxFirstSum[end]=max(leftmaxFirstSum[end-1],firstLenSum[end]);
        for(int begin=n-firstLen;begin>=0;begin--) rightmaxFirstSum[begin]=max(rightmaxFirstSum[begin+1],firstLenSum[begin+firstLen-1]);

        //iterator the secondLen array
   
        i=0;
        temp=0;
        for(;i<secondLen;i++) temp+=nums[i];
        int res=temp+rightmaxFirstSum[i];
        for(;i<n;i++){
            temp=temp-nums[i-secondLen]+nums[i];
            int left=i-secondLen;
            if(left>=0) res=max(res,temp+leftmaxFirstSum[left]);
            int right=i+1;
            if(right<n) res=max(res,temp+rightmaxFirstSum[right]);
        }
        
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={3,8,1,3,2,1,8,9,0};
    int firstLen=3;
    int secondLen=2;
    vector<int> nums1={2,1,5,6,0,9,5,0,3,8};
    int firstLen1=4;
    int secondLen1=3;
    int res=mysolu.maxSumTwoNoOverlap(nums1, firstLen1, secondLen1);
    return 0;
}
