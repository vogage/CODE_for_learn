//
//  720_Longest Word in Dictionary.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/29.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;



class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end());
        string res="";
        unordered_set<string> StrSet;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            if(StrSet.find(str.substr(0,str.size()-1))!=StrSet.end()){
                StrSet.insert(str);
                res=cmp(res,str);
            }
            if(str.size()==1) StrSet.insert(str);
        }
        return res;
    }
private:

    string cmp(string &str1,string &str2){
        if(str1.size()!=str2.size()) return str1.size()>str2.size()?str1:str2;
        else return min(str1,str2);
    }
};

int main(){
    Solution mysolu;
    vector<string> words={"w","wo","wor","worl","world"};
    vector<string> words1={"a","banana","app","appl","ap","apply","apple"};
    vector<string> words2={"b","br","bre","brea","break","breakf","breakfa","breakfas","breakfast","l","lu","lun","lunc","lunch","d","di","din","dinn","dinne","dinner"};
    vector<string> words3={"m","mo","moc","moch","mocha","l","la","lat","latt","latte","c","ca","cat"};
    vector<string> words4={"ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d"};
    vector<string> words5={"n","j","sl","yyd","slo","jk","jkdt","y","yy"};
    vector<string> words6={"rac","rs","ra","on","r","otif","o","onpdu","rsf","rs","ot","oti","racy","onpd"};
    string res=mysolu.longestWord(words6);
    return 0;
}
