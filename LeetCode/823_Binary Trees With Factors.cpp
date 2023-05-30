//
//  823_Binary Trees With Factors.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/16.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int res=0;
        int mod=1e9+7;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            arr_map[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0)
                    arr_map[arr[i]]=(arr_map[arr[i]]+arr_map[arr[j]]*arr_map[arr[i]/arr[j]])%mod;
            }
            res=(res+arr_map[arr[i]])%mod;
        }
        return res;
    }
private:
    unordered_map<int,long> arr_map;
};

class Solution2 {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=dfs(i,arr);
            total=total%(int)(1e9+7);
        }
        return total;
    }
private:
    int dfs(int i,vector<int>& arr){
        if(arr_map.find(arr[i])!=arr_map.end()) return arr_map[arr[i]];
        long total=1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]%arr[j]==0){
                int k=get_index(i,j,arr);
                if(k==-1)continue;
                if(k==j){
                    total+=(dfs(j,arr)%(int)(1e9+7))*(dfs(k,arr)%(int)(1e9+7));
                    total=total%(int)(1e9+7);
                }else{
                    total+=2*(dfs(j,arr)%(int)(1e9+7))*(dfs(k,arr)%(int)(1e9+7));
                    total=total%(int)(1e9+7);
                }
            }
        }
        return (int)total%(int)(1e9+7);
    }
    int get_index(int i,int j,vector<int>& arr){
        
        int begin_index=0;
        int end_index=j;
        int target=arr[i]/arr[j];
        if(target==arr[j])return j;
        if(target<arr[begin_index])return -1;
        while(begin_index<end_index){
            int mid_index=(begin_index+end_index)/2;
            if(arr[mid_index]>target){
                end_index=mid_index;
            }else if(arr[mid_index]==target){
                return mid_index;
            }else{
                begin_index=mid_index+1;
            }
        }
        return -1;
    }
    unordered_map<int, int> arr_map;
    
    
};


int main(){
    Solution mysolu;
    vector<int> nums={2,4,5,10};
    vector<int> nums1={2,4};
    vector<int> nums2={15,13,22,7,11};
    vector<int> nums3={18,31,2,4,14,7,9,63,10,84};
    int res=mysolu.numFactoredBinaryTrees(nums);
    return 0;
}

