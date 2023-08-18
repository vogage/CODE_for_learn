//
//  861_Score After Flipping Matrix.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/11.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
//    A move consists of choosing any row or column and toggling each value in that row or column
// (i.e., changing all 0's to 1's, and all 1's to 0's).
    int matrixScore(vector<vector<int>>& grid) {
        // change the row flip, ensure the first coloumn to be 1 digit
        for(int i=0;i<grid.size();i++){
            if(grid[i][0]==0) fliprow(grid,i);
        }
        // change the colonm flip, sum the grid value in each row
        int tempex=1;
        int res=0;
        int n=grid.size();
        for(int j=grid[0].size()-1;j>=0;j--){
            int colsum=0;
            for(int i=0;i<n;i++){
                colsum+=grid[i][j];
            }
            res+=tempex*max(colsum,n-colsum);
            tempex=tempex*2;
        }
        return res;
    }
private:
    void fliprow(vector<vector<int>>& grid,int i){
        for(int j=0;j<grid[i].size();j++){
            grid[i][j]=1-grid[i][j];
        }
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> grid = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    int res=mysolu.matrixScore(grid);
    return 0;
}
