//
//  567_Permutation in String.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/15.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

//n other words, return true if one of s1's permutations is the substring of s2.
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<int, int> S1Map;
        unordered_map<int, int> S2Map;
        for(int i=0;i<s1.size();i++) S1Map[s1[i]]++;
       
        int index=s1.size()-1;
        
        while(index<s2.size()){
            int low=index-s1.size();
            int j=index;
            cout<<(j>index-s1.size())<<endl;
            cout<<index-s1.size()<<endl;
            cout<<s1.size()<<endl;
            cout<<index-(int)s1.size()<<endl;
            for(;j>index-s1.size();j--){
            //for(int j=index;j>low;j--){
                S2Map[s2[j]]++;
            }
            int steps=Cal_Steps(S1Map,S2Map);
            if(steps==0)return true;
            index+=steps;
            S2Map.clear();

        }
        return false;
    }
private:
    int Cal_Steps(const unordered_map<int, int>& m1,unordered_map<int, int>& m2){
        int res=0;
        for(auto m:m1){
            int temp=m.second-m2[m.first];
            res+=temp>0?temp:0;
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    
//Input: s1 = "ab", s2 = "eidbaooo"
//Output: true
//Explanation: s2 contains one permutation of s1 ("ba").
    string s1="ab";
    string s2="eidbaooo";
    string s11="rokx";
    string s12="otrxvfszxroxrzdsltg";
    bool res=mysolu.checkInclusion(s11, s12);
    
    return 0;
}
