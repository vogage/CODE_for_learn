//
//  368_Largest Divisible Subset.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/28.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>());
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if((dp[j].size()>dp[i].size())&&(nums[i-1]%nums[j-1]==0)){
                  
                        dp[i]=dp[j];
                    
                }
            }
            dp[i].push_back(nums[i-1]);
            if(ans.size()<dp[i].size()) ans=dp[i];
        }
        return ans;
       
    }
  
};

class Solution2 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        int flag=1;
        if(nums[0]==1){
            flag=0;
        }
        else{
            nums.push_back(1);
            flag=1;
        }
        sort(nums.begin(),nums.end());
        int i,j;
        int dp[nums.size()][2];
        int dp2[5*nums.size()][2];
        int dd=dp2[300][1];
        dp2[300][1]=10;
        int pp=dp2[300][1];
        for(i=nums.size()-1;i>=0;i--){
            dp[i][0]=0;
            dp[i][1]=i;
            for(j=i+1;j<nums.size();j++){
                if((nums[j]%nums[i])==0){
                    if(dp[j][0]>dp[i][0]){
                        dp[i][0]=dp[j][0];
                        dp[i][1]=j;
                    }
                }
            }
            dp[i][0]++;
        }
        i=0;
        vector<int> t;
        t.push_back(nums[i]);
        while(dp[i][1]!=i){
            i=dp[i][1];
            t.push_back(nums[i]);
            
        }
        if(flag==1){
            t.erase(t.begin());
        }
        return t;
        
    }
};

int main(){
    vector<int> nums = {1,2,4,8};
    Solution2 mysolu;
    vector<int> res=mysolu.largestDivisibleSubset(nums);
    return 0;
}
