//
//  1017_Convert to Base -2.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/27.
//

#include <stdio.h>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        string res="";
        vector<int> resbits(64,0);
        int index=0;
      
        while(n){
            int tail=n%2;
            if(tail==1){
                if(index%2==1){
                    resbits[index]++;
                    resbits[index+1]++;
                }else{
                    resbits[index]++;
                }
            }
            n=n/2;
            index++;
        }
        for(int i=0;i<=resbits.size();i++){
            res+=resbits[i]+'0';
        }
        reverse(res.begin(),res.end());
        return res.substr(res.find('1'));
        
    }
};

int main(){
    Solution mysolu;
    string res=mysolu.baseNeg2(6);
    return 0;
}
