//
//  991_Broken Calculator.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue>=target) return startValue-target;
        if(target%2==1){
            return 2+brokenCalc(startValue, (target+1)/2);
        }else return 1+brokenCalc(startValue, target/2);
    }
};
int main(){
    Solution mysolu;
    int startValue = 3, target = 10;
    int res=mysolu.brokenCalc(startValue, target);
    return 0;
}
