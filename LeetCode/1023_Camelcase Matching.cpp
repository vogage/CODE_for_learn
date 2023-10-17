//
//  1023_Camelcase Matching.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/28.
//

#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

//A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. 
//You may insert each character at any position and you may not insert any characters.

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        //queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
        //[true,false,true,false,false]
        int n=queries.size();
        vector<bool> res(n,false);
        for(int k=0;k<n;k++){
            int index=0;
            int i=0;
            for(;i<queries[k].size();i++){
                if(index<pattern.size()&&pattern[index]==queries[k][i]){ index++;continue;}
                if(queries[k][i]<='z'&&queries[k][i]>='a')continue;
                else break;
            }
            res[k]=(index==pattern.size()&&i==queries[k].size());
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<string> queries={"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
    string pattern="FoBa";
    vector<bool> res=mysolu.camelMatch(queries, pattern);
    return 0;
}
