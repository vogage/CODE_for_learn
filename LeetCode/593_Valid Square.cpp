//
//  593_Valid Square.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/15.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<long long> DistanceVec;
        DistanceVec.push_back(cal_distance(p1, p2));
        DistanceVec.push_back(cal_distance(p1, p3));
        DistanceVec.push_back(cal_distance(p1, p4));
        DistanceVec.push_back(cal_distance(p2, p3));
        DistanceVec.push_back(cal_distance(p2, p4));
        DistanceVec.push_back(cal_distance(p3, p4));
        sort(DistanceVec.begin(),DistanceVec.end(),less<long long>());
        for(int i=1;i<4;i++){
            if(DistanceVec[0]!=DistanceVec[i]) return false;
        }
        return true;
    }
private:
    long long cal_distance(vector<int>& p1,vector<int>& p2){
        return (long long)(p2[0]-p1[0])*(long long)(p2[0]-p1[0])+(long long)(p2[1]-p1[1])*(long long)(p2[1]-p1[1]);
    }
};

int main(){
    Solution mysolu;
    vector<int> p1={0,0};
    vector<int> p2={1,1};
    vector<int> p3={1,0};
    vector<int> p4={0,1};
    
    bool res=mysolu.validSquare(p1, p2, p3, p4);
    return 0;
}
