//
//  1027_Longest Arithmetic Subsequence.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/7.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        vector<unordered_map<int, int>> subs(n,unordered_map<int, int>());
        int res=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                int d=nums[i]-nums[j];
                subs[i][d]=subs[j][d]+1;
                res=max(subs[i][d],res);
            }
        }
        return res+1;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={20,1,15,3,10,5,8};
    int res=mysolu.longestArithSeqLength(nums);
    return 0;
}

