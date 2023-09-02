//
//  887_Super Egg Drop.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/21.
//

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
//1 <= k <= 100
//1 <= n <= 104
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        for(int m=1;m<=n;m++){
            for(int t=1;t<=k;t++){
                
                dp[m][t]=dp[m-1][t-1]+dp[m-1][t]+1;
                if(dp[m][t]>=n) return m;
            }
        }
        return 0;
    }
};


int main(){
    Solution mysolu;
    int k=3;
    int n=14;
    int k1=1;
    int n1=4;
    int k2=2;
    int n2=7;
    int res=mysolu.superEggDrop(1,4);
    return 0;
}
