//
//  1033_Moving Stones Until Consecutive.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/13.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> dat;
        dat.push_back(a);
        dat.push_back(b);
        dat.push_back(c);
        sort(dat.begin(),dat.end());
        vector<int> res(2,0);
        int dist1=dat[1]-dat[0];
        int dist2=dat[2]-dat[1];
        if(dist1==2||dist2==2) res[0]=1;
        else{
            if(dist1>2) res[0]++;
            if(dist2>2) res[0]++;
        }
        if(dist1>1) res[1]+=dist1-1;
        if(dist2>1) res[1]+=dist2-1;
        return res;
    }
};

int main(){
    Solution mysolu;
    int a=1;
    int b=2;
    int c=5;
    vector<int> res=mysolu.numMovesStones(a, b, c);
    return 0;
}
