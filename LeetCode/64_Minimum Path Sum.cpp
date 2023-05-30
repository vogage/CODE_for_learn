//
//  64_Minimum Path Sum.cpp
//  leetcode
//
//  Created by qiandehou on 2022/3/29.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return 0;
        int m=grid[0].size();
        for(int i=m-2;i>=0;i--){
            grid[n-1][i]=grid[n-1][i]+grid[n-1][i+1];
        }
        for(int i=n-2;i>=0;i--){
            grid[i][m-1]=grid[i][m-1]+grid[i+1][m-1];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                grid[i][j]=min(grid[i+1][j],grid[i][j+1])+grid[i][j];
            }
        }
        return grid[0][0];
        
    }
};

int main(){
    vector<vector<int>> grid={{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid2={{1,2,3},{4,5,6}};
    Solution mysolu;
    int res=mysolu.minPathSum(grid2);
    return 0;
}

