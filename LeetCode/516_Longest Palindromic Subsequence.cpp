#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        mem = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) {
            mem[i][i] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j =i-1; j>=0; j--) {
                if (s[i] == s[j]) mem[i][j] = 2 + mem[i - 1][j + 1];
                else {
                    mem[i][j] = max(mem[i - 1][j], mem[i][j + 1]);
                }
            }
        }
        return mem[n-1][0];
    }
private:
    vector<vector<int>> mem;
};


class Solution2 {
public:
    int longestPalindromeSubseq(string s) {
        
        int start = 0;
        int end = s.size() - 1;
        int res = 0;
        if (s.size() == 1)return 1;
        dfs(start, end, s);
        return str_substr_map[s];
    }
private:
    int dfs(int start, int end, const string& s) {
        if (start == end)return 1;
        if (start >end)return 0;
        string substr = s.substr(start, end - start + 1);
        if (str_substr_map.find(substr) != str_substr_map.end())return str_substr_map[substr];
        if (s[start] == s[end]){
            int res=2 + dfs(start + 1, end - 1, s); 
            str_substr_map[substr] = res;
            return res;
        }
        int res=max(dfs(start + 1, end, s), dfs(start, end - 1, s));
        str_substr_map[substr] = res;
        return res;
           
    }
    unordered_map<string, int> str_substr_map;

};


int main() {
    Solution mysolu;
    string str = "bbbab";
    string str1 = "cbbd";
    string str2 = "aaa";
    string str4 = "a";
    int res = mysolu.longestPalindromeSubseq(str4);
    return 0;
}