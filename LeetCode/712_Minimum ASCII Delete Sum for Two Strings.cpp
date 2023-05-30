#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i >=0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + s1[i] + s2[j];
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        int res = 0;
        for (char c : s1)res += c;
        for (char c : s2)res += c;

        return res-dp[0][0];
    }

private:
   
   
};

int main() {
    string s1 = "delete";
    string s2 = "leet";
    Solution mysolu;
    int res = mysolu.minimumDeleteSum(s1, s2);
    return 0;
}
