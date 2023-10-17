//
//  985_Sum of Even Numbers After Queries.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int EvenSum=0;
        vector<int> res;
        for(auto n:nums) if(n%2==0) EvenSum+=n;
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0],index=queries[i][1];
            if(nums[index]%2){
                int temp=nums[index]+val;
                if(temp%2==0) EvenSum+=temp;
            }else{
                int temp=nums[index]+val;
                if(temp%2==0) EvenSum+=val;
                else EvenSum-=nums[index];
            }
            
            nums[index]+=val;
            res.push_back(EvenSum);
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    vector<int> nums ={1,2,3,4};
    vector<vector<int>> queries =
    {{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> res=mysolu.sumEvenAfterQueries(nums, queries);
    
    return 0;
}
