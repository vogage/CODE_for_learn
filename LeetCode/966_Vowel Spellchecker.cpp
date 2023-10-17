//
//  966_Vowel Spellchecker.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/13.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

//Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
//
//For a given query word, the spell checker handles two categories of spelling mistakes:
//
//Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
//Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually,
//it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
//Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
//Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
//In addition, the spell checker operates under the following precedence rules:
//
//When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
//When the query matches a word up to capitlization, you should return the first such match in the wordlist.
//When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
//If the query has no matches in the wordlist, you should return the empty string.
//Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

struct Tire{
    vector<pair<char,Tire*>> CharVec;
    bool isword;
    Tire():isword(false),CharVec(vector<pair<char, Tire*>>()){}
};

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> WordlistSet(wordlist.begin(),wordlist.end());
        unordered_map<string, string> CapitMap;
        unordered_map<string, string> NoVowelMap;
        VowelSet={'a', 'e', 'i', 'o', 'u'};
        for(int i=0;i<wordlist.size();i++){
            string temp=to_lower(wordlist[i]);
            if(CapitMap.find(temp)==CapitMap.end()) CapitMap[temp]=wordlist[i];
            string temp2=to_no_vowel(temp);
            if(NoVowelMap.find(temp2)==NoVowelMap.end()) NoVowelMap[temp2]=wordlist[i];
        }
        vector<string> res;
        for(int i=0;i<queries.size();i++){
            string temp=to_lower(queries[i]);
            string temp2=to_no_vowel(temp);
            if(WordlistSet.find(queries[i])!=WordlistSet.end()){
                res.push_back(queries[i]); continue;
            }else if(CapitMap.find(temp)!=CapitMap.end()){
                res.push_back(CapitMap[temp]);continue;
            }else if(NoVowelMap.find(temp2)!=NoVowelMap.end()){
                res.push_back(NoVowelMap[temp2]);continue;
            }else{
                res.push_back("");
            }
        }
        return res;
    }
private:
    string to_lower(string str){
        string res="";
        for(int i=0;i<str.size();i++){
            res+=tolower(str[i]);
        }
        return res;
    }
    string to_no_vowel(string& str){
        string res="";
        for(int i=0;i<str.size();i++){
            if(VowelSet.find(str[i])!=VowelSet.end()){
                res+="#";
            }else{
                res+=str[i];
            }
        }
        return res;
    }
private:
    unordered_set<char> VowelSet;
};

int main(){
    Solution mysolu;
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> res=mysolu.spellchecker(wordlist, queries);
    //["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
    vector<string> wordlist1 = {"zeo","Zuo"};
    vector<string> queries1 = {"zuo"};
    vector<string> res1=mysolu.spellchecker(wordlist1, queries1);
    return 0;
}
