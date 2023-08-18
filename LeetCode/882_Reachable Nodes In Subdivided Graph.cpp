//
//  882_Reachable Nodes In Subdivided Graph.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/17.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

struct Edge{
    int begin;
    int end;
    int notVisitedLen;
    Edge(int b,int e,int nvl):begin(b),end(e),notVisitedLen(nvl){}
};

class cmp{
public:
    bool operator()(pair<int,int>& p1,pair<int,int> &p2){
        return p1.second<p2.second;
    }
};

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        //bfs search
        vector<Edge> edgevec;
        unordered_map<int, vector<int>> IndexMap;
      
        
        // construct the index map
        for(int i=0;i<edges.size();i++){
            edgevec.push_back(Edge(edges[i][0],edges[i][1],edges[i][2]));
            IndexMap[edges[i][0]].push_back(i);
            IndexMap[edges[i][1]].push_back(i);
        }
        
        //how to judge the visited edge nodes????
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> que; //node and the left steps
        unordered_set<int> visited;
        que.push({0,maxMoves});
       
        int res=0;
        //initial the first step
        while(!que.empty()){
            
            pair<int,int> cur=que.top();
            que.pop();
            if(visited.find(cur.first)!=visited.end())continue;
            visited.insert(cur.first);
            res++;
            
           
            for(int i:IndexMap[cur.first]){ //each edge with the current node
                int leftstep=cur.second;
                Edge E=edgevec[i];
                if(leftstep>E.notVisitedLen){
                    leftstep-=E.notVisitedLen;
                    res+=E.notVisitedLen;
                    E.notVisitedLen=0;
                    int ni=E.begin==cur.first?E.end:E.begin;
                    if(visited.find(ni)==visited.end()){
                        que.push({ni,leftstep-1});
                    }
                }else{
                    res+=leftstep;
                    E.notVisitedLen-=leftstep;
                }
                edgevec[i]=E;
            }
        }
        
        return res;
        
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> edges = {{0,1,10},{0,2,1},{1,2,2}};
    int maxMoves = 6;
    int n = 3;
    
    vector<vector<int>> edges1={{0,3,8},{0,1,4},{2,4,3},{1,2,0},{1,3,9},{0,4,7},{3,4,9},{1,4,4},{0,2,7},{2,3,1}};
    int maxMoves1=8;
    int n1=5;
    int res=mysolu.reachableNodes(edges1, maxMoves1, n1);
    return 0;
}
