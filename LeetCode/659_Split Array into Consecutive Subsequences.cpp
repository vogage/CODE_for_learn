//
//  659_Split Array into Consecutive Subsequences.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
//        Each subsequence is a consecutive increasing sequence (i.e. each integer is exactly one more than the previous integer).
//        All subsequences have a length of 3 or more.
        int n=nums.size();
       
        unordered_map<int, int> NumCntMap;
        for(int i=0;i<nums.size();i++) NumCntMap[nums[i]]++;
        unordered_map<int, int> EndNumMap;
        for(int i:nums){
            if(NumCntMap[i]==0)continue;
            if(EndNumMap[i-1]>0){
                EndNumMap[i-1]--;
                EndNumMap[i]++;
            }else if(NumCntMap[i+1]>0&&NumCntMap[i+1]>0){
                EndNumMap[i+2]++;
                NumCntMap[i+1]--;
                NumCntMap[i+2]--;
            }else{
                return false;
            }
        }
        return true;
        
    }
private:
    
    
};


int main(){
    Solution mysolu;
//Input: nums = [1,2,3,3,4,4,5,5]
//Output: true
//Explanation: nums can be split into the following subsequences:
//[1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
//[1,2,3,3,4,4,5,5] --> 3, 4, 5
    return 0;
}
