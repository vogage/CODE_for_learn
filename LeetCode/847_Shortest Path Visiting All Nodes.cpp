//
//  847_Shortest Path Visiting All Nodes.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/23.
//

#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;


class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int res=INT_MAX;
        for(int i=0;i<graph.size();i++){
           
            bfs(graph,1名,res);
        }
        return res;
    }
private:
    void bfs(vector<vector<int>>& graph,int i,int& res){
        unordered_set<int> node_set;
        queue<int> node_que;
        
        node_set.insert(i);
        int total=0;
        
        while(!node_que.empty()){
            int n=node_que.size();
            for(int j=0;j<n;j++){
                int temp=node_que.front();
                node_que.pop();
                
                int m=graph[temp].size();
                int count=0;
                for(int k=0;k<m;k++){
                    if(node_set.find(graph[temp][k])==node_set.end()){
                        node_set.insert(graph[temp][k]);
                        node_que.push(graph[temp][k]);
                        count++;
                    }
                }
                if(count)total+=m<=2?count:1+(count-1)*2;
            }
        }
        res=min(res,total);
        
    }
};


int main(){
    Solution mysolu;
    vector<vector<int>> graph={{1},{0,2,4},{1,3,4},{2},{1,2}};
    vector<vector<int>> graph2={{1,2,3},{0},{0},{0}};
    vector<vector<int>> graph3={{1,2,3,5},{0,5},{0,4},{0},{5,2},{0,4,1}};
    int res=mysolu.shortestPathLength(graph3);
    return 0;
}
