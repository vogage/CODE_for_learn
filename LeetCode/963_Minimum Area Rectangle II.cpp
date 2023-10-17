//
//  963_Minimum Area Rectangle II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/12.
//

#include <stdio.h>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        double res=numeric_limits<double>::max();
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j)continue;
                vector<int> boarder1={points[j][0]-points[i][0],points[j][1]-points[i][1]};
                for(int m=0;m<points.size();m++){
                    if(m==i||m==j)continue;
                    vector<int> boarder2={points[m][0]-points[i][0],points[m][1]-points[i][1]};
                    if(boarder1[0]*boarder2[0]+boarder1[1]*boarder2[1]!=0)continue;
                    for(int n=0;n<points.size();n++){
                        if(m==n||n==i||n==j)continue;
                        vector<int> boarder3={points[n][0]-points[j][0],points[n][1]-points[j][1]};
                        vector<int> boarder4={points[m][0]-points[n][0],points[m][1]-points[n][1]};
                        if(boarder3[0]*boarder1[0]+boarder3[1]*boarder1[1]!=0) continue;
                        if((boarder3[0]*boarder3[0]+boarder3[1]*boarder3[1]==boarder2[0]*boarder2[0]+boarder2[1]*boarder2[1])&&
                           (boarder1[0]*boarder1[0]+boarder4[1]*boarder4[1]==boarder1[0]*boarder1[0]+boarder4[1]*boarder4[1])){
                            res=min(res,sqrt(boarder3[0]*boarder3[0]+boarder3[1]*boarder3[1])*sqrt(boarder1[0]*boarder1[0]+boarder1[1]*boarder1[1]));
                        }
                    }
                }
            }
        }
        return res==numeric_limits<double>::max()?0:res;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> points= {{1,2},{2,1},{1,0},{0,1}};
    vector<vector<int>> points1={{0,1},{2,1},{1,1},{1,0},{2,0}};
    double res=mysolu.minAreaFreeRect(points);
    return 0;
}
