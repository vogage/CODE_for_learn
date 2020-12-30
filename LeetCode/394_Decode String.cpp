#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') st.push(s[i]);
            else {
                string temp = "";
                string res_temp = "";
                while (!st.empty()&&st.top()!='[') {
                    char c = st.top();
                    st.pop();
                    temp += c;
                }
                reverse(temp.begin(), temp.end());
                string num = "";
                st.pop();
                while (!st.empty()&&'0'<=st.top()&&st.top()<='9') {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());
                for (int j = 0; j < stoi(num); j++) {
                    res_temp += temp;
                }
                for (int j = 0; j < res_temp.size();j++) {
                    st.push(res_temp[j]);
                }
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "100[leetcode]";
    Solution mysolu;
    string res = mysolu.decodeString(s3);
    return 0;
}