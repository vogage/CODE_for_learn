//
//  338_Counting Bits.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/4.
//

#include <stdio.h>
#include<vector>

using namespace std;



class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> res(num+1,0);
        if(num==0)return res;
        res[1]=1;
        
       // res.push_back(1);
        
        for(int i=2;i<=num;i++){
            int m1=i/2;
            int m2=i-m1;
            if(m1==m2) res[i]=res[m1];
            else{
                res[i]=1+res[i-1];
            }
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    int input=10;
    vector<int> res=mysolu.countBits(input);
    return 0;
}
