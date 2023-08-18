//
//  869_Reordered Power of 2.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/14.
//

#include <stdio.h>
#include <string>
#include <queue>

using namespace std;


//bool reorderedPowerOf2(int N) {
//    long c = counter(N);
//    for (int i = 0; i < 32; i++)
//        if (counter(1 << i) == c) return true;
//    return false;
//}
//
//long counter(int N) {
//    long res = 0;
//    for (; N; N /= 10) res += pow(10, N % 10);
//    return res;
//}

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        //count the num of 1 digit
        string str=to_string(n);
        if(isPowerOf2(str)) return true;
        if(dfs(0,str.size(),str)) return true;
        return false;
    }
private:
    bool dfs(int begin,int end,string str){
        if(begin+1==end)return false;
       
        if(dfs(begin+1,end,str)) return true;
        for(int i=begin+1;i<end;i++){
            string tempstr=str;
            char tempchar=str[begin];
            tempstr[begin]=tempstr[i];
            tempstr[i]=tempchar;
            if(isPowerOf2(tempstr)) return true;
            if(dfs(begin+1,end,tempstr)) return true;
        }
        return false;
    }
    
    bool isPowerOf2(string &str){
        if(str[0]=='0')return false;
        int res=stoi(str);
        //count the num of 1 digit
        int cnt=0;
        while(res){
            if(res%2) cnt++;
            res=res>>1;
        }
        return cnt==1;
    }
};


int main(){
    Solution mysolu;
    bool res=mysolu.reorderedPowerOf2(4069);
    return 0;
}
