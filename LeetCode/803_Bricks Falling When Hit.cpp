//
//  803_Bricks Falling When Hit.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/6.
//

#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        dir={{0,1},{0,-1},{1,0},{-1,0}};
        n=grid.size();
        m=grid[0].size();
        vector<int> res;
        //step1 update the hit
        for(int i=0;i<hits.size();i++){
            grid[hits[i][0]][hits[i][1]]--;
        }
        //update the breck not fall after hit
        for(int i=0;i<m;i++){
            //dfs search for the brick not fall
            if(grid[0][i]==1) update_the_brick_not_fall(grid,i);
        }
        for(int i=hits.size()-1;i>=0;i--){
            res.push_back(cal_falled_bricks(grid,hits[i]));
           
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
private:
    int cal_falled_bricks(vector<vector<int>>&grid,vector<int> hit){
        int i=hit[0];
        int j=hit[1];
        if(grid[i][j]==-1) return 0;
        // dfs search the connected bricks
      
        queue<int> Que;
        unordered_set<int> visited;
        
        bool isConnectedToTop=false;
        Que.push(i*m+j);
        visited.insert(i*m+j);
        while(!Que.empty()){
            int index=Que.front();
            Que.pop();
            int ni=index/m;
            int nj=index%m;
            
            for(int i=0;i<dir.size();i++){
                int ti=ni+dir[i][0];
                int tj=nj+dir[i][1];
                int tindex=ti*m+tj;
                if(is_step_index(grid, ti, tj)&&visited.find(tindex)==visited.end()){
                    if(grid[ti][tj]==2) isConnectedToTop=true;
                    else if(grid[ti][tj]==1){
                        
                        Que.push(tindex);
                        visited.insert(tindex);
                    }
                }
            }
        }
        
        if(grid[i][j]==0){
            if(i==0){
                grid[i][j]=2;
                isConnectedToTop=true;
            }
            else grid[i][j]=1;
        }
    
        
        if(isConnectedToTop){
            for(auto id:visited){
                grid[id/m][id%m]=2;
            }
            return visited.size()-1;
        }
  
        return 0;
    }
    
    void update_the_brick_not_fall(vector<vector<int>> &grid,int i){
        queue<int> Que;
        unordered_set<int> visited;
        Que.push(i);
        visited.insert(i);
        grid[0][i]=2;
        while(!Que.empty()){
            int index=Que.front();
            Que.pop();
            int ni=index/m;
            int nj=index%m;
            for(int i=0;i<dir.size();i++){
                int ti=ni+dir[i][0];
                int tj=nj+dir[i][1];
                int tindex=ti*m+tj;
                if(is_step_index(grid, ti, tj)&&grid[ti][tj]==1&&visited.find(tindex)==visited.end()){
                    visited.insert(tindex);
                    Que.push(tindex);
                    grid[ti][tj]=2;
                }
            }
        }
        
    }
    
    bool is_step_index(vector<vector<int>>& grid,int i,int j){

        return i>=0&&i<n&&j>=0&&j<m;
    }
private:
    vector<vector<int>> dir;

    int n;
    int m;
    
};



int main(){
    Solution mysolu;
    vector<vector<int>> grid ={{1,0,0,0},{1,1,1,0}};
    vector<vector<int>> hits = {{1,0}};
    
//    grid =
//    [[1],[1],[1],[1],[1]]
//    hits =
//    [[3,0],[4,0],[1,0],[2,0],[0,0]]
//
    vector<vector<int>> grid1={{1},{1},{1},{1},{1}};
    vector<vector<int>> hits1={{3,0},{4,0},{1,0},{2,0},{0,0}};
    
    // grid = [[1,0,1],[1,1,1]]
    // hits = [[0,0],[0,2],[1,1]]
    vector<vector<int>> grid2={{1,0,1},{1,1,1}};
    vector<vector<int>> hits2={{0,0},{0,2},{1,1}};
    vector<int> res=mysolu.hitBricks(grid2, hits2);
    return 0;
}
