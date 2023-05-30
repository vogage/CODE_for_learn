//
//  334_Increasing Triplet Subsequence.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/4.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        unordered_map<int,bool> twoincre;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    if(twoincre.find(j)!=twoincre.end()){
                        if(twoincre[j])return true;
                       
                    }else{
                        twoincre[j]=two_increase_search(j,nums);
                        if(twoincre[j])return true;
                    }
                }
            }
        }
        return false;
    }
    bool two_increase_search(int j,vector<int>& nums){
        for(int i=0;i<j;i++){
            if(nums[i]<nums[j]) return true;
        }
        return false;
    }
};

class Solution2{
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX;
        int bigger=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<small) small=nums[i];
            else if(nums[i]<bigger) bigger=nums[i];
            else return true;
        }
        return false;
    }
};

int main(){
    Solution2 mysolu;
    
    
    vector<int> input={1,2,3,4,5};
    vector<int> input2={1,2,1,3};
    bool res=mysolu.increasingTriplet(input2);
    return 0;
}
