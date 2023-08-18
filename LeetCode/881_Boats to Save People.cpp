//
//  881_Boats to Save People.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/17.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end(),greater<int>());
        priority_queue<int,vector<int>,less<int>> que;
       
        int cnt=0; //two people in the boat
        for(int i=0;i<people.size();i++){
            
          
            if(que.empty()||que.top()<people[i]){
                que.push(limit-people[i]);// a new boat
            }else{
                que.pop();
                cnt++;
               
            }
        }
        return que.size()+cnt;
    }
};

int main(){
    Solution mysolu;
    vector<int> people = {3,2,2,1};
    vector<int> people1={3,2,3,2,2};
    int limit = 3;
    int limit1=6;
    int res=mysolu.numRescueBoats(people1, limit1);
    return 0;
}
