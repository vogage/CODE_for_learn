//
//  808_Soup Servings.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/13.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Soup{
public:
    Soup(int _soupA,int _soupB,double _prob):soupA(_soupA),soupB(_soupB),prob(_prob){};
    int soupA;
    int soupB;
    double prob;
};

class Solution {
public:

    double soupServings(int n) {
        //这个题目有个地方就挺没意思的，就是n>=4276，return 1;
        method=vector<vector<int>>({{100,0},{75,25},{50,50},{25,75}});
        Soup origin(n,n,1);
        global_n=n*2;
        
        return dfs(origin);
    }
    double dfs(Soup sp){
        long long sp_key=sp.soupA*global_n+sp.soupB;
        if(soup_map.find(sp_key)!=soup_map.end())return soup_map[sp_key];
        double res=0;
        if(sp.soupA<=0){
            if(sp.soupB>0) res=sp.prob;
            else res=0.5*sp.prob;
        }else if(sp.soupB>0){
            for(int i=0;i<method.size();i++){
                res+=dfs(Soup(sp.soupA-method[i][0],sp.soupB-method[i][1],0.25*sp.prob));
            }
        }
        soup_map[sp_key]=res;
        return res;
    }
private:
    int global_n;
   
    vector<vector<int>> method;
   
    unordered_map<long long,double> soup_map;
};

int main(){
    Solution mysolu;
    double res = mysolu.soupServings(4275);
    return 0;
}
