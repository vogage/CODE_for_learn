//
//  1029_Two City Scheduling.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/12.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

//A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti],
//the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
//
//Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

class cmp{
public:
    bool operator()(vector<int>& v1,vector<int>& v2){
        return v1[1]-v1[0]>v2[1]-v2[0];
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<vector<int>,vector<vector<int>>,cmp> pque;
        int n=costs.size();
        for(int i=0;i<n/2;i++){
            pque.push(costs[i]);
        }
        int res=0;
        for(int i=n/2;i<n;i++){
            if(costs[i][1]-costs[i][0]>pque.top()[1]-pque.top()[0]){
                res+=pque.top()[1];
                pque.pop();
                pque.push(costs[i]);
            }else{
                res+=costs[i][1];
            }
        }
        while(!pque.empty()){
            res+=pque.top()[0];
            pque.pop();
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> costs={{10,20},{30,200},{400,50},{30,20}};
    int res=mysolu.twoCitySchedCost(costs);
    return 0;
}
