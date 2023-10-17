//
//  1014_Best Sightseeing Pair.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/26.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        pair<int,int> begin(values[0],0);
        int res=0;
        for(int i=1;i<values.size();i++){
            res=max(res,values[i]+begin.first+begin.second-i);
            if(values[i]-begin.first>begin.second-i){
                begin.first=values[i];
                begin.second=i;
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> values={8,1,5,2,6};
    vector<int> values1={1,2,2};
    vector<int> values2={2,10,9,3,2};
    int res=mysolu.maxScoreSightseeingPair(values1);
    
    return 0;
}
