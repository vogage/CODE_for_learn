//
//  813_Largest Sum of Averages.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/13.
//

#include <stdio.h>
#include<vector>

using namespace std;



class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
       
        vector<vector<double>> dp(k+1,vector<double>(n,0));
        double temp_total=0;
        for(int i=0;i<nums.size();i++){
            temp_total+=nums[i];
            dp[1][i]=(double)temp_total/(double)(i+1);
        }
        for(int kk=2;kk<=k;kk++){
            for(int j=kk-1;j<n;j++){
                temp_total=0;
                for(int i=j;i>=kk-1;i--){
                    temp_total+=(double)nums[i];
                    dp[kk][j]=max(dp[kk][j],dp[kk-1][i-1]+temp_total/(double)(j-i+1));
                }
            }
        }
        return dp[k][n-1];
    }
};


int main(){
    Solution mysolu;
    vector<int> nums={9,1,2,3,9};
    int k=3;
    
    vector<int> nums1={1,2,3,4,5,6,7};
    int k1=4;
    
    double res=mysolu.largestSumOfAverages(nums1, k1);
    
    return 0;
}
