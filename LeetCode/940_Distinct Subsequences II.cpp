#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> char_vec(26, -1);
        int n = s.size();
        vector<long> dp(n+1, 0);
        dp[0] = 1;
       
        int mod = 1e9 + 7;
        for (int i =0; i < s.size(); i++) {
            int index = s[i] - 'a';
            dp[i+1] = dp[i] * 2%mod;
            if (char_vec[index] >= 0) dp[i + 1] -= dp[char_vec[index]];
            char_vec[index] = i;
            
        }
    
        return (int)dp.back()-1;
    }
};


class Solution2 {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long>dp(n + 1, 0);
        long mod = 1e9 + 7;
        for (int end_char_index = 0; end_char_index < n; end_char_index++) {
            int pre_end_char = end_char_index - 1;
            for (; pre_end_char >= 0; pre_end_char--) {
                if (s[end_char_index] != s[pre_end_char]) {
                    dp[end_char_index] += dp[pre_end_char];
                    dp[end_char_index] %= mod;
                }
                else {
                    dp[end_char_index] += dp[pre_end_char];
                    dp[end_char_index] %= mod;
                    break;
                }
            }
            if (pre_end_char == -1) dp[end_char_index]++;
        }
        long res = 0;
        for (long i : dp) {
            res = (res + i) % mod;
        }
        return (int)res;
    }
};


int main() {
    Solution mysolu;
    string s = "abc";
    string s1 = "aba";
    string s2 = "aaa";
    string s3 = "lee";
    int res = mysolu.distinctSubseqII(s3);
    return 0;
}