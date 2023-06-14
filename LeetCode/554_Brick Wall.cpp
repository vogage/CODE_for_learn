//
//  554_Brick Wall.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/12.
//

#include <stdio.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> WidthMap;
        for(int i=0;i<wall.size();i++){
            int WidthSum=0;
            for(int j=0;j<wall[i].size()-1;j++){
                WidthSum+=wall[i][j];
                WidthMap[WidthSum]++;
            }
        }
        int MaxSumEdge=0;
        for(auto m:WidthMap){
            if(m.second>MaxSumEdge) MaxSumEdge=m.second;
        }
        return wall.size()-MaxSumEdge;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> wall={{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    int res=mysolu.leastBricks(wall);
    return 0;
}
