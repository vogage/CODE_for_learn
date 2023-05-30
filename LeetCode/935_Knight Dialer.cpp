#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int knightDialer(int n) {
		unordered_map<int, vector<int>> dial_map;
		dial_map[0] = { 4,6 };
		dial_map[1] = { 6,8 };
		dial_map[2] = { 7,9 };
		dial_map[3] = { 4,8 };
		dial_map[4] = { 0,3,9 };
		dial_map[6] = { 0,1,7 };
		dial_map[7] = { 2,6 };
		dial_map[8] = { 1,3 };
		dial_map[9] = { 2,4 };
		vector<long long> dp_pre(10, 1);
		vector<long long> dp(10,0);
		long mod = 1e9 + 7;
		for (int i = 2; i <= n; i++) {
			dp = vector<long long>(10, 0);
			for (auto m : dial_map) {
				for (int j = 0; j < m.second.size(); j++) {
					dp[m.first] += dp_pre[m.second[j]];
					
				}
				dp[m.first]= dp[m.first] % mod;
			}
			dp_pre = dp;
			
		}
		long res = 0;
		if (n == 1)return 10;
		for (auto i : dp) {
			res += i;
			res =res % mod;
		}
		return (int)res;
    }
};

int main() {
	int n = 2;
	Solution mysolu;
	int res = mysolu.knightDialer(3131);
	return 0;
}