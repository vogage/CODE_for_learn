//
//  421_Maximum XOR of Two Numbers in an Array.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/16.
//

#include <stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res=0,mask=0;
        for(int i=31;i>=0;i--){
            int mask=mask|(1<<i);
            unordered_set<int> candiset;
            for(int j=0;j<nums.size();j++){
                int prefix=mask&nums[j];
                candiset.insert(prefix);
            }
            int temp=res|(1<<i);
            for(auto pre:candiset){
                if(candiset.find(pre^temp)!=candiset.end()){
                    res=temp;
                    break;
                }
            }
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    vector<int> nums={3,10,5,25,2,8};
    int res=mysolu.findMaximumXOR(nums);
    return 0;
}
