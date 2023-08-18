//
//  875_Koko Eating Bananas.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/16.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int begin=1;
        int end=INT_MIN;
        for(int i=0;i<piles.size();i++){
            end=max(end,piles[i]);
        }
        while (begin<end) {
            int mid=(begin+end)/2;
            int hR=cntEatHour(piles,mid);
            if(hR>h) begin=mid+1;
            else end=mid;
        }
        return begin;
       
    }
private:
    int cntEatHour(vector<int>&piles ,int k){
        int res=0;
        for(int i=0;i<piles.size();i++){
            int temp=piles[i]/k;
            res+=piles[i]%k==0?temp:temp+1;
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    vector<int> piles={3,6,7,11};
    int res=mysolu.minEatingSpeed(piles, 8);
    return 0;
}
