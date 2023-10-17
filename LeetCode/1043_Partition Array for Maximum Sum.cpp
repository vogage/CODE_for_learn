//
//  1043_Partition Array for Maximum Sum.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/10.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,0);
        int temp=0;
        for(int i=0;i<k&&i<n;i++){
            temp=max(temp,arr[i]);
            dp[i]=temp*(i+1);
        }
        for(int i=k;i<n;i++){
            temp=arr[i];
            for(int j=1;j<=k;j++){
                temp=max(temp,arr[i-j+1]);
                dp[i]=max(dp[i],dp[i-j]+temp*j);
            }
        }
        return dp[n-1];
    }
};


int main(){
    Solution mysolu;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k=3;
    int res=mysolu.maxSumAfterPartitioning(arr, k);
    return 0;
}
