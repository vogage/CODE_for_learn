//
//  996_Number of Squareful Arrays.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/6/7.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
       
    }
private:
    bool isquare(const int &left,const int &right){
        int total=left+right;
        int root=(int)sqrt(total);
        if(root*root==total) return true;
        else return false;
    }
};
        
        
        

class Solution1 {
public:
    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int,vector<int>> graph;
        unordered_set<int> used;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isquare(nums[i],nums[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false);
        unordered_set<string> res;
        
        for(int i=0;i<n;i++){
            if(used.find(nums[i])!=used.end()) continue;
            used.insert(nums[i]);
            visited[i]=true;
            dfs(graph,visited,nums,i,0,"",res);
            visited[i]=false;
        }
        return res.size();
        
    }
private:
    void dfs(unordered_map<int, vector<int>>&graph,vector<bool>& visited,vector<int>& nums,int i,int temp,string temp_str,unordered_set<string>& res){
        temp_str+=to_string(nums[i]);
        if(temp==nums.size()-1){
            res.insert(temp_str);
            return;
        }
        
            for(int k=0;k<graph[i].size();k++){
                if(visited[graph[i][k]]) continue;
                visited[graph[i][k]]=true;
                dfs(graph,visited,nums,graph[i][k],temp+1,temp_str,res);
                visited[graph[i][k]]=false;
            }
        
    }
    bool isquare(const int &left,const int &right){
        int total=left+right;
        int root=(int)sqrt(total);
        if(root*root==total) return true;
        else return false;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={1,17,8};
    vector<int> nums1={2,2,2};
    vector<int> nums2={2,2,2,2,2,2,2,2,2,2,2};
    int res=mysolu.numSquarefulPerms(nums2);
    return 0;
}
