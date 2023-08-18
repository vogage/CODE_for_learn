//
//  862_Shortest Subarray with Sum at Least K.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/13.
//

#include <stdio.h>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        map<long long,int> VIMap;
        int n=nums.size();
        vector<long long> sums(n+1,0);
        long long temp=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];
            sums[i+1]=temp;
        }
       
        VIMap[0]=0;
        int res=nums.size();
        for(int i=1;i<=n;i++){
            auto vbegin=VIMap.lower_bound(sums[i]);//The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val
            if(vbegin!=VIMap.end())VIMap.erase(vbegin,VIMap.end());
            VIMap[sums[i]]=i;

            auto vLessIndex=VIMap.upper_bound(sums[i]-(long long)k);
            if(vLessIndex!=VIMap.begin()){
                vLessIndex--;
                res=min(res,i-vLessIndex->second);
                auto left=VIMap.begin();
                while(left->second+res<i){
                    auto e=left;
                    left++;
                    VIMap.erase(e);
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums = {2,-1,2};
    int k = 3;
    
    vector<int> nums1={98408,68055,-242,-30837,-32199,-37883,29031,78553,69131,-48420,-44596,40345,-29328,71093,29449,96503,16445,-40618,-44568,-14463,26675,-178,-16201,26116,-30553,-41026,4747,89157,-47865,15963,46716,46730,-9637,-43422,53846,-48159,24650,-5188,-43580,-772,73710,74677,-21382,48851,73280,83219,53598,63355,-32874,57103,97656,58056,98463,81672,-3613,-14643,52197,18938,77782,95206,20389,67417,60037,-25277,88537,55731,79680,94462,-45789,-12104,69509,-30872,64869,42050,75810,18522,51794,6392,22212,36361,-40304,70048,-6087,33855,96789,-43234,-10420,-6263,11916,-6644,76439,32034,83580,-47129,78135,-32879,85482,21243,6158,26496,-49154,95408,16228,46171,14287,12760,47239,43674,42764,29038,36467,-33692,16649,67380,-19264,-14135,8200,34100,72632,-41768,34224,10799,72831,10666,34896,-23222,96415,-25419,13023,29052,79082,-8795,-37857,-15909,-13594,-36568,-22567,28483,75850,-47417,-48851,-38811,13986,39786,73325,61052,-35638,-24886,7118,72319,96268,26436,-27428,61561,98998,26311,-35436,49212,-24323,18259,-4272,-25267,-29726,77755,13627,79837,-1794,46878,-11715,-32339,-43381,-28945,-9858,-35780,64130,-11190,68690,-41955,96720,-36150,94420,-13356,62179,33156,72533,69441,-20540,26554,-33873,1505,-35886,7513,14607,78831,54778,20645,-20535,-28752,-32918,48099};
    int k1=2796018;
    int res=mysolu.shortestSubarray(nums1, k1);
    return 0;
}
