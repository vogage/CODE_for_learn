//
//  1007_Minimum Domino Rotations For Equal Row.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/23.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> RowMap;
        unordered_map<int, int> TopsMap;
        unordered_map<int, int> BottomsMap;
        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]) RowMap[tops[i]]++;
            else{
                RowMap[tops[i]]++;
                RowMap[bottoms[i]]++;
            }
            TopsMap[tops[i]]++;
            BottomsMap[bottoms[i]]++;
        }
        for(auto m:RowMap){
            if(m.second==tops.size()) return tops.size()-max(TopsMap[m.first],BottomsMap[m.first]);
        }
        return -1;
    }
};


int main(){
    return 0;
}
