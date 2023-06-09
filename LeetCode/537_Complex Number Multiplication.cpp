//
//  537_Complex Number Multiplication.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/9.
//

#include <stdio.h>
#include <string>

using namespace std;


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {

        pair<int,int> p1=str2complex_num(num1);
        pair<int,int> p2=str2complex_num(num2);
        
        pair<int,int> pm;
        pm.first=p1.first*p2.first-p1.second*p2.second;
        pm.second=p1.second*p2.first+p1.first*p2.second;
        return to_string(pm.first)+"+"+to_string(pm.second)+"i";
    }
private:
    pair<int,int> str2complex_num(const string& num){
        pair<int,int> res;
        int index=0;
        for(;index<num.size();index++){
            if(num[index]=='+')break;
        }
        res.first=stoi(num.substr(0,index));
        res.second=stoi(num.substr(index+1,num.size()-index-2));
        return res;
    }
};


int main(){
    Solution mysolu;
    string num1 = "1+1i";
    string num2 = "1+1i";
    string res=mysolu.complexNumberMultiply(num1, num2);
    return 0;
}

