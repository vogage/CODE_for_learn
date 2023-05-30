//
//  476_Number Complement.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/29.
//

#include <stdio.h>


class Solution {
public:
    int findComplement(int num) {
        int temp=1;
        int res=num;
        res=res>>1;
        while(res){
            res=res>>1;
            temp=temp<<1;
            temp+=1;
        }
        return temp^num;
    }
};

int main(){
    Solution mysolu;
    int res=mysolu.findComplement(5);
    return 0;
}
