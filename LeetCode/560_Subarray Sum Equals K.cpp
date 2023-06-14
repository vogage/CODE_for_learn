//
//  560_Subarray Sum Equals K.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/14.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> SumMap;
       
        int TempSum=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            TempSum+=nums[i];
            if(TempSum==k) cnt++;
            if(SumMap.find(TempSum-k)!=SumMap.end()){
                cnt+=SumMap[TempSum-k];
            }
            SumMap[TempSum]++;
        }
        return cnt;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={1,1,1};
    int res=mysolu.subarraySum(nums, 2);
    return 0;
}
