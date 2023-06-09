//
//  524_Longest Word in Dictionary through Deleting.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/9.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        vector<int> IndexOfDictString(n,0);
        unordered_set<int> StrIndexSet;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<IndexOfDictString.size();j++){
                if(StrIndexSet.find(j)!=StrIndexSet.end()) continue;
                if(s[i]==dictionary[j][IndexOfDictString[j]]){
                    IndexOfDictString[j]++;
                    if(IndexOfDictString[j]==dictionary[j].size()) StrIndexSet.insert(j);
                }
            }
        }
        string res="";
        for(auto Id:StrIndexSet){
            res=cmp(res,dictionary[Id]);
        }
        return res;
    }
private:
    string cmp(const string& str1,const string &str2){
        if(str1.size()!=str2.size()) return str1.size()>str2.size()?str1:str2;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]) return str1[i]<str2[i]?str1:str2;
        }
        return  str1;
    }
};















struct Tire{
    bool StrEnd;
    vector<Tire*> leaf;
    Tire():StrEnd(false),leaf(vector<Tire*>(26,nullptr)){};
};

class Solution2 {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //construct the tires tree
        Root=new Tire();
        for(int i=0;i<dictionary.size();i++){
            Tire *temp=Root;
            for(int j=0;j<dictionary[i].size();j++){
                int CharIndex=dictionary[i][j]-'a';
                if(!temp->leaf[CharIndex])temp->leaf[CharIndex]=new Tire();
                temp=temp->leaf[CharIndex];
            }
            temp->StrEnd=true;
        }
        
        //find the longest word
        int n=s.size();
        string res="";
        dfs(s,0,Root,res,res);
        return res;
    }
private:
    void dfs(const string& s,int CharIndex,Tire *p,string temp,string& res){
        if(!p)return;
        //search the string
        if(p->StrEnd) res=cmp(res,temp);
        if(CharIndex==s.size())return;
        //1.delete the element
        dfs(s,CharIndex+1,p,temp,res);
        //2.add the element
       
        dfs(s,CharIndex+1,p->leaf[s[CharIndex]-'a'],temp+s[CharIndex],res);
    }
    
    
    
    
    
    string cmp(const string& str1,const string &str2){
        if(str1.size()!=str2.size()) return str1.size()>str2.size()?str1:str2;
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]) return str1[i]<str2[i]?str1:str2;
        }
        return  str1;
    }
    
    Tire *Root;
};



int main(){
    Solution mysolu;
    string s="abpcplea";
    vector<string> dictionary={"ale","apple","monkey","plea"};
    string s1="aaa";
    vector<string> dictionary1={"a","aa","aaa"};
    string res=mysolu.findLongestWord(s1, dictionary1);
    return 0;
    
}
