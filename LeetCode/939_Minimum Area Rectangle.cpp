//
//  939_Minimum Area Rectangle.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/4.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        //construct the data of retangls
        map<int,set<int>> RowMap;
        map<int,set<int>> ColMap;
        int res=INT_MAX;
        for(int i=0;i<points.size();i++){
            RowMap[points[i][0]].insert(points[i][1]);
            ColMap[points[i][1]].insert(points[i][0]);
        }
        for(auto Row:RowMap){
            auto Rowleft=Row.second.begin();
            while(Rowleft!=Row.second.end()){
                auto Rowright=Rowleft;
                Rowright++;
                if(Rowright==Row.second.end()) break;
                cout<<*Rowright<<endl;
                while(Rowright!=Row.second.end()){
                    for(auto Downleft=ColMap[*Rowleft].upper_bound(Row.first);Downleft!=ColMap[*Rowleft].end();Downleft++){
                        if(ColMap[*Rowright].find(*Downleft)!=ColMap[*Rowright].end()) res=min(res,(*Downleft-Row.first)*(*Rowright-*Rowleft));
                    }
                    Rowright++;
                }
                Rowleft++;
            }
           
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> points={{1,1},{1,3},{3,1},{3,3},{2,2}};
    int res=mysolu.minAreaRect(points);
    return 0;
}


