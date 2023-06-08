//
//  486_Predict the Winner.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/6.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        int sums=0;
        for(int i=0;i<nums.size();i++){
            sums+=nums[i];
        }
        int fsum=dfs(nums,0,n-1);
        return fsum*2>=sums;
    }
private:
    int n;
    int get_index(int a,int b){
        return a*n+b;
    }
    unordered_map<int, int> SumMap;
    int dfs(vector<int>nums,int begin,int end){
        if(begin>end)return 0;
        //first choose houw much scores can be get
        //already saved
        int Index=get_index(begin, end);
        if(SumMap.find(Index)!=SumMap.end())return SumMap[Index];
        //case:choose begin
        int res_begin=nums[begin];
        res_begin+=min(dfs(nums,begin+1,end-1),dfs(nums,begin+2,end));
        //case:choose end
        int res_end=nums[end];
        res_end+=min(dfs(nums,begin+1,end-1),dfs(nums,begin,end-2));
        SumMap[Index]=res_begin>res_end?res_begin:res_end;
        return SumMap[Index];
    }
};



int main(){
    Solution mysolu;
    vector<int> nums={1,5,233,7};
    vector<int> nums1={1,5,2};
    bool res=mysolu.PredictTheWinner(nums);
    
    return 0;
}
