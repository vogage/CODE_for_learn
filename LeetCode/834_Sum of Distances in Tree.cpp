//
//  834_Sum of Distances in Tree.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/17.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;


class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++){
            nodes_map[edges[i][0]].push_back(edges[i][1]);
            nodes_map[edges[i][1]].push_back(edges[i][0]);
        }
        
        count=vector<int>(n,1);
        res=vector<int>(n,0);
        total=n;
        post_dfs(0,-1);
        pre_dfs(0,-1);
        
        return res;
    }
private:
    void post_dfs(int root,int pre){
        
        
            for(int i=0;i<nodes_map[root].size();i++){
                if(nodes_map[root][i]==pre)continue;
                post_dfs(nodes_map[root][i],root);
                count[root]+=count[nodes_map[root][i]];
                res[root]+=res[nodes_map[root][i]]+count[nodes_map[root][i]];
            }
        
        
    }
    void pre_dfs(int root,int pre){
        for(int i=0;i<nodes_map[root].size();i++){
            if(nodes_map[root][i]==pre) continue;
            res[nodes_map[root][i]]=res[root]-count[nodes_map[root][i]]+total-count[nodes_map[root][i]];
            pre_dfs(nodes_map[root][i],root);
        }
    }
    unordered_map<int,vector<int>> nodes_map;
    vector<int> count;
    vector<int> res;
    int total;
            
};

int main(){
    Solution mysolu;
    int n=6;
    vector<vector<int>> edges={{0,1},{0,2},{2,3},{2,4},{2,5}};
    vector<int> res=mysolu.sumOfDistancesInTree(n, edges);
    return 0;
}

