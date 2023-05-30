//
//  393_UTF-8 Validation.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/16.
//

#include <stdio.h>
#include<vector>
using namespace std;


class Solution {
public:
    bool validUtf8(vector<int>& data) {
        //For a 1-byte character, the first bit is a 0, followed by its Unicode code.
        //For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
        for(int i=0;i<data.size();){
            int nbyte=cal_bytes(data[i]);
            if(nbyte>4||nbyte<1)return false;
            i++;
            for(int j=0;j<nbyte-1;j++,i++){
                if(i>=data.size())return false;
                if(!valid_byte(data[i]))return false;
               
            }
            
        }
        return true;
    }
    int cal_bytes(int first_code){
        //get the byte
        int mod_num=128;
        int res=0;
        for(int i=0;i<5&&first_code/mod_num!=0;i++){
            res++;
            first_code%=mod_num;
            mod_num/=2;
        }
        return res==0?1:res==1?0:res;
    }
    
    bool valid_byte(int sucess_code){
        if(sucess_code/128==0)return false;
        sucess_code%=128;
        if(sucess_code/64!=0)return false;
        return true;
    }
};

int main(){
    Solution mysolu;
    
    vector<int> data={197,130,1};
    vector<int> data2={235,140,4};
    vector<int> data3={255};
    vector<int> data4={237};
    bool res=mysolu.validUtf8(data4);
    return 0;
}
