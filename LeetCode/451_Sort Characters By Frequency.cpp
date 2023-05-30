//
//  451_Sort Characters By Frequency.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/28.
//

#include <stdio.h>
#include<string>
#include<unordered_map>
#include<queue>

using namespace std;

struct cmp{
    bool operator()(pair<char,int> &a,pair<char,int> &b) const
    {
        return a.second<b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> str_map;
        for(auto c:s)str_map[c]++;
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pri_que;
        for(auto m:str_map)pri_que.push(m);
        string res="";
        while(!pri_que.empty()){
            pair<char,int> p=pri_que.top();
            pri_que.pop();
            for(int i=0;i<p.second;i++){
                res+=p.first;
            }
        }
        return res;
    }
};


int main(){
    
    Solution mysolu;
    
    string str="tree";
    string str2="cccaaa";
    string res=mysolu.frequencySort(str2);
    
    
    return 0;
}
