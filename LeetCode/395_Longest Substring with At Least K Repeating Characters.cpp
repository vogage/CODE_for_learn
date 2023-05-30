//
//  395_Longest Substring with At Least K Repeating Characters.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/16.
//

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int countMap[26];
        int maxUnique = getMaxUniqueLetters(s);
        int result = 0;
        for (int currUnique = 1; currUnique <= maxUnique; currUnique++) {
            // reset countMap
            memset(countMap, 0, sizeof(countMap));
            int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
            while (windowEnd < s.size()) {
                // expand the sliding window
                if (unique <= currUnique) {
                    idx = s[windowEnd] - 'a';
                    if (countMap[idx] == 0) unique++;
                    countMap[idx]++;
                    if (countMap[idx] == k) countAtLeastK++;
                    windowEnd++;
                }
                // shrink the sliding window
                else {
                    idx = s[windowStart] - 'a';
                    if (countMap[idx] == k) countAtLeastK--;
                    countMap[idx]--;
                    if (countMap[idx] == 0) unique--;
                    windowStart++;
                }
                if (unique == currUnique && unique == countAtLeastK)
                    result = max(windowEnd - windowStart, result);
            }
        }

        return result;
    }

    // get the maximum number of unique letters in the string s
    int getMaxUniqueLetters(string s) {
        bool map[26] = {0};
        int maxUnique = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!map[s[i] - 'a']) {
                maxUnique++;
                map[s[i] - 'a'] = true;
            }
        }
        return maxUnique;
    }
};






class Solution3 {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char,int> str_map;
        int res=0;
        for(int i=0;i<s.size();i++) str_map[s[i]]++;
        int num_unique_char=str_map.size();
        str_map.clear();
        for(int cout=1;cout<=num_unique_char;cout++){
            unordered_set<char> unique_chars;
           
            for(int begin,end=0;end<s.size();end++){
                if(unique_chars.find(s[end])==unique_chars.end()){
                    if(unique_chars.size()<cout){
                        unique_chars.insert(s[end]);
                        str_map[s[end]]++;
                    }else{
                        //check the current substr is satified the at least k repeating characters rule
                        bool is_satisfied=true;
                        for(auto m:str_map){
                            if(m.second<k) {is_satisfied=false;break;}
                        }
                        if(is_satisfied) res=max(res,end-begin+1);
                        
                        //change the current characters for the substr
                        unique_chars.clear();
                        str_map.clear();
                        for(begin=end;begin>=0;begin--){
                            if(unique_chars.find(s[begin])==unique_chars.end()){
                                if(unique_chars.size()<cout){
                                    unique_chars.insert(s[begin]);
                                    str_map[s[begin]]++;
                                }else{
                                    break;
                                }
                           }else{
                               str_map[s[begin]]++;
                           }
                        }
                        
                    }
                }else{
                    str_map[s[end]]++;
                }
                
            }
        }
        return res;
        
    }
    
};

class Solution2 {
public:
    int longestSubstring(string s, int k) {
        res=0;
        substr_cal(s,0,s.size()-1,k);
        return res;
    }
    void substr_cal(string &s,int begin,int end,int k){
        if(end-begin+1<res)return;
        unordered_map<char,int> str_map;
        for(int i=begin;i<=end;i++){
            str_map[s[i]]++;
        }
        bool isvalid=true;
        for(int i=begin;i<=end;i++){
            if(str_map[s[i]]<k){
                isvalid=false;
                substr_cal(s,begin,i-1,k);
                substr_cal(s, i+1, end, k);
                break;
            }
        }
        if(isvalid) res=max(res,end-begin+1);
        return;
    }
    int res;
};


int main(){
    Solution mysolu;
    string s="ababbc";
    string s1="aaabb";
    int k=3;
    int res=mysolu.longestSubstring(s1,k);
    
    return 0;
}
