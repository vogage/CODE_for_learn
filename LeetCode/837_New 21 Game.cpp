//
//  837_New 21 Game.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/19.
//

#include <stdio.h>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k<=0||k+maxPts<=n)return 1.0;
        vector<double> dp(n+1,0.0);
        double Wsum=1.0;
        double res=0.0;
        dp[0]=1.0;
        for(int i=1;i<=n;i++){
            dp[i]=Wsum/maxPts;
            if(i<k) Wsum+=dp[i];else res+=dp[i];
            if(i-maxPts>=0) Wsum-=dp[i-maxPts];
            
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    int n = 21;
    int k = 17;
    int maxPts = 10;
    double res=mysolu.new21Game(n, k, maxPts);
    return 0;
}
