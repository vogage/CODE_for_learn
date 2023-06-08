//
//  481_Magical String.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/2.
//

#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        queue<int> nums;
        nums.push(2);
        int cnt=1;
        if(n<2)return n;
        n--;
        
        while(--n){
            int temp=nums.front();
            if(temp==1) cnt++;
            int val=nums.back()==1?2:1;
            nums.pop();
            if(temp==1) nums.push(val);
            else{
                nums.push(val);
                nums.push(val);
            }
            
        }
        return cnt;
    }
};


int main(){
    Solution mysolu;
    int res=mysolu.magicalString(6);
    return 0;
}
