//
//  2. 2022B星环自行车俱乐部.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/2.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node{
    int time;
    int distance;
    Node(int t,int d):time(t),distance(d){};
    bool operator<(const Node& n) const
    {
        if(time!=n.time){
            return time<n.time;
        }else{
            return distance>n.distance;
        }
    }
    bool operator>(const Node& n) const
    {
        if(time!=n.time){
            return time>=n.time;
        }else{
            return distance<=n.distance;
        }
    }
};




int main(){
    int N=3;
    int E=30;
    int D=20;
    int res=INT_MAX;
    unordered_map<int, int> time_distance;
    time_distance[0]=0;
    for(int i=0;i<N;i++){
        unordered_map<int, int> pre=time_distance;
        time_distance.clear();
        for(int e=1;e*e<E;e++){
            for(auto m:pre){
                int move_time=(E-m.second)/(e*e);
                int move_distance=move_time*e;
                int arrive=m.second+move_distance;
                if(arrive>=D){
                    int actual_time=(D-m.second)%e==0?(D-m.second)/e:(D-m.second)/e+1;
                    res=min(res,m.first+actual_time);
                }else{
                    int used_time=move_time+m.first;
                    if(time_distance.find(used_time)==time_distance.end()){
                        time_distance[used_time]=arrive;
                    }else{
                        time_distance[used_time]=max(time_distance[used_time],arrive);
                    }
                }
            }
        }
        
    }
    return 0;
}







