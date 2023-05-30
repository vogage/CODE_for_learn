//
//  373_Find K Pairs with Smallest Sums.cpp
//  leetcode
//
//  Created by qiandehou on 2021/5/3.
//

#include <stdio.h>

#include<vector>
#include <stack>
#include<queue>

using namespace std;

class Solution {
    //方法2
    struct tmp2 //重写仿函数
    {
        bool operator() (const vector<int>& a,const vector<int>& b){
                return a[0]+a[1]-b[0]-b[1]>0;
        };
    };
    
    
    
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
       
       // auto f=[](const vector<int>& a,const vector<int>& b){
       //     return a[0]+a[1]-b[0]-b[1];
       // };

        priority_queue<vector<int>,vector<vector<int>>,tmp2> pq;
        
        
        for(int i=0;i<nums1.size();i++){
            pq.push(vector<int>{nums1[i],nums2[0],0});
        }
        
        while(k--&&!pq.empty()){
            vector<int> temp=pq.top();
            res.push_back(vector<int>{temp[0],temp[1]});
            pq.pop();
            if(temp[2]==nums2.size()-1) continue;
            pq.push(vector<int>{temp[0],nums2[temp[2]+1],temp[2]+1});
        }
        
        
        
        return res;
    }
};

int main(){
    vector<int> nums1={1,7,11};
    
    vector<int> nums2={2,4,6};
    Solution mysolu;
    vector<vector<int>> res=mysolu.kSmallestPairs(nums1, nums2, 3);
    
    return 0;
}
