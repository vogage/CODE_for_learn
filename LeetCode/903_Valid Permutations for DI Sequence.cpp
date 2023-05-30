#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>

using namespace std;
class Solution2 {
public:
    int numPermsDISequence(string s) {
        int n = s.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= n; i++) dp[0][i] = 1;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            if (s[i] == 'I') {
                
                for (int j = 0; j < n- i; j++) {
                   
                    cur = (cur + dp[i][j]) % mod;
                    dp[i + 1][j] = cur;

                }
            }
            else {
                for (int j = n - i - 1; j >= 0; j--) {
                    
                    cur = (cur + dp[i][j + 1]) % mod;
                    dp[i + 1][j] = cur;
                }
            }
        }
        return dp[n][0];
    }
};

class Solution {
public:
    int numPermsDISequence(string s) {
        memo["I"] = 1;
        memo["D"] = 1;
        memo["DD"] = 1;
        memo["II"] = 1;
        memo["DI"] = 2;
        memo["ID"] = 2;
        return dfs(s);

    }
    int dfs(string s) {
        if (memo.find(s) != memo.end())return memo[s];
        unordered_set<string> sub_str_set;
        long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < s.size(); i++) {
            int left_end = i - 1;
            int right_start = i + 1;
            string temp = (left_end >= 0 ? s.substr(0, left_end + 1) : "")
                + (right_start < s.size() ? s.substr(right_start, s.size() - right_start) : "");
            if (sub_str_set.find(temp) == sub_str_set.end()) {
                res += dfs(temp) % mod;
                res = res % mod;
                sub_str_set.insert(temp);
            }
        }
        memo[s] = (int)res;
        return  memo[s];
    }
private:
    unordered_map<string, int> memo;
};

int main() {
    Solution2 mysolu;
    string s = "DID";
    int res = mysolu.numPermsDISequence(s);

	return 0;
}