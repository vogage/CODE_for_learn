//
//  880_Decoded String at Index.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/16.
//

#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

//2 <= s.length <= 100
//s consists of lowercase English letters and digits 2 through 9.
//s starts with a letter.
//1 <= k <= 109
//It is guaranteed that k is less than or equal to the length of the decoded string.
//The decoded string is guaranteed to have less than 263 letters.

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<pair<string,long long>> st;
        st.push(pair<string,long long>("",0));
        string temp="";
        long long repeat=0;
        long long totalnum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]<='z'&&s[i]>='a') temp+=s[i];
            else{
                repeat=repeat*10+s[i]-'0';
                totalnum=(st.top().second+temp.size())*repeat;
                if(totalnum>k)break;
                if(i+1<s.size()&&s[i+1]>='a'&&s[i+1]<'z'){
                    st.push(pair<string,long long>(temp,totalnum));
                    repeat=0;
                    temp="";
                }
            }
        }
        if(temp!="") st.push(pair<string,long long>(temp,totalnum));
        return gst(st,k-1);
    }
private:
    string gst(stack<pair<string,long long>>& st,int k){
        pair<string,long long> p1,p2;
        if(!st.empty()){
            p1=st.top();
            st.pop();
        }
        while(!st.empty()){
           
            p2=st.top();
            st.pop();
            long long repeatnum=p2.second+p1.first.size();
            k=k%repeatnum;
            if(k>=p2.second) break;
            else{
                p1=p2;
            }
           
        }
        k=k-p2.second;
        string res="";
        res.push_back(p1.first[k]);
        return res;
    }
};


int main(){
    Solution mysolu;
    string s = "leet2code3";
    string s1="a2345678999999999999999";
    string s2="ha22";
    string s3="a23";
    string s4="a2b3c4d5e6f7g8h9";
    string s5="vzpp636m8y";
    string s6="l3mtm5weq7ki78c7hck4";
    int k5=2920;
    int k4=9;
    int k3=6;
    int k2=5;
    int k = 10;
    int k1=1;
    int k6=165511;
    string res=mysolu.decodeAtIndex(s5, k5);
    return 0;
}
