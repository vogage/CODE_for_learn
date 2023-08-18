//
//  846_Hand of Straights.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/7.
//

#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> DigitSumMap;
        if(hand.size()%groupSize!=0)return false;
        int n=hand.size()/groupSize;
        for(int i=0;i<hand.size();i++){
            DigitSumMap[hand[i]]++;
        }
        auto itBegin=DigitSumMap.begin();
        for(int i=0;i<n;i++){
            while(itBegin->second==0&&itBegin!=DigitSumMap.end()) itBegin++;
            int b=itBegin->first;
            for(int j=0;j<groupSize;j++){
                int tar=b+j;
                if(DigitSumMap.find(tar)==DigitSumMap.end()||DigitSumMap[tar]<1) return false;
                DigitSumMap[tar]--;
            }
        }
        return true;
    }
};

int main(){
    Solution mysolu;
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    bool res=mysolu.isNStraightHand(hand, groupSize);
    return 0;
}
