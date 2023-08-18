//
//  858_Mirror Reflection.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/11.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int tp=0;int tq=0;
        vector<int> res={-1,0,2,1};
        while(tq%p!=0||((tq/p)%2==0&&tp%2==0)){
            tq+=q;
            tp++;
        }
        return res[(tq/p)%2*2+tp%2];
    }
};
int main(){
    Solution mysolu;
    int res=mysolu.mirrorReflection(2, 1);
    return 0;
    
}
