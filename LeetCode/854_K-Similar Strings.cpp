//
//  854_K-Similar Strings.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/8.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

//1 <= s1.length <= 20
//s2.length == s1.length
//s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//s2 is an anagram of s1.

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        unordered_set<string> visited;
        queue<string> Qstr;
        Qstr.push(s2);
        visited.insert(s2);
        int level=0;
        while(!Qstr.empty()){
            int sz=Qstr.size();
            for(int i=0;i<sz;i++){
                string temp=Qstr.front();
                Qstr.pop();
                if(temp==s1) return level;
                vector<string> neighbours=get_meaningful_candidate(s1, temp);
                for(auto neigh:neighbours){
                    if(visited.find(neigh)==visited.end()) Qstr.push(neigh);
                }
            }
            level++;
        }
        return -1;
    }


private:
    vector<string> get_meaningful_candidate(string& s1,string &s2){
        vector<string> res;
        int index=0;
        for(;index<s1.size();index++){
            if(s1[index]!=s2[index]) break;
        }
        int j=index+1;
        for(;j<s1.size();j++){
            if(s1[index]==s2[j]){
                char_swap(index, j, s2);
                res.push_back(s2);
                char_swap(j, index, s2);
            }
        }
        return res;
    }
    
    void char_swap(int i,int j,string& str){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    
    unordered_map<string, int> StepMap;
};


int main(){
    Solution mysolu;
    string s1="abcde";
    string s2="bdcae";
    string s11="abcdeabcdeabcdeabcde";
    string s12="aaaabbbbccccddddeeee";
    int res=mysolu.kSimilarity(s11, s12);
    return 0;
}
