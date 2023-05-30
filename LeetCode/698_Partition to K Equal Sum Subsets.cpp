//
//  698_Partition to K Equal Sum Subsets.cpp
//  leetcode
//
//  Created by qiandehou on 2022/3/15.
//

#include <stdio.h>
#include <vector>

using namespace std;
//Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        int n = nums.size();
        vector<bool> dp(1 << n, false);
        vector<int> total(1 << n, 0);
        dp[0] = true;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (sum % k != 0)return false;
        sum /= k;
        sort(nums.begin(), nums.end());
        if (nums[n - 1] > sum) return false;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i]) {
                for (int j = 0; j < n; j++) {
                    int temp = i | (1 << j);
                    if (temp != i) {
                        if (nums[j] <= (sum - (total[i] % sum))) {
                            dp[temp] = true;
                            total[temp] = nums[j] + total[i];
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};









class Solution1 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int i=0;i<nums.size();i++) total+=nums[i];
        if(total%k!=0)return false;
        total=total/k;
       
        vector<int> bucks(k,total);
        sort(nums.begin(),nums.end(),less<int>());
        //if(nums.back()>total)return false;
        vector<bool>visited(nums.size(),false);
        
        dp=vector<pair<bool,bool>>(1<<nums.size(),pair<bool,bool>{false,false});//left : visited //right : can partition
        
        return dfs(nums,bucks,visited,0,0);
    }
private:
   
    bool dfs(vector<int> &nums,vector<int>& bucks,vector<bool>& visited,int buck_start,int nums_start){
        int index=get_index(visited);
        if(dp[index].first)return dp[index].second;
        if(buck_start==bucks.size()){return true;}
        
        for(int i=nums_start;i<nums.size();i++){
            if(visited[i])continue;
            if(bucks[buck_start]-nums[i]<0)break;
            visited[i]=true;
            bucks[buck_start]-=nums[i];
            bool nxt=false;
            if(bucks[buck_start]==0){
                nxt=dfs(nums,bucks,visited,buck_start+1,0);
            }else{
                nxt=dfs(nums,bucks,visited,buck_start,nums_start+1);
            }
            
            bucks[buck_start]+=nums[i];
            visited[i]=false;
            dp[index].first=true;
            dp[index].second=nxt;
            if(nxt)return true;
        }
        
        return false;
        
    }
    
    int get_index(const vector<bool>& visited){
        int res=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]) res=res|(1<<i);
        }
        return res;
    }
private:
    vector<pair<bool,bool>>dp;
    
   
};








class Solution2 {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total=0;
        for(int i:nums) total+=i;
        if(total%k!=0)return false;
        vector<int> bucks(k,total/k);
        sort(nums.begin(),nums.end(),greater<int>());
        return dfs(0,nums,bucks);
    }
    bool dfs(int start,vector<int>& nums,vector<int>& bucks){
        if(start==nums.size())return true;
       
        for(int i=0;i<bucks.size();i++){
            if(bucks[i]-nums[start]>=0){
                bucks[i]-=nums[start];
               
                if(dfs(start+1,nums,bucks))return true;
                bucks[i]+=nums[start];
            }
        }
        return false;
    }
};

int main(){
    Solution mysolu;
    vector<int>nums = {4,3,2,3,5,2,1};
    int k=4;
    
    //[1,2,3,4]
    //3
    vector<int> nums2={1,2,3,4};
    vector<int> nums3={605,454,322,218,8,19,651,2220,175,710,2666,350,252,2264,327,1843};
    
    vector<int> nums4={3,9,4,5,8,8,7,9,3,6,2,10,10,4,10,2};
    
    vector<int> nums5={85,35,40,64,86,45,63,16,5364,110,5653,97,95};
    int k5=7;
    
    vector<int> nums6={4,1,5,8,7,2,5,4,10,2,2,6,5,4,7};
    int k6=8;
   
    bool res=mysolu.canPartitionKSubsets(nums6, k6);
    return 0;
}

