//
//  983_Minimum Cost For Tickets.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/6/3.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> ticket_days={1,7,30};
        size_t n=days.size();
        vector<int> targets(n,INT_MAX);
        //for(int i=0;i<3;i++)targets[0]=min(targets[0],costs[i]);
        for(int i=0;i<n;i++){
            vector<int> index=get_index(days,i,ticket_days);
            for(int j=0;j<3;j++){
                if(index[j]==-1){
                    targets[i]=min(targets[i],costs[j]);
                }else{
                    targets[i]=min(targets[i],targets[index[j]]+costs[j]);
                }
            }
            
        }
       
        return targets[n-1];
    }
private:
        vector<int> get_index(vector<int>& days,int i,vector<int>& ticket_days){
            vector<int> res(3,0);
            for(int j=0;j<3;j++){
                int pre=i;
                int target=days[i]-ticket_days[j];
                while(pre>=0&&days[pre]>target){
                    pre--;
                }
                res[j]=pre;
            }
            return res;
        }
    
};


int main(){
    Solution mysolu;
    vector<int> days={1,4,6,7,8,20};
    vector<int> costs={7,2,15};
    vector<int> days1={1,2,3,4,5,6,7,8,9,10,30,31};
    
    vector<int> days2={6,8,9,18,20,21,23,25};
    vector<int> costs2={2,10,41};
    
    vector<int> days3={1,4,6,7,8,20};
    vector<int> costs3={7,2,15};
    
    vector<int> days4={1,5,8,9,10,12,13,16,17,18,19,20,23,24,29};
    vector<int> costs4={3,12,54};
    
    vector<int> days5={1,3,7};
    vector<int> costs5={1,4,20};
    int res=mysolu.mincostTickets(days, costs);
    return 0;
}


