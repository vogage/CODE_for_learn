//
//  829_Consecutive Numbers Sum.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/1.
//

#include <stdio.h>
#include <vector>

using namespace std;


class Solution {
public:
    int consecutiveNumbersSum(int n) {
        // 1.the consecutive num is odd
        int k=0;
        int odd_cnt=0;
        while(1){
            int ConseNum=2*k+1;
            int mid=n/ConseNum;
            if(mid<=k) break;
            if(n%ConseNum==0) odd_cnt++;
            k++;
        }
        
        //2. the consecutive num is even
        k=1;
        int even_cnt=0;
        while(1){
            int ConseNum=2*k;
            int mid=n/ConseNum;
            if(mid<k)break;
            if(n%k==0){
                int even_sum=n/k;
                if(even_sum%2==1) even_cnt++;
            }
            k++;
        }
        return odd_cnt+even_cnt;
        
    }
};


int main(){
    Solution mysolu;
    int n=15;
    int res=mysolu.consecutiveNumbersSum(n);
    return 0;
}
