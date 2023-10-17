//
//  1041_Robot Bounded In Circle.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/10.
//

#include <stdio.h>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int Rcnt=0; //left+1,right-1
        vector<vector<int>> dir={{0,1},{-1,0},{0,-1},{1,0}};
        vector<int> pos={0,0};
        unordered_set<int> xpos;
        xpos.insert(0);
        unordered_set<int> ypos;
        ypos.insert(0);
        
        int dir_index=0;
        for(auto c:instructions){
            if(c=='L'){ 
                Rcnt--;
                dir_index=(dir_index+1)%4;
            }
            else if(c=='R'){
                Rcnt++;
                dir_index=(dir_index+3)%4;
            }else{
                pos[0]+=dir[dir_index][0];
                pos[1]+=dir[dir_index][1];
                xpos.insert(pos[0]);
                ypos.insert(pos[1]);
            }
        }
        if(Rcnt%4==0){
            return pos[0]==0&&pos[1]==0;
        }else{
            return xpos.size()>1||ypos.size()>1;
        }
    }
};

int main(){
    Solution mysolu;
    string instructions = "GGLLGG";
    string instructions1 = "GLGLGGLGL";
    string instructions2= "GLRLLGLL";
    bool res=mysolu.isRobotBounded(instructions2);
    return 0;
}
