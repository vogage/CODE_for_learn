#include<string>
#include<vector>

using namespace std;

//Given a string s, return the number of different non - empty palindromic subsequences in s.
//Since the answer may be very large, return it modulo 109 + 7.

//A subsequence of a string is obtained by deleting zero or more characters from the string.
//A sequence is palindromic if it is equal to the sequence reversed.
//Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.

//Input: s = "bccb"
//Output : 6
//Explanation : The 6 different non - empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
//Note that 'bcb' is counted only once, even though it occurs twice.
class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> palind(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            palind[i][i] = 1;
        }
        for (int end = 0; end < n; end++) {
            for (int start = end-1; start >=0; start--) {
                if (s[start] == s[end]) {
                    palind[start][end] = palind[start + 1][end] + 1+ (start+1<=end-1?palind[start + 1][end - 1]:0);
                }
                else {
                    palind[start][end]=palind[start+1][end]+1;
                }
            }
        }
        return palind[0][n - 1];
    }
};

class Solution2 {
public:
    int countPalindromicSubsequences(string s) {
        int len = s.length();
        int mod = 1e9 + 7;

        vector<vector<int>> dp(len, vector<int>(len, 0));

        for (int i = 0; i < len; i++) dp[i][i] = 1;














        for (int gap = 1; gap < len; gap++) {
            for (int i = 0, j = gap; j < len; i++, j++) {

                if (s[i] == s[j]) {

                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[j]) low++;
                    while (low <= high && s[high] != s[j]) high--;

                    if (low > high) {
                        // no occurrence of d in between
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod + 2) % mod;
                    }
                    else if (low == high) {
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod + 1) % mod;
                    }
                    else {
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod - dp[low + 1][high - 1] % mod) % mod;
                    }

                }
                else {
                    dp[i][j] = ((dp[i + 1][j] % mod + dp[i][j - 1] % mod) % mod - dp[i + 1][j - 1] % mod) % mod;
                }

                if (dp[i][j] < 0) dp[i][j] += mod;
            }
        }


        return dp[0][len - 1];
    }
};

int main() {
    Solution2 mysolu;
    string s = "bccb";
    string s1 = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
    int res = mysolu.countPalindromicSubsequences(s);
    return 0;
}

//Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
//Output : 104860361
//Explanation : There are 3104860382 different non - empty palindromic subsequences, which is 104860361 modulo 109 + 7.