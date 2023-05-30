//
//  787_Cheapest Flights Within K Stops.cpp
//  leetcode
//
//  Created by qiandehou on 2022/3/29.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>


using namespace std;
class City{
public:
    int CityNo;
    int Dst_From_Src;
    int Cost_From_Src;
    City(int _CityNo,int _Dst_From_Src,int _Cost_From_Src){
        CityNo=_CityNo;
        Dst_From_Src=_Dst_From_Src;
        Cost_From_Src=_Cost_From_Src;
    }
    friend bool operator < (const City& c1,const City c2){
        return c1.Cost_From_Src>c2.Cost_From_Src;
    }
};

class Flight{
public:
    int From;
    int Dst;
    int Cost;
    Flight(int _From,int _Dst,int _Cost){
        From=_From;
        Dst=_Dst;
        Cost=_Cost;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<Flight>> flight_map;
        for(int i=0;i<flights.size();i++){
            flight_map[flights[i][0]].push_back(Flight(flights[i][0],flights[i][1],flights[i][2]));
        }
        priority_queue<City> citys_queue;
        unordered_map<int, int> city_dst_map;
        citys_queue.push(City(src,0,0));
        while(!citys_queue.empty()){
            City top=citys_queue.top();
            citys_queue.pop();
            
            if(top.CityNo==dst) return top.Cost_From_Src;
            if(city_dst_map.find(top.CityNo)!=city_dst_map.end()){
                if(city_dst_map[top.CityNo]<=top.Dst_From_Src) continue;
            }
            city_dst_map[top.CityNo]=top.Dst_From_Src;
            if(top.Dst_From_Src>k) continue;
            for(auto flight:flight_map[top.CityNo]){
                citys_queue.push(City(flight.Dst,top.Dst_From_Src+1,top.Cost_From_Src+flight.Cost));
            }
        }
        return -1;
    }
};


class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //where flights[i] = [fromi, toi, pricei]
        //loc_price_map[dst]=INT_MIN;
        vector<vector<int>> dp(k+2,vector<int>(n,INT_MAX));
        unordered_map<int,vector<vector<int>>> flights_map;
        
        for(auto flight:flights){
            flights_map[flight[0]].push_back(vector<int>({flight[1],flight[2]}));
        }
        dp[0][src]=0;
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]!=INT_MAX){
                    if(flights_map.find(j)!=flights_map.end()){
                        for(auto flight:flights_map[j]){
                            dp[i+1][flight[0]]=min(dp[i+1][flight[0]],dp[i][j]+flight[1]);
                        }
                    }
                }
            }
        }
        int res=INT_MAX;
        for(int i=1;i<=k+1;i++) res=min(res,dp[i][dst]);
        return res==INT_MAX?-1:res;
    }
private:


};

int main(){
    int n=5;
    vector<vector<int>> flights={{4,1,1},{1,2,3},{0,3,2},{0,4,10},{3,1,1},{1,4,3}};
    int src=2;
    int dst=1;
    int k=1;
    
    
    //n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
    int n1=3;
    vector<vector<int>> flights1={{0,1,100},{1,2,100},{0,2,500}};
    int src1=0;
    int dst1=2;
    int k1=1;
    
    int n2=4;
    vector<vector<int>> flights2={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src2=0;
    int dst2=3;
    int k2=1;
    
    int n3=4;
    vector<vector<int>> flights3={{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int src3=0;
    int dst3=3;
    int k3=1;
    
    int n4=3;
    vector<vector<int>> flights4={{0,1,2},{1,2,1},{2,0,10}};
    int src4=1;
    int dst4=2;
    int k4=1;
    
    
    
    Solution mysolu;
    int res=mysolu.findCheapestPrice(n1, flights1, src1, dst1, k1);
    return 0;
}
