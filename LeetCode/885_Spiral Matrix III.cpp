//
//  885_Spiral Matrix III.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/18.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int cnt=rows*cols-1;
        int step=1;
        int i=0;
        vector<vector<int>> res;
        res.push_back({rStart,cStart});
        while(cnt){
            
            vector<int> d=dir[i%4];
            for(int s=1;s<=step;s++){
                rStart+=d[0];
                cStart+=d[1];
                if(rStart>=0&&rStart<rows&&cStart>=0&&cStart<cols){
                    res.push_back({rStart,cStart});
                    cnt--;
                    
                }
            }
            i++;
            if(i%2==0) step++;
        }
        return res;
    }
};



int main(){
    Solution mysolu;
    int rows = 1, cols = 4, rStart = 0, cStart = 0;
    int rows1=5,cols1=6,rStart1=1,cStart1=4;
    vector<vector<int>> res=mysolu.spiralMatrixIII(rows1, cols1, rStart1, cStart1);
    return 0;
}

