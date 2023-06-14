//
//  565_Array Nesting.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/14.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
//        Return the longest length of a set s[k].
        unordered_set<int> IndexSet;
        int res=0;
        
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(IndexSet.find(i)==IndexSet.end()){
                dfs_nest(nums,i,IndexSet,res);
            }
        }
        return res;
    }
private:
    void dfs_nest(vector<int>& nums,int index,unordered_set<int>& IndexSet,int& res){
//        You are given an integer array nums of length n where nums is a permutation of the numbers in the range [0, n - 1].
        int cnt=0;
        while(1){
            if(IndexSet.find(index)!=IndexSet.end()){
                res=max(cnt,res);
                return ;
            }
            IndexSet.insert(index);
            cnt++;
            index=nums[index];
        }
    }
};


int main(){
    Solution mysolu;
    
    vector<int> nums={5,4,0,3,1,6,2};
    vector<int> nums1={0,2,1};
    int res=mysolu.arrayNesting(nums1);
    return 0;
}
