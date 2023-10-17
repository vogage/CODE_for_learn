//
//  990_Satisfiability of Equality Equations.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        pars=vector<char>(26,'#');
        for(char c='a';c<='z';c++) pars[c-'a']=c;
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!')continue;
            char a=equations[i][0];
            char b=equations[i][3];
            ParUnion(a,b);
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='=')continue;
            char a=equations[i][0];
            char b=equations[i][3];
            if(ParFind(a)==ParFind(b))return false;
        }
        return true;
    }
private:
    char ParFind(char a){
        if(pars[a-'a']==a) return a;
        else {
            pars[a-'a']=ParFind(pars[a-'a']);
            return pars[a-'a'];
        }
    }
    
    void ParUnion(char a,char b){
        if(a==b)return;
        pars[ParFind(a)-'a']=ParFind(b);
    }
private:
    vector<char> pars;
};


int main(){
    Solution mysolu;
    //equations = ["a==b","b!=a"]
    vector<string> equations={"a==b","b!=a"};
    vector<string> equations1={"a==b","e==c","b==c","a!=e"};
    vector<string> equations3={"f==a","a==b","f!=e","a==c","b==e","c==f"};
    bool res=mysolu.equationsPossible(equations3);
    return 0;
    
}
