//
//  1003_Check If Word Is Valid After Substitutions.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/21.
//

#include <stdio.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        string temp="abc";
        int i=0;
        while(i<s.size()){
            if(s[i]=='a'){
                int k=0;
                while(k<3&&i<s.size()&&s[i]==temp[k]){ i++;k++;}
                for(int j=2;j>=k;j--) st.push(temp[j]);
            }else if(!st.empty()&&s[i]==st.top()){
                while(i<s.size()&&!st.empty()&&s[i]==st.top()){
                    st.pop();
                    i++;
                }
            }else return false;
        }
        return st.empty();
    }
};


int main(){
    Solution mysolu;
    string s = "abcabcababcc";
    string s1= "aabcbc";
    string s2="aabbcc";
    bool res=mysolu.isValid(s2);//
    return 0;
}
