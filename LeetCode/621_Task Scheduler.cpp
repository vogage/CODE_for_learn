//
//  621_Task Scheduler.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/16.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> CharMap;
        pair<int,int> cnt;
        for(int i=0;i<tasks.size();i++){
            CharMap[tasks[i]]++;
        }
        for(auto m:CharMap){
            if(cnt.first<m.second){
                cnt.first=m.second;
                cnt.second=1;
            }else if(cnt.first==m.second){
                cnt.second++;
            }else{
                continue;
            }
        }
        return max((int)tasks.size(),(n+1)*(cnt.first-1)+cnt.second);
    }
};



int main(){
    Solution mysolu;
//    tasks = ["A","A","A","B","B","B"], n = 2
//    A -> B -> idle -> A -> B -> idle -> A -> B
    
    vector<char> tasks={'A','A','A','B','B','B'};
    int res=mysolu.leastInterval(tasks, 2);
    return 0;
}
