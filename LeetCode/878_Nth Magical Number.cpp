//
//  878_Nth Magical Number.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/16.
//

#include <stdio.h>


class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long end,repeat;
        // calculate the min common multiple
        if(a>b){
            end=(long long)a*(long long)n;
            repeat=calComMul(a,b);
        }else{
            end=(long long)b*(long long)n;
            repeat=calComMul(b,a);
        }
        
        long long begin=n;
        int mod=1000000007;
    
        while(begin<end){
            long long mid=(begin+end)/2;
            long long cnt=mid/(long long)a+mid/(long long)b-mid/repeat;
            if(cnt>=n) end=mid;
            else begin=mid+1;
        }
        return begin%mod;
    }
private:
    int calComMul(int a,int b){
        int comDiv=gcd(a,b);
        if(a%comDiv==0) return (long long)(a/comDiv)*(long long)b;
        else return a*b;
    }
    int gcd(int a,int b){
        if(a%b==0) return b;
        else return gcd(b,a%b);
    }
};

int main(){
    Solution mysolu;
    int res=mysolu.nthMagicalNumber(206117388,938, 24479);
    return 0;
}
