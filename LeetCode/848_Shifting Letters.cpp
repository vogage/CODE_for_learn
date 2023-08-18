//
//  848_Shifting Letters.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/7.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        shifts.back()=shifts.back()%26;
        for(int i=shifts.size()-2;i>=0;i--){
            shifts[i]=(shifts[i+1]+shifts[i])%26;
        }
        for(int i=0;i<s.size();i++){
            s[i]=(s[i]+shifts[i]-'a')%26+'a';
        }
        return s;
    }
};


int main(){
    Solution mysolu;
    string s="abc";
    vector<int> shifts = {3,5,9};
    string res=mysolu.shiftingLetters(s, shifts);
    return 0;
}
