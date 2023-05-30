//
//  357_Count Numbers with Unique Digits.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/28.
//

#include <stdio.h>


class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        int res=0;
        int count=9;
        int temp=9;
        if(n==0)return 1;
        
        for(int i=1;i<n;i++){
            temp=temp*count;
            count--;
            res=res+temp;
        }
        
       
        
        return res+10;
    }
};


int main(){
    Solution mysolu;
    int ans=mysolu.countNumbersWithUniqueDigits(3);
    return 0;
}
