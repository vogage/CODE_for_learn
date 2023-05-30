#include<vector>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		int n = matrix.size();
		vector<int> dp_pre = matrix.back();
		vector<int> dp(n, 0);
		for (int i = n -2; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				int temp_path =dp_pre[j];
				if (j - 1 >= 0) temp_path = min(dp_pre[j - 1], temp_path);
				if (j + 1 < n) temp_path = min(dp_pre[j + 1], temp_path);
				dp[j] = matrix[i][j] + temp_path;
			}
			dp_pre = dp;
		}
		int res = INT_MAX;
		if (n == 1) dp = dp_pre;
		for (int i : dp) res = min(res, i);
		return res;
    }
};


int main() {
	Solution mysolu;
	vector<vector<int>> matrix = { {2,1,3},{6,5,4},{7,8,9} };
	vector<vector<int>> matrix1 = { {-19,57},{-40,-5} };
	int res = mysolu.minFallingPathSum(matrix1);
	return 0;
}