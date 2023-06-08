//
//  495_Teemo Attacking.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/6.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)return 0;
        if(timeSeries.size()==1)return duration;
        int PoisonEnd=timeSeries[0]+duration;
        int res=0;
        for(int i=1;i<timeSeries.size();i++){
            if(timeSeries[i]<PoisonEnd){
                //reset time
                res+=timeSeries[i]-timeSeries[i-1];
                
            }else{
                //renew time
                res+=duration;
               
            }
            PoisonEnd=timeSeries[i]+duration;
        }
        return res+=duration;
    }
};



int main(){
    Solution mysolu;
    vector<int> timeSeries={1,2};
    vector<int> timeSeries1={1,4};
    int duration=2;
    int res=mysolu.findPoisonedDuration(timeSeries1, duration);
    return 0;
}
