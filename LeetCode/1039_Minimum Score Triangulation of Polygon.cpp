//
//  1039_Minimum Score Triangulation of Polygon.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/7.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class cmp{
public:
    bool operator()(int &v1,int &v2){
        return v1<v2;
    }
};

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
      //devide
        int n=values.size();
        dp=vector<vector<int>>(n,vector<int>(n,0));
        int res=INT_MAX;
        return dp_divide(values,0,values.size()-1);
    }
private:
    int dp_divide(vector<int>& values,int i,int j){
        if(dp[i][j]!=0)return dp[i][j];
        int res=j-i>1?INT_MAX:0;
        for(int k=i+1;k<j;k++){
            res=min(res,values[i]*values[k]*values[j]+dp_divide(values, i, k)+dp_divide(values, k, j));
        }
        return dp[i][j]=res;
    }
    vector<vector<int>> dp;
};

int main(){
    Solution mysolu;
    vector<int> values = {1,3,1,4,1,5};
    vector<int> values1={2,1,4,4};
    int res=mysolu.minScoreTriangulation(values);
    return 0;
}
