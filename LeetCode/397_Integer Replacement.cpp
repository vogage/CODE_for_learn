#include<vector>
#include<map>

using namespace std;

class Solution {
    map<int, int> visited;
public:
    int integerReplacement(int n) {
        
        if (n == 1)return 0;
        if (visited.find(n) ==visited.end()) {
            if ((n & 1) == 1) {
                visited[n] = min(integerReplacement(n/2+1), integerReplacement((n - 1) / 2)) + 2;
            }
            else {
                visited[n] = integerReplacement(n / 2)+1;
            }
        }
        return visited[n];
    }
};


class Solution2 {
public:
    int integerReplacement(int n) {
        vector<int>dp(n + 2, INT_MAX);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                dp[i] = dp[i / 2] + 1;
            }
            else {
                dp[i] = min(dp[(i + 1)/2]+1, dp[i - 1]) + 1;
            }
        }
        return dp[n];
    }
};


int main() {
    int n = 65535;
    Solution mysolu;
    int res = mysolu.integerReplacement(n);
	return 0;
}