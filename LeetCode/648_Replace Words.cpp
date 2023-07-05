//
//  648_Replace Words.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

struct Tire{
    bool isend;
    vector<Tire*> sons;
    Tire():isend(false),sons(vector<Tire*>(26)){};
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new Tire();
        Build_Dictionary_Tire(root,dictionary);
        vector<string> SentenceWords=sentence_split(sentence);
        string res="";
        for(int i=0;i<SentenceWords.size();i++){
            res+=Str_Dictionary(SentenceWords[i]);
            res+=" ";
        }
        return res.substr(0,res.size()-1);
        
    }
private:
    string Str_Dictionary(string str){
        Tire *temp=root;
        int i=0;
        string res="";
        while(temp&&!temp->isend&&i<str.size()){
            int index=str[i]-'a';
            temp=temp->sons[index];
            res+=str[i];
            i++;
            
        }
        if(temp&&temp->isend) return res;
        else return str;
    }
    
    vector<string> sentence_split(string &sentence){
        vector<string> res;
        string temp="";
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }else{
                res.push_back(temp);
                temp="";
            }
        }
        if(temp!="") res.push_back(temp);
        return res;
    }
    
    void Build_Dictionary_Tire(Tire* root,vector<string>& dictionary){
        for(int i=0;i<dictionary.size();i++){
            Tire *temp=root;
            for(int j=0;j<dictionary[i].size();j++){
                int index=dictionary[i][j]-'a';
                if(temp->sons[index]==nullptr){
                    temp->sons[index]=new Tire();
                }
                temp=temp->sons[index];
            }
            temp->isend=true;
        }
    }
private:
    Tire *root;
    
};


int main(){
    Solution mysolu;
//    dictionary = ["cat","bat","rat"], sentence =
    vector<string> dictionary = {"cat","bat","rat"};
    string sentence="the cattle was rattled by the battery";
    string res=mysolu.replaceWords(dictionary, sentence);
    return 0;
}
