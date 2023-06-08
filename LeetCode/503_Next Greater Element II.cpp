//
//  503_Next Greater Element II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/7.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> Candidates;
        vector<int> res(n,0);
        
        //initial
        for(int i=n-1;i>=0;i--){
            while(!Candidates.empty()&&nums[i]>Candidates.top())Candidates.pop();
            Candidates.push(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            while(!Candidates.empty()&&nums[i]>=Candidates.top())Candidates.pop();
            if(Candidates.empty()){
                res[i]=-1;
                Candidates.push(nums[i]);
            }else{
                res[i]=Candidates.top();
                Candidates.push(nums[i]);
            }
        }
        
        
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={1,2,3,4,3};
    vector<int> ans=mysolu.nextGreaterElements(nums);
    return 0;
    
}
