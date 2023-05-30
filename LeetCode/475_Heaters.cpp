//
//  475_Heaters.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/29.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        heaters.insert(heaters.begin(), INT_MIN);
        heaters.push_back(INT_MAX);
        int res=0;
        for(int i=0;i<houses.size();i++){
            int begin=0;
            int end=heaters.size()-1;
            
            // find the nearest heater
            while(begin<end){
                int mid=(begin+end)/2;
                if(heaters[mid]>houses[i]) end=mid;
                else begin=mid+1;
            }
            
            if(begin==0){
                res=max(res,heaters[1]-houses[i]);
            }else if(begin == heaters.size()-1){
                res=max(res,houses[i]-heaters[heaters.size()-2]);
            }else{
                long long left_dist=(long long)houses[i]-(long long)heaters[begin-1];
                long long right_dist=(long long)heaters[begin]-(long long)houses[i];
                res=max((int)min(left_dist,right_dist),res);
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int i=0,j=0,res=INT_MIN;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        //if(houses.size()==0||heaters.size()==0)return -1;
        int n=houses.size();
        int m=heaters.size();
        vector<int> intervals_pre(n,0);
        vector<int> intervals_next(n,0);
        for(int i=0,j=0;i<n;i++){
            // interval from the pre_heater
            while(j<m&&houses[i]>heaters[j])j++;
            if(j>0) intervals_pre[i]=houses[i]-heaters[j-1];
            else intervals_pre[i]=houses[i]-heaters[j]>0?houses[i]-heaters[j]:INT_MAX;
            // interval form the next heater
            if(j==m) intervals_next[i]=INT_MAX;
            else intervals_next[i]=heaters[j]-houses[i];
        }
        for(int i=0;i<n;i++){
            res=max(res,min(intervals_pre[i],intervals_next[i]));
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> houses={1,2,3,4};
    vector<int> heaters={1,4};
    
    vector<int> houses1={1,2,3};
    vector<int> heaters1={2};
    
    vector<int> house2={1,5};
    vector<int> heaters2={2};
    
    vector<int> house3={282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> heaters3={823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    int res=mysolu.findRadius(houses, heaters);
    
    return 0;
}
