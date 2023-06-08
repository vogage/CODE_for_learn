//
//  522_Longest Uncommon Subsequence II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/8.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;



class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<int, unordered_map<string, int>> StrMap;
        priority_queue<int,vector<int>,less<int>> StrSizeQueue;
        for(int i=0;i<strs.size();i++){
            int n=strs[i].size();
            if(StrMap.find(n)==StrMap.end()){
                StrSizeQueue.push(n);
            }
            StrMap[n][strs[i]]++;
        }
        vector<int> Candidates;
        while(!StrSizeQueue.empty()){
            int TempSize=StrSizeQueue.top();
            StrSizeQueue.pop();
            
            for(auto m:StrMap[TempSize]){
                if(m.second>1) continue;
                else{
                    bool HaveSubCommonStr=false;
                    for(int j=0;j<Candidates.size();j++){
                        for(auto m2:StrMap[Candidates[j]]){
                            if(is_sub_str(m2.first, m.first)){
                                HaveSubCommonStr=true;
                            }
                        }
                    }
                    if(!HaveSubCommonStr)return TempSize;
                }
            }
            Candidates.push_back(TempSize);
        }
        
        
        return -1;
    }
private:
    bool is_sub_str(const string &parent,const string &son){
        int j=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==son[j]) j++;
        }
        return j==son.size();
    }
    
};

int main(){
    Solution mysolu;
    vector<string> strs = {"aba","cdc","eae"};
    vector<string> strs2={"aaa","aaa","aa"};
    int res=mysolu.findLUSlength(strs2);
    return 0;
}
