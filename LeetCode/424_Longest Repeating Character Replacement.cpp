//
//  424_Longest Repeating Character Replacement.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/19.
//

#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res=INT_MIN;
        
        for(int i=0;i<s.size();i++){
            int temp=RepeatFromThisChar(s,k,i);
            res=max(temp,res);
            while(i<s.size()-1&&s[i]==s[i+1])i++;
        }
        return res;
    }
private:
    int RepeatFromThisChar(const string& s,int k,int index){
        char pre=s[index];
        int cnt=1;
        int i=index+1;
        while(i<s.size()){
            if(s[i]!=pre){
                if(k==0) break;
                k--;
            }
            cnt++;
            i++;
        }
        return min(cnt+k,(int)s.size());
    }
};

//1 <= s.length <= 105
//s consists of only uppercase English letters.
//0 <= k <= s.length

int main(){
    Solution mysolu;
    string s="ABAB";
    string s1="AABABBA";
    string s2="ABBB";
    string s3="KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
    string s4="AAAAA";
    int res=mysolu.characterReplacement(s4,5);
    return 0;
}

