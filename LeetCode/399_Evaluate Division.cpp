//
//  399_Evaluate Division.cpp
//  leetcode
//
//  Created by qiandehou on 2021/11/7.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<string,unordered_map<string,double>> division_values;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // initialize
        for(int i=0;i<equations.size()&&i<values.size();i++){
            division_values[equations[i][0]][equations[i][1]]=values[i];
            division_values[equations[i][1]][equations[i][0]]=1/values[i];
            division_values[equations[i][0]][equations[i][0]]=1;
            division_values[equations[i][1]][equations[i][1]]=1;
        }
        vector<double> res;
        for(int i=0;i<queries.size();i++){
            double temp=1;
            unordered_set<string> search_set;
            dfs(queries[i],search_set,temp,res);
            if(res.size()<i+1)res.push_back(-1);
           
        }
        return res;
    }
    void dfs(vector<string>& target_query,unordered_set<string>&search_set,double temp,vector<double>& res){
        if(search_set.find(target_query[0])!=search_set.end()){return;}
        else{search_set.insert(target_query[0]);}
        if(division_values.find(target_query[0])==division_values.end()){temp=-1;res.push_back(temp);return;}
        else{
            if(division_values[target_query[0]].find(target_query[1])!=division_values[target_query[0]].end()){
                temp=temp*division_values[target_query[0]][target_query[1]];
               
                res.push_back(temp);
                return;
            }else{
                for(auto k:division_values[target_query[0]]){
                    if(k.first==target_query[0]) continue;
                    vector<string>sub_query;
                    sub_query.push_back(k.first);
                    sub_query.push_back(target_query[1]);
                    double temp2=temp*k.second;
                    dfs(sub_query,search_set,temp2,res);
                    
                }
                
            }
        }
        
    }
    
};


int main(){
//Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
    
    vector<vector<string>> equations;
    vector<double> values;
    vector<vector<string>> queries;
    
    vector<string> eq1={"a","b"};
    equations.push_back(eq1);
    vector<string> eq2={"b","c"};
    equations.push_back(eq2);
    
    values.push_back(2.0);
    values.push_back(3.0);
    
    vector<string> qu1={"a","c"};
    queries.push_back(qu1);
    vector<string> qu2={"b","a"};
    queries.push_back(qu2);
    vector<string> qu3={"a","e"};
    queries.push_back(qu3);
    vector<string> qu4={"a","a"};
    queries.push_back(qu4);
    vector<string> qu5={"x","x"};
    queries.push_back(qu5);
    
    vector<vector<string>> equations2={{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double> values2={3.0,0.5,3.4,5.6};
    vector<vector<string>> queries2={{"x3","x4"}};
    
    vector<vector<string>> equations3={{"x1","x2"},{"x2","x3"},{"x1","x4"},{"x2","x5"}};
    vector<double>values3={3.0,0.5,3.4,5.6};
    vector<vector<string>> queries3={{"x2","x4"},{"x1","x5"},{"x1","x3"},{"x5","x5"},{"x5","x1"},{"x3","x4"},{"x4","x3"},{"x6","x6"},{"x0","x0"}};
    
    Solution mysolu;
    vector<double> res=mysolu.calcEquation(equations3, values3, queries3);
    return 0;
    
    
}
