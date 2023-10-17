//
//  962_Maximum Width Ramp.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/12.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> Candidates; //first:nums[i], second;i
        Candidates.push_back(pair<int,int>(nums[0],0));
        int res=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<Candidates.back().first){
                Candidates.push_back(pair<int,int>(nums[i],i));
            }else{
                int k=Candidates.size()-1;
                while(k>=0&&Candidates[k].first<=nums[i]) k--;
                res=max(res,i-Candidates[k+1].second);
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={9,8,1,0,1,9,4,0,4,1};
    vector<int> nums1={3,4,1,2};
    int res=mysolu.maxWidthRamp(nums1);
    return 0;
}
