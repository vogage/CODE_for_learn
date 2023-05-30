//
//  452_Minimum Number of Arrows to Burst Balloons.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/28.
//

#include <stdio.h>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(vector<int> &a,vector<int> &b)
{
    return a[0]<b[0];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end(),cmp);
        vector<int> tmp=points[0];
        int cnt=1;
        for(int i=1;i<points.size();i++){
            if(tmp[1]<points[i][0]){
                cnt++;
                tmp=points[i];
            }else{
                tmp[0]=points[i][0];
                tmp[1]=min(points[i][1],tmp[1]);
            }
        }
        return cnt;
        
    }
};

int main(){
    int res=0;
    Solution mysolu;
    vector<vector<int>> points={{10,16},{2,8},{1,6},{7,12}};
    vector<vector<int>> points1={{1,2},{2,3},{3,4},{4,5}};
    res=mysolu.findMinArrowShots(points1);
    return 0;
}
