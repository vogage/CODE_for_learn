//
//  864_Shortest Path to Get All Keys.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/13.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {

        dir={{-1,0},{1,0},{0,-1},{0,1}};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m,vector<bool>(64,false)));
        queue<pair<int,int>> que;
        int path=0;
        int KNum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='@') {
                    que.push(pair<int,int>(i*m+j,0));
                    visited[i][j][0]=true;
                }
                else if(grid[i][j]>='A'&&grid[i][j]<='Z') KNum++;
            }
        }
        
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                pair<int,int> cur=que.front();
                que.pop();
                int curi=cur.first/m;
                int curj=cur.first%m;
                if(cur.second==(1<<KNum)-1) return path;
             
                    for(int k=0;k<dir.size();k++){
                        int furi=curi+dir[k][0];
                        int furj=curj+dir[k][1];
                        int furkeys=cur.second;
                        if(furi>=0&&furi<n&&furj>=0&&furj<m){
                            if(grid[furi][furj]=='#') continue;
                            else if(grid[furi][furj]>='a'&&grid[furi][furj]<='z'){
                                furkeys=1<<(grid[furi][furj]-'a')|cur.second;
                            }else if(grid[furi][furj]>='A'&&grid[furi][furj]<='Z'){
                                if(!(furkeys&(1<<(grid[furi][furj]-'A')))) continue;
                            }
                            if(visited[furi][furj][furkeys]) continue;
                            que.push(pair<int,int>(furi*m+furj,furkeys));
                            visited[furi][furj][furkeys]=true;
                        }
                    }
            }
            path++;
        }
        return -1;
    }
    

private:
    vector<vector<int>> dir;
};

int main(){
    Solution mysolu;
    vector<string> grid={"@.a..","###.#","b.A.B"};
    vector<string> grid2={"@..aA","..B#.","....b"};
    vector<string> grid3={".@aA"};
    vector<string> grid4={"@...a",".###A","b.BCc"};
    int res=mysolu.shortestPathAllKeys(grid4);
    return 0;
}
