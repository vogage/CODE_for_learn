//
//  874_Walking Robot Simulation.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/15.
//

#include <stdio.h>
#include <vector>
#include <set>
#include <map>

using namespace std;

//-2: Turn left 90 degrees.
//-1: Turn right 90 degrees.
//1 <= k <= 9: Move forward k units, one unit at a time.

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<int,set<int>> XdirObstaclesMap;
        map<int,set<int>> YdirObstaclesMap;
        for(int i=0;i<obstacles.size();i++){
            XdirObstaclesMap[obstacles[i][1]].insert(obstacles[i][0]);
            YdirObstaclesMap[obstacles[i][0]].insert(obstacles[i][1]);
        }
       // if(XdirObstaclesMap.find(0)!=XdirObstaclesMap.end()&&XdirObstaclesMap[0].find(0)!=XdirObstaclesMap[0].end())return 0;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int dir_state=0;
        vector<int> rob_state={0,0};
        int res=0;//oular distance
        for(int i=0;i<commands.size();i++){
            if(commands[i]==-1){
                dir_state=(dir_state+1)%4;
            }else if(commands[i]==-2){
                dir_state=(dir_state-1+4)%4;
            }else{
                //judge the direction closet obstacle
                int dist=INT_MAX;
                if(dir[dir_state][0]==0&&YdirObstaclesMap.find(rob_state[0])!=YdirObstaclesMap.end()){
                    //north or south dir
                    
                    if(dir[dir_state][1]==1){
                        auto it=YdirObstaclesMap[rob_state[0]].upper_bound(rob_state[1]);
                        if(it!=YdirObstaclesMap[rob_state[0]].end()) dist=*it-rob_state[1]-1;
                    }else{
                        auto it=YdirObstaclesMap[rob_state[0]].lower_bound(rob_state[1]);
                        if(it!=YdirObstaclesMap[rob_state[0]].begin()){
                            it--;
                            dist=rob_state[1]-*it-1;
                        }
                    }
                }else if(dir[dir_state][1]==0&&XdirObstaclesMap.find(rob_state[1])!=XdirObstaclesMap.end()){
                    //east or west dir
                    
                    if(dir[dir_state][0]==1){
                        auto it=XdirObstaclesMap[rob_state[1]].upper_bound(rob_state[0]);
                        if(it!=XdirObstaclesMap[rob_state[1]].end()) dist=*it-rob_state[0]-1;
                    }else{
                        auto it=XdirObstaclesMap[rob_state[1]].lower_bound(rob_state[0]);
                        if(it!=XdirObstaclesMap[rob_state[1]].begin()){
                            it--;
                            dist=rob_state[0]-*it-1;
                        }
                    }
                }
                rob_state[0]+=min(commands[i],dist)*dir[dir_state][0];
                rob_state[1]+=min(commands[i],dist)*dir[dir_state][1];
                res=max(res,rob_state[0]*rob_state[0]+rob_state[1]*rob_state[1]);
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    //commands = [4,-1,4,-2,4], obstacles = [[2,4]]
    vector<int> commands={4,-1,4,-2,4};
    vector<vector<int>> obstacles={{2,4}};
    vector<int> commands1={-2,-1,-2,3,7};
    vector<vector<int>> obstacles1={{1,-3},{2,-3},{4,0},{-2,5},{-5,2},{0,0},{4,-4},{-2,-5},{-1,-2},{0,2}};
    int res=mysolu.robotSim(commands1, obstacles1);
    return 0;
}
