//
//  525_Contiguous Array.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/9.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;
//Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> CntMap;
        int cnt=0;
        int res=0;
        CntMap[0]=-1;
        for(int i=0;i<nums.size();i++){
            nums[i]==0?cnt--:cnt++;
            if(CntMap.find(cnt)!=CntMap.end()){
                res=max(res,i-CntMap[cnt]);
            }else{
                CntMap[cnt]=i;
            }
            
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={1,1,0,0,0,0,0,0,1,1,1};
    int res=mysolu.findMaxLength(nums);
    return 0;
}

