//
//  539_Minimum Time Difference.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/9.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //"HH:MM" change to miniutes
        int n=timePoints.size();
        vector<int> MiniutesVec(n,0);
        for(int i=0;i<n;i++){
            MiniutesVec[i]=ToMiniutes(timePoints[i]);
            if(MiniutesVec[i]==0) MiniutesVec.push_back(24*60);
        }
        sort(MiniutesVec.begin(),MiniutesVec.end());
        int res=INT_MAX;
        for(int i=1;i<MiniutesVec.size();i++){
            res=min(res,MiniutesVec[i]-MiniutesVec[i-1]);
        }
        return res;
    }
private:
    int ToMiniutes(const string &str){
        return stoi(str.substr(0,2))*60+stoi(str.substr(3,2));
    }
};


int main(){
    Solution mysolu;
    vector<string> timePoints={"23:59","00:00"};
    int res=mysolu.findMinDifference(timePoints);
    return 0;
}
