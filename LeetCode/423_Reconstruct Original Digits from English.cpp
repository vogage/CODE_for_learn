//
//  423_Reconstruct Original Digits from English.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/19.
//

#include <stdio.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

//struct trie{
//    vector<trie*> children;
//    bool isend;
//    trie():children(26),isend(false){};
//};

struct node{
    char c;
    int i;
    string str;
    node(char ch,int digit,string s):c(ch),i(digit),str(s){};
};

class Solution {
public:
    string originalDigits(string s) {
        vector<string> vstr={"zero","one","two","three","four","five","six","seven","eight","nine"};
        vector<int> vt=cal(s);
        vector<node> round1={node('w',2,"two"),node('u',4,"four"),node('x',6,"six"),node('g',8,"eight"),node('z',0,"zero"),
            node('h',3,"three"),node('f',5,"five"),node('s',7,"seven"),node('i',9,"nine"),node('o',1,"one")};
        vector<int> digits(10,0);
        for(int i=0;i<round1.size();i++){
            node p=round1[i];
            if(vt[p.c-'a']>0){
                digits[p.i]=vt[p.c-'a'];
                for(int j=0;j<p.str.size();j++){
                    vt[p.str[j]-'a']-=digits[p.i];
                }
            }
        }
        string res="";
        for(int i=0;i<digits.size();i++){
            for(int j=0;j<digits[i];j++){
                res+=to_string(i);
            }
        }
        return res;
      
    }
private:

    vector<int> cal(const string& s){
        vector<int> res(26,0);
        for(int i=0;i<s.size();i++){
            res[s[i]-'a']++;
        }
        return res;
    }


};

class Solution2 {
public:
    string originalDigits(string s) {
        //trie* root=initial();
        vector<string> vstr={"zero","one","two","three","four","five","six","seven","eight","nine"};
        vector<int> totalchar=cal(s);
        string res=bagget(vstr,totalchar);
        return res;
    }
private:
//    trie* initial(){
//        vector<string> vstr={"zero","one","two","three","four","five","six","seven","eight","nine"};
//        trie* root=new trie();
//        for(int i=0;i<vstr.size();i++){
//            trie* tmp=root;
//            for(int j=0;j<vstr.size();j++){
//                int index=vstr[i][j]-'a';
//                tmp->children[index]=new trie();
//                tmp=tmp->children[index];
//            }
//            tmp->isend=true;
//        }
//        return root;



    vector<int> cal(const string& s){
        vector<int> res(26,0);
        for(int i=0;i<s.size();i++){
            res[s[i]-'a']++;
        }
        return res;
    }
    string bagget(const vector<string>& vstr,vector<int>& tv){
        string res="";
        for(int i=0;i<vstr.size();i++){
            string temp="";
            dfs(vstr,tv,i,temp,res);
        }
        return res;
        
    }
    
    void dfs(const vector<string>& vstr,vector<int> tv,int str_id,string temp,string& res){
        if(res.size()!=0)return ;
        if(str_id==vstr.size()){
            for(int j=0;j<tv.size();j++){
                if(tv[j]>0)return;
            }
            res=temp;
            return;
            
        }
        vector<int> tv2=tv;
        for(int i=0;i<vstr[str_id].size();i++){
            int c_id=vstr[str_id][i]-'a';
            if(tv[c_id]<1) {
                dfs(vstr,tv,str_id+1,temp,res);
                return;
            }
            tv2[c_id]--;
        }
        dfs(vstr,tv2,str_id,temp+to_string(str_id),res);
        dfs(vstr,tv2,str_id+1,temp+to_string(str_id),res);
        
    }
    
};


//1 <= s.length <= 105
//s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
//s is guaranteed to be valid.

int main(){
    Solution mysolu;
    string str="owoztneoer";
    string s ="zeroonetwothreefourfivesixseveneightnine";
    string res=mysolu.originalDigits(s);
    return 0;
}
