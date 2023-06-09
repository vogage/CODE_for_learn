//
//  540_Single Element in a Sorted Array.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/9.
//

#include <stdio.h>
#include <vector>

using namespace std;

//You are given a sorted array consisting of only integers where every element appears exactly twice,
//except for one element which appears exactly once.


//Your solution must run in O(log n) time and O(1) space.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int p=0;
        for(int i=0;i<nums.size();i++){
            p^=nums[i];
        }
        return p;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    int res=mysolu.singleNonDuplicate(nums);
    return 0;
}
