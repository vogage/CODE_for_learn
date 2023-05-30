//
//  365_Water and Jug Problem.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/29.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int div=gcd(jug1Capacity,jug2Capacity);
        if(jug1Capacity+jug2Capacity<targetCapacity)return false;
        if(jug1Capacity==targetCapacity||jug2Capacity==targetCapacity||jug1Capacity+jug2Capacity==targetCapacity)return true;
        return targetCapacity%div==0;
    }
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
};

int main(){
    int jug1Capacity=2;
    int jug2Capacity=6;
    int targetCapacity=5;
    Solution mysolu;
    bool res=mysolu.canMeasureWater(jug1Capacity,jug2Capacity,targetCapacity);
    return 0;
}
