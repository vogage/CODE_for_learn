#include<string>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> dic_m;
        for (int i = 0; i < s.size(); i++) {
            if (dic_m.find(s[i]) == dic_m.end()) {
                dic_m[s[i]] = i;
            }
            else {
                bool flag_c =false;
                for (int j = dic_m[s[i]] + 1; j < i; j++) {
                    if (s[j] < s[i]&&s[j]!='0') {
                        s[dic_m[s[i]]] = '0';
                        dic_m[s[i]] = i;
                        flag_c = true;
                        break; 
                    }
                }
               if(!flag_c) s[i] = '0';

            }
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '0')res += s[i];
        }
        return res;
    }
};


class Solution1 {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dic(26, 0);
        for (int i = 0; i < s.size(); i++) {
            dic[s[i] - 'a']++;
        }
        stack<char> st;
        vector<bool> visited(26, false);
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
           
            dic[index]--;
            if (visited[index]) continue;
            while (!st.empty() && dic[st.top()-'a'] && s[i] < st.top()) {
                visited[st.top() - 'a'] = false;
                st.pop();

            }
            st.push(s[i]);
            visited[s[i] - 'a'] = true;

        }
        string res="";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution1 mysolu;
    string  s = "bcabc";
    string s1 = "cbacdcbc";
    // acdb
    string ans = mysolu.removeDuplicateLetters(s1);
    return 0;
}