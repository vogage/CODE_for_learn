//
//  992_Subarrays with K Different Integers.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <unordered_map>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;
//two pointer

class KnumZone{
public:
    int begin;
    int end;
    int kend;
    int k;
    unordered_map<int, int> kmap;
    KnumZone(int begin,int end,int k):begin(begin),end(end),kend(end),k(k){}
    bool isKnum(){
        return kmap.size()==k;
    }
    void remove_num(int val){
        if(kmap[val]>1) kmap[val]--;
        else kmap.erase(val);
    }
    int cnt_subarray(vector<int>& nums){
        int n=end-kend+1;
        int res=0;
        while(kend<=end){
            res+=n;
            remove_num(nums[begin]);
            while(!isKnum()&&n&&kend<nums.size()){
                kmap[nums[kend]]++;
                n--;
                kend++;
            }
            begin++;
            if(begin==nums.size()) break;
        }
        
        return res;
    }
    
    
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int res=0;
        KnumZone ker(0,0,k);
        for(int i=0;i<nums.size();i++){
            if(ker.kmap.size()<k){
                ker.kmap[nums[i]]++;
                ker.end++;
                ker.kend++;
            }else if(ker.isKnum()){
                if(ker.kmap.find(nums[i])!=ker.kmap.end()){
                    ker.end++;
                }else{
                    res+=ker.cnt_subarray(nums);
                    ker.end++;
                }
            }
        }
        if(ker.begin<ker.end) res+=ker.cnt_subarray(nums);
        return res;
    }
private:
   
};

int main(){
    Solution mysolu;
    vector<int> nums = {1,2,1,2,3};
    vector<int> nums1={1,2};
    int k=2;
    int k1=1;
    vector<int> nums2={1,2,1,3,4};
    int k2=3;
    vector<int> nums3={2,1,1,1,2};
    int k3=1;
    int res=mysolu.subarraysWithKDistinct(nums1, k1);
    return 0;
}

