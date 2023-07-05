//
//  692_Top K Frequent Words.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/28.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class cmp{
public:
    bool operator ()(const pair<string,int>& p1,const pair<string,int>& p2){
        if(p1.second!=p2.second) return p1.second<p2.second;
        else return p1.first<p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> StrMap;
        for(int i=0;i<words.size();i++) StrMap[words[i]]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        for(auto m:StrMap) pq.push(m);
        vector<string> res;
        for(int i=0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main(){
  
    return 0;
}
