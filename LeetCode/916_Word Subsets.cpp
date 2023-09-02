//
//  916_Word Subsets.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/26.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> UniMap;
        universal_map(words2,UniMap);
        vector<string> res;
        for(int i=0;i<words1.size();i++){
            if(judege_sub(UniMap, words1[i])) res.push_back(words1[i]);
        }
        return res;
    }
private:
    bool judege_sub(unordered_map<char, int>& UniMap,string& w){
        unordered_map<char, int> wordMap;
        for(int i=0;i<w.size();i++){
            wordMap[w[i]]++;
        }
        for(auto m:UniMap){
            if(wordMap[m.first]<m.second)return false;
        }
        return true;
    }
    
    void universal_map(vector<string>& words,unordered_map<char, int>& UniMap){
        for(int i=0;i<words.size();i++){
            unordered_map<char, int> WordMap;
            for(int j=0;j<words[i].size();j++){
                WordMap[words[i][j]]++;
            }
            for(auto m:WordMap){
                UniMap[m.first]=max(UniMap[m.first],m.second);
            }
        }
    }
};

int main(){
    Solution mysolu;
    vector<string> words1={"amazon","apple","facebook","google","leetcode"};
    vector<string> words2={"l","e"};
    vector<string> res=mysolu.wordSubsets(words1, words2);
    return 0;
}
