//
//  853_Car Fleet.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/7.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double> TimeMap;
        for(int i=0;i<position.size();i++){
            TimeMap[-position[i]]=(double)(target-position[i])/speed[i];
        }
        int res=0;
        double cur=0;
        for(auto m:TimeMap){
            if(m.second>cur){
                cur=m.second;
                res++;
            }
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    int target = 12;
    vector<int> position ={10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};
    
    
    int target1 = 20;
    vector<int> position1 = {6,2,17};
    vector<int> speed1 ={3,9,2};
    
    int target2 = 13;
    vector<int> position2 ={10,2,5,7,4,6,11};
    vector<int> speed2 = {7,5,10,5,9,4,1};
    
    int res=mysolu.carFleet(target2, position2, speed2);
    return 0;
}
