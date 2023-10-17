//
//  994_Rotting Oranges.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/19.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt=0;
        queue<int> que;
        int n=grid.size();
        int m=grid[0].size();
        unordered_set<int> visited;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) cnt++;
                else if(grid[i][j]==2) {
                    int temp=i*m+j;
                    que.push(temp);
                    visited.insert(temp);
                }
            }
        }
        int level=0;
      
        
        while(!que.empty()){
            if(cnt==0) break;
            int sz=que.size();
            for(int i=0;i<sz;i++){
                int qi=que.front()/m;
                int qj=que.front()%m;
                que.pop();
                for(int k=0;k<dir.size();k++){
                    int ki=qi+dir[k][0];
                    int kj=qj+dir[k][1];
                    int temp=ki*m+kj;
                    if(ki<0||ki>=n||kj<0||kj>=m)continue;
                    if(visited.find(temp)==visited.end()&&grid[ki][kj]==1){
                        cnt--;
                        visited.insert(temp);
                        que.push(temp);
                    }
                }
            }
            level++;
        }
        return cnt==0?level:-1;
    }
};
int main(){
    Solution mysolu;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
   
    vector<vector<int>> grid1={{2,2,2,1,1}};
    vector<vector<int>> grid2={{1},{2}};
    vector<vector<int>> grid3= {{2,1,1},{0,1,1},{1,0,1}};
    vector<vector<int>> grid4={{1},{2},{1},{1}};
    int res=mysolu.orangesRotting(grid4);
    return 0;
}

