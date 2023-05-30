#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>>dp(2, vector<int>(n+1, 0));
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                // case1 the next char is 1;
                // case2 the next char is 0;
                dp[0][i] = min(dp[0][i + 1], dp[1][i + 1]);
                dp[1][i] = 1 + dp[1][i + 1];
            }
            else {
                dp[0][i] = 1 + min(dp[0][i + 1], dp[1][i + 1]);
                dp[1][i] = dp[1][i + 1];
            }
        }
        return min(dp[1][0], dp[0][0]);
    }
};


int main() {
    Solution mysolu;
    string s = "00110";
    string s1 = "010110";
    string s2 = "00011000";
     
    int res = mysolu.minFlipsMonoIncr(s2);

	return 0;
}