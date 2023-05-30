//
//  454_4Sum II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/28.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums_map1;
        unordered_map<int,int> nums_map2;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                nums_map1[nums1[i]+nums2[j]]++;
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                nums_map2[nums3[i]+nums4[j]]++;
            }
        }
        int res=0;
        
        for(auto m:nums_map1){
            if(nums_map2.find(-m.first)!=nums_map2.end()){
                res+=m.second*nums_map2[-m.first];
            }
        }
        return res;
    }
};

class Solution2 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums_map;
        unordered_map<int,int> nums_map2;
        int res=0;
        
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                nums_map[nums1[i]+nums2[j]]++;
            }
        }
        for(auto m:nums_map){
            for(int i=0;i<nums3.size();i++){
                nums_map2[nums3[i]+m.first]+=m.second;
            }
        }
        
        for(int i=0;i<nums4.size();i++){
            res+=nums_map2[-nums4[i]];
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {-2,-1};
    vector<int> nums3 = {-1,2};
    vector<int> nums4 = {0,2};
    int res=mysolu.fourSumCount(nums1, nums2, nums3, nums4);
    
    return 0;
}
