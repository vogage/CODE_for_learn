//
//  840_Magic Squares In Grid.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/3.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt=0;
        if(grid.size()<3||grid[0].size()<3) return 0;
        for(int i=0;i<grid.size()-2;i++)
        {
            for(int j=0;j<grid[0].size()-2;j++)
            {
                if(isMagic(i,j,grid))cnt++;
            }
            
        }
        return cnt;
        
    }
private:
    bool  isMagic(int i,int j, vector<vector<int>>&grid)
    {
       unordered_set<int> NumSet;
       for(int k=1;k<=9;k++) NumSet.insert(k);
        NumSet.erase(grid[i][j]);
        NumSet.erase(grid[i][j+1]);
        NumSet.erase(grid[i][j+2]);
        NumSet.erase(grid[i+1][j]);
        NumSet.erase(grid[i+1][j+1]);
        NumSet.erase(grid[i+1][j+2]);
        NumSet.erase(grid[i+2][j]);
        NumSet.erase(grid[i+2][j+1]);
        NumSet.erase(grid[i+2][j+2]);
       int row1=grid[i][j]+grid[i][j+1]+grid[i][j+2];
       int row2=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
       int row3=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
       int col1=grid[i][j]+grid[i+1][j]+grid[i+2][j];
       int col2=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
       int col3=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
       int diag1=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
       int diag2=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
       return row1==row2&&row2==row3&&row3==col1&&col1==col2&&col2==col3&&col3==diag1&&diag1==diag2&&NumSet.size()==0;
   }
};



int main(){
    Solution mysolu;
    vector<vector<int>> grid={{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    vector<vector<int>> grid1={{8}};
    vector<vector<int>> grid2={{5,5,5},{5,5,5},{5,5,5}};
    int res=mysolu.numMagicSquaresInside(grid2);
    return 0;
}
