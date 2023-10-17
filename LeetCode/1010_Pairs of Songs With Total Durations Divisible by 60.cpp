//
//  1010_Pairs of Songs With Total Durations Divisible by 60.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/23.
//

#include <stdio.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> TimeMap;
        int res=0;
        for(int i=0;i<time.size();i++){
            int t=time[i]%60;
            res+=TimeMap[60-t];
            if(t!=0) TimeMap[t]++;
            else TimeMap[60]++;
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int>  time = {30,20,150,100,40};
    vector<int>  time1={60,60,60};
    int res=mysolu.numPairsDivisibleBy60(time1);
    return 0;
}
