//
//  890_Find and Replace Pattern.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/19.
//

#include <stdio.h>
#include<string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(ismatch(words[i],pattern)) res.push_back(words[i]);
        }
        return res;
    }
private:
    bool ismatch(string str,string pattern){
        unordered_map<char, char> word2patternMap;
        unordered_map<char, char> pattern2wordMap;
        for(int i=0;i<str.size();i++){
            if(word2patternMap.find(str[i])==word2patternMap.end()&&pattern2wordMap.find(pattern[i])==pattern2wordMap.end()){
                    word2patternMap[str[i]]=pattern[i];
                    pattern2wordMap[pattern[i]]=str[i];
            }else if(word2patternMap.find(str[i])!=word2patternMap.end()&&pattern2wordMap.find(pattern[i])!=pattern2wordMap.end()){
                
               
            }else{
                return false;
            }
            str[i]=word2patternMap[str[i]];
        }
        return str==pattern;
    }
};


int main(){
    Solution mysolu;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    
    vector<string> res=mysolu.findAndReplacePattern(words, pattern);
    return 0;
}
