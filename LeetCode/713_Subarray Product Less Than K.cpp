//
//  713_Subarray Product Less Than K.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/29.
//

#include <stdio.h>
#include <vector>

using namespace std;

//1 <= nums.length <= 3 * 104
//1 <= nums[i] <= 1000
//0 <= k <= 106
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long temp=1;
        int end=0;
        int begin=0;
        int res=0;
        while(end<nums.size()){
            temp=temp*nums[end];
            while(begin<end&&temp>=k){
                temp=temp/nums[begin];
                begin++;
            }
            if(temp<k)res+=end-begin+1;
            end++;
        }
        return res;
       
    }
};

int main(){
    Solution mysolu;
//Input: nums = [10,5,2,6], k = 100
    vector<int> nums={10,5,2,6};
    int k=100;
    vector<int> nums1={1,2,3};
    int k1=0;
    int res=mysolu.numSubarrayProductLessThanK(nums1, k1);
    return 0;
}
