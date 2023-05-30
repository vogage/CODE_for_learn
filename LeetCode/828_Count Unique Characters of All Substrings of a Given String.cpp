//
//  828_Count Unique Characters of All Substrings of a Given String.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/17.
//

#include <stdio.h>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> char_vec(26,vector<int>(2,-1));
        //int mod=1e9+7;
        int n=s.size();
        int res=0;
        for(int i=0;i<s.size();i++){
            int c=s[i]-'A';
            res+=(i-char_vec[c][1])*(char_vec[c][1]-char_vec[c][0]);
            char_vec[c][0]=char_vec[c][1];
            char_vec[c][1]=i;
        }
        for(int i=0;i<26;i++){
            res+=(n-char_vec[i][1])*(char_vec[i][1]-char_vec[i][0]);
        }
        return res;
    }
};

class Solution2 {
public:
    int uniqueLetterString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n,0));
        int res=n;
        for(int i=0;i<n;i++) dp[1][i]=1;
        for(int len=2;len<=n;len++){
            for(int j=len-1;j<n;j++){
                int repeat_cout=0;
                for(int k=j-1;k>=j-len+1;k--){
                    if(s[k]==s[j]){repeat_cout++;}
                }
                if(repeat_cout==1) dp[len][j]=dp[len-1][j-1]-1;
                else if(repeat_cout>1) dp[len][j]=dp[len-1][j-1];
                else dp[len][j]=dp[len-1][j-1]+1;
                res+=dp[len][j];
            }
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    string str="LEETCODE";
    string str2="ABC";
    string str3="ABA";
    int res=mysolu.uniqueLetterString(str);
    ;    return 0;
}


