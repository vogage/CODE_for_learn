//
//  801_Minimum Swaps To Make Sequences Increasing.cpp
//  leetcode
//
//  Created by qiandehou on 2022/4/6.
//

#include <stdio.h>
#include<vector>

using namespace std;


class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        if(n==0)return 0;
        vector<int> swap(n,0);
        vector<int> fixed(n,0);
        swap[0]=1;
        fixed[0]=0;
        for(int i=1;i<n;i++){
            if(nums1[i]<=nums2[i-1]||nums2[i]<=nums1[i-1]){
                swap[i]=swap[i-1]+1;
                fixed[i]=fixed[i-1];
            }else if(nums1[i]<=nums1[i-1]||nums2[i]<=nums2[i-1])
            {
                fixed[i]=swap[i-1];
                swap[i]=fixed[i-1]+1;
            }else{
                fixed[i]=min(fixed[i-1],swap[i-1]);
                swap[i]=fixed[i]+1;
            }
        }
        return min(swap[n-1],fixed[n-1]);
    }
};



int main(){

    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};
    
    Solution mysolu;
    int res=mysolu.minSwap(nums1, nums2);
    return 0;


}
