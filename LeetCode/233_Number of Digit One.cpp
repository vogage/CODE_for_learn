//
//  233_Number of Digit One.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/17.
//

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if(n==0)return 0;
        string str=to_string(n);
        int Ten=1;
        DigitNumOneVec.push_back(1);
        for(int i=1;i<str.size();i++){
            Ten*=10;
            DigitNumOneVec.push_back(Ten+10*DigitNumOneVec[i-1]);
        }
        return help(str);
        
        
        
//        if(str[0]>'1') return total+countDigitOne(stoi(str.substr(1,str.size()-1)));
//        else if(str[0]=='1') return stoi(str.substr(1,str.size()-1))+1+countDigitOne(stoi(str.substr(1,str.size()-1)));
//        else return countDigitOne(stoi(str.substr(1,str.size()-1)));
    }
private:
    vector<int> DigitNumOneVec;
    int help(string str){
        if(str.size()==1) return 1;
        int n=str.size();
        string sub=str.substr(1,n-1);
        if(str[0]>'1') return (str[0]-'1')*DigitNumOneVec[n-2]+10*sub.size()+2*help(sub);
        // 10*sub.size() : the first digit is 1;
        // str[0]-'1' :the number which is less than first digit. e.g. first digit =3 ,the num less than 3 is 2 : 1,2
        //
        else if(str[0]=='1') return stoi(sub)+1+(sub[0]>'0'?2*help(sub):help(sub));
        else return help(sub);
       
    }
    
};


int main(){
    Solution mysolu;
    int n=6234;
    int res=mysolu.countDigitOne(21);
    return 0;
}
