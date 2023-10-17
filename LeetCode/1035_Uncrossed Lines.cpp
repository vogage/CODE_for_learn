//
//  Testcase Testcase Result  Code  1035_Uncrossed Lines.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/13.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int res=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=max(dp[i][j]+1,dp[i+1][j+1]);
                    res=max(res,dp[i+1][j+1]);
                }else{
                    dp[i+1][j+1]=max(dp[i][j],dp[i+1][j]);
                }
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums1={2,5,1,2,5};
    vector<int> nums2={10,5,2,1,5,2};
    vector<int> nums11={1,3,7,1,7,5};
    vector<int> nums21={1,9,2,5,1};
    int res=mysolu.maxUncrossedLines(nums11, nums21);
    return 0;
}
