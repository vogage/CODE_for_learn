//
//  870_Advantage Shuffle.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/15.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class cmp{
public:
    bool operator()(pair<int,int>& p1,pair<int,int>& p2){
        return p1.first>p2.first;
    }
};

typedef priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> PQ;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=min(nums1.size(),nums2.size());
        vector<int> res(n,-1);
        vector<int> NoUseVec;
        PQ pqmin1,pqmin2;
        
        for(int i=0;i<n;i++){
            pqmin1.push(pair<int,int>(nums1[i],i));
            pqmin2.push(pair<int,int>(nums2[i],i));
        }
        while(!pqmin1.empty()){
            while(!pqmin1.empty()&&pqmin1.top().first<=pqmin2.top().first){
                NoUseVec.push_back(pqmin1.top().second);
                pqmin1.pop();
            }
            if(pqmin1.empty())break;
            res[pqmin2.top().second]=pqmin1.top().first;
            pqmin1.pop();
            pqmin2.pop();
        }
        for(int i=0;i<NoUseVec.size();i++){
            res[pqmin2.top().second]=nums1[NoUseVec[i]];
            pqmin2.pop();
        }
        return res;
    }
};


int main(){
//Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//Output: [2,11,7,15]
    Solution mysolu;
    vector<int> nums1={2,7,11,15};
    vector<int> nums2={1,10,4,11};
    vector<int> nums11={0};
    vector<int> nums12={0};
    vector<int> res=mysolu.advantageCount(nums11, nums12);
    return 0;
}
