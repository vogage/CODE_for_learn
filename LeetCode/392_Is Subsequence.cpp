#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0;
        for (int i = 0; i < t.size(); i++) {
            if (s[j] == t[i]) {
                j++;
            }

        }
        return j == s.size();
    }
};

int main() {
    string s = "abc";
    string t = "ahbgdc";
    Solution mysolu;
    bool res = mysolu.isSubsequence(s, t);
    return 0;
}