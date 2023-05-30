//
//  343_Integer Break.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/5.
//

#include <stdio.h>
#include<vector>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> pv(n+1,vector<int>(n+1,0));
        pv[0][2]=0;
        pv[1][1]=1;
        pv[1][2]=0;
        pv[2][2]=1;
        pv[2][1]=2;
        for(int i=3;i<=n;i++){
            pv[i][1]=i;
            for(int k=2;k<=i/2+1;k++){
                for(int j=i-1;j>=1;j--){
                    pv[i][k]=max(pv[i][k],pv[j][k-1]*(i-j));
                }
            }
        }
        int res=0;
        for(int i=2;i<=pv[n].size()/2+1;i++){
            res=max(res,pv[n][i]);
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    int input=2;
    int input2=6;
    int res=mysolu.integerBreak(input2);
    return 0;
}
