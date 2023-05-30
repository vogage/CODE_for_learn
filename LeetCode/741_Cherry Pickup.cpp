//
//  741_Cherry Pickup.cpp
//  leetcode
//
//  Created by qiandehou on 2022/3/28.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution3 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        dp[0][0]=grid[0][0];
        for(int step=1;step<=2*n-2;step++){// 0->2n-2; 一共2n-1步，没错
            vector<vector<int>> dp2(n,vector<int>(n,INT_MIN));
            // two man ,the row of each get the two dimension dp program
            for(int r1=max(0,step-(n-1));r1<=min(n-1,step);r1++){
                for(int r2=max(0,step-(n-1));r2<=min(n-1,step);r2++){
                    if(grid[r1][step-r1]==-1||grid[r2][step-r2]==-1) continue;
                    int val=grid[r1][step-r1];
                    if(r1!=r2)val+=grid[r2][step-r2];
                    for(int pre_step_r1=r1-1;pre_step_r1<=r1;pre_step_r1++){
                        for(int pre_step_r2=r2-1;pre_step_r2<=r2;pre_step_r2++){
                            if(pre_step_r1>=0&&pre_step_r2>=0)
                                dp2[r1][r2]=max(dp2[r1][r2],dp[pre_step_r1][pre_step_r2]+val);
                        }
                    }
                }
            }
            dp=dp2;
            
        }
        return dp[n-1][n-1];
    }
};




class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        mygrid=grid;
        n=grid.size();
        memo=vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,INT_MIN)));
        return max(0,dp(0,0,0));
    }
private:
    int dp(int r1,int c1,int r2){
        int c2=r1+c1-r2;
        if(r1==n||r2==n||c1==n||c2==n) return -999999;
        else if(mygrid[r1][c1]==-1||mygrid[r2][c2]==-1)return -999999;
        else if(r1==n-1&&c1==n-1) return mygrid[r1][c1];
        else if(memo[r1][c1][r2]!=INT_MIN)return memo[r1][c1][r2];
        
        else{
            int ans=mygrid[r1][c1];
            if(c1!=c2) ans+=mygrid[r2][c2];
            ans+=max(max(dp(r1+1,c1,r2+1),dp(r1+1,c1,r2)),max(dp(r1,c1+1,r2),dp(r1,c1+1,r2+1)));
            memo[r1][c1][r2]=ans;
            return ans;
        }
        
    }
    vector<vector<vector<int>>> memo;
    vector<vector<int>> mygrid;
    int n;
};



class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
      
        int res = 0;
        dfs_forward(grid, 0, 0, 0, res);
        return res;
    }
private:
    void dfs_forward(vector<vector<int>>& grid, int i, int j, int temp, int& res) {
        //if(i==2&&j==6){
        //    int temp22=22;
        //}
        if (allow_move(grid, i, j)) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
               
                if (i == grid.size() - 1 && j == grid.size() - 1) {
                    //之前不行的问题就出现在这里，这里没有复原现场，导致，下一次dfs时，该处的1并没有被累加到！！！！2022-3-29
                    dfs_backward(grid, i, j, temp+1, res);
                    grid[i][j]=1;
                    return;
                }
                for (int k = 0; k < forward_dir.size(); k++) {
                   // moves.push_back(vector<int>{i,j});
                    dfs_forward(grid, i + forward_dir[k][0], j + forward_dir[k][1], temp+1, res);
                   // moves.pop_back();
                }
                
                grid[i][j] = 1;
            }
            else {
                if (i == grid.size() - 1 && j == grid.size() - 1) { dfs_backward(grid, i, j, temp, res); return; }
                
                for (int k = 0; k < forward_dir.size(); k++) {
                    //moves.push_back(vector<int>{i,j});
                    dfs_forward(grid, i + forward_dir[k][0], j + forward_dir[k][1], temp, res);
                    //moves.pop_back();
                }
                
            }
        }
    }

    void dfs_backward(vector<vector<int>>& grid, int i, int j, int temp, int& res) {
        //if(i==3&&j==0){
        //    int temp33=33;
        //}
        if (allow_move(grid, i, j)) {
            if (grid[i][j] == 1) {
                grid[i][j] = 0;
               
                for (int k = 0; k < backward_dir.size(); k++) {
                    //moves.push_back(vector<int>{i,j});
                    dfs_backward(grid, i + backward_dir[k][0], j + backward_dir[k][1], temp + 1, res);
                    //moves.pop_back();
                    
                }
                grid[i][j] = 1;
                if (i == 0 && j ==0) { res=max(res,temp+1); return; }
            }
            else {
                
                for (int k = 0; k < backward_dir.size(); k++) {
                    //moves.push_back(vector<int>{i,j});
                    dfs_backward(grid, i + backward_dir[k][0], j + backward_dir[k][1], temp, res);
                    //moves.pop_back();
                }
                if (i == 0 && j == 0) { res = max(res, temp); return; }
            }
        }
    }

    bool allow_move(const vector<vector<int>>& grid,int i, int j) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n)return false;
        if (grid[i][j] == -1)return false;
        return true;
    }

private:
    vector<vector<int>> forward_dir = { {0,1},{1,0} };
    vector<vector<int>> backward_dir = { {-1,0},{0,-1} };
    //vector<vector<int>> moves;
     
};

int main(){
    vector<vector<int>> grids={{1,1,1,1,0,0,0},
                                {0,0,0,1,0,0,0},
                                {0,0,0,1,0,0,1},
                                {1,0,0,1,0,0,0},
                                {0,0,0,1,0,0,0},
                                {0,0,0,1,0,0,0},
                                {0,0,0,1,1,1,1}};
    Solution3 mysolu;
    int res=mysolu.cherryPickup(grids);
    return 0;
}
