//
//  457_Circular Array Loop.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/12/10.
//

#include <stdio.h>
#include<vector>
#include<unordered_set>


using namespace std;


class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return false;
        
        for(int i=0;i<n;i++){
           
            vector<bool>visited(n,false);
            if(dfs(nums,visited,i,0,nums[i]<0?false:true))return  true;
        }
        return false;
    }
    
    bool dfs(vector<int>&nums,vector<bool>& visited,int index,int k,bool flag){
        int n=nums.size();
        while(index<0) index=index+n;
        index=index%n;
        //judge forward or backward acoordiance
        bool flag2=nums[index]<0?false:true;
        if(flag2!=flag)return false;
        //judge if visited before
        if(visited[index]) return nums[index]>0?nums[index]%n!=0:-nums[index]%n!=0;
       
        //next step
        visited[index]=true;
        return dfs(nums,visited,index+nums[index],k+1,flag);
    }
};


int main(){
    Solution mysolu;
    vector<int>nums={2,-1,1,2,2};
    vector<int>nums1={-1,-2,-3,-4,-5,6};
    vector<int>nums2={-2,1,-1,-2,-2};
    vector<int>nums3={1,-1,5,1,4};
    vector<int>nums4={-1,-2,-3,-4,-5};
    
    bool res=mysolu.circularArrayLoop(nums4);
    return 0;
    
}
