//
//  921_Minimum Add to Make Parentheses Valid.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/26.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') open++;
            else{
                if(open>0) open--;
                else res++;
            }
        }
        return res+open;
    }
};


int main(){
    Solution mysolu;
    string str="()))((";
    int res=mysolu.minAddToMakeValid(str);
    return 0;
}
