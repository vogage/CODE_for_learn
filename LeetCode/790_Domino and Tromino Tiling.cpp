//
//  790_Domino and Tromino Tiling.cpp
//  leetcode
//
//  Created by qiandehou on 2022/4/1.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int numTilings(int n) {
        int Mod=1e9;
        if(n<0)return -1;
        if(n==1)return 1;
        if(n==2)return 2;
        if(n==3)return 5;
        vector<long long> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=Mod;
        }
        return (int)dp[n];
    }
};



int main(){
    Solution mysolu;
    int res=mysolu.numTilings(4);
    return 0;
}
