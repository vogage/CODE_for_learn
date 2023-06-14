//
//  556_Next Greater Element III.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/12.
//

#include <stdio.h>
#include <string>
#include <queue>
//#defineINT_MAX2147483647
using namespace std;
//Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
class Solution {
public:
    int nextGreaterElement(int n) {
        string str=to_string(n);
        priority_queue<char,vector<char>,less<char>> CandidateChars;
        CandidateChars.push(str.back());
        int i=str.size()-2;
        for(;i>=0;i--){
            if(str[i]<CandidateChars.top()) break;
            CandidateChars.push(str[i]);
        }
        if(i==-1)return -1;
        int swapj=0;
        for(int k=str.size()-1;k>i;k--){
            str[k]=CandidateChars.top();
            CandidateChars.pop();
            if(str[k]>str[i]) swapj=k;
        }
        char temp=str[swapj];
        str[swapj]=str[i];
        str[i]=temp;
        
        string IntMax=to_string(INT_MAX);
        
        return IntMax.size()==str.size()&&str>IntMax?-1:stoi(str);
        
    }
};


int main(){
    Solution mysolu;
    int n=13;
    int n1=1234;
    int n2=430241;
    int n3=21;
    int n4=2147483476;
    int n5=230241;
    int res=mysolu.nextGreaterElement(n4);
    
    
    return 0;
}
