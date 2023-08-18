//
//  856_Score of Parentheses.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/10.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int scoreOfParentheses(string s) {
        int res=0;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push('(');
            }else{
                if(st.top()=='('){
                    st.pop();
                    st.push(-1);
                }else{
                    int sum=0;
                    while(st.top()!='('){
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*sum);
                }
            }
        }
        return -st.top();
    }
};

int main(){
    Solution mysolu;
    string s="((())())";
    int res=mysolu.scoreOfParentheses(s);
    return 0;
}
