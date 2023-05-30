//
//  407_Trapping Rain Water II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/3/29.
//

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;




class Solution {
    
private:
    int n;
    int m;
    vector<pair<int,int>> Dir=vector<pair<int,int>>{pair<int,int>(0,-1),pair<int,int>(0,1),pair<int,int>(-1,0),pair<int,int>(1,0)};
    
public:
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        n=heightMap.size();
        if(n<3)return 0;
        m=heightMap[0].size();
        int res=0;
        //initialize
        vector<vector<Grid_Point>> Grids(n,vector<Grid_Point>(m));
        // calculate the boundary
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Grids[i][j]=Grid_Point(i, j, heightMap[i][j], heightMap[i][j], false, Is_Boundary(i, j));
            }
        }
        
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(Grids[i][j].visited) continue;
                vector<vector<bool>> Visited(n,vector<bool>(m));
                priority_queue<Grid_Point,vector<Grid_Point>,cmp> Search_Queue;
                vector<Grid_Point> Candidate;
                Search_Queue.push(Grids[i][j]);
                Visited[i][j]=true;
                while(!Search_Queue.empty()){
                    Grid_Point p=Search_Queue.top();
                    Search_Queue.pop();
                   
                    if(Grids[p.i][p.j].boundary)break;
                    if(Grids[p.i][p.j].visited)continue;
                    for(int k=0;k<Dir.size();k++){
                        int ki=p.i+Dir[k].first;
                        int kj=p.j+Dir[k].second;
                        if(!Visited[ki][kj]) Search_Queue.push(Grids[ki][kj]);
                        Visited[ki][kj]=true;
                    }

                    Candidate.push_back(Grids[p.i][p.j]);
                    for(int h=0;h<Candidate.size();h++){
                        int hi=Candidate[h].i;
                        int hj=Candidate[h].j;
                        Grids[hi][hj].volume=max(Grids[hi][hj].volume,Search_Queue.top().volume);
                    }
                }
                for(int w=0;w<Candidate.size();w++){
                    
                    int wi=Candidate[w].i;
                    int wj=Candidate[w].j;
                    res+=Grids[wi][wj].volume-Grids[wi][wj].value;
                    Grids[wi][wj].visited=true;
                }
            }
        }
      
        return res;
    }
private:
    struct Grid_Point{
        int i;
        int j;
        int volume;
        int value;
        bool visited;
        bool boundary;
        Grid_Point(int ii,int jj,int a,int b,bool v,bool boud):i(ii),j(jj),volume(a),value(b),visited(v),boundary(boud){};
        Grid_Point():i(-1),j(-1),volume(INT_MAX),value(0),visited(false),boundary(false){};
    };

    struct cmp{
        bool operator()(const Grid_Point& p1,const Grid_Point &p2){
            return p1.value>p2.value;
        }
    };
    
    
    bool Is_Boundary(int i,int j){
        if(i==0||i==n-1)return true;
        if(j==0||j==m-1)return true;
        return false;
    }
            

};


int main(){
    vector<vector<int>>heightMap={{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    vector<vector<int>>heightMap2={{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
    vector<vector<int>>heightMap3={{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    vector<vector<int>>heightMap4={{9,9,9,9,9},{9,2,1,2,9},{9,2,8,2,9},{9,2,3,2,9},{9,9,9,9,9}};
    vector<vector<int>>heightMap5={{78,16,94,36},{87,93,50,22},{63,28,91,60},{64,27,41,27},{73,37,12,69},{68,30,83,31},{63,24,68,36}};
    vector<vector<int>>heightMap6={{12,13,1,12},{13,4,13,12},{13,8,13,12},{12,13,10,12},{13,13,13,13}};
    Solution mysolu;
    int res=mysolu.trapRainWater(heightMap5);
    return 0;
}

