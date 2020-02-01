#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int res = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == '1') {
					if (res == 0)res = 1;
					judge_square(matrix, i, j, res,1);
				}
			}
		}
		return res;
	}

	void judge_square(vector<vector<char>>& matrix, int i, int j, int& res,int len) {
		if (i + len >= matrix.size() || j + len >= matrix[0].size())return;
		for (int k = i; k <= i + len; k++) {
			if (matrix[k][j + len] == '0')return;			
		}
		for (int k = j; k <= j + len; k++) {
			if (matrix[i + len][k] == '0')return;
		}
		res = max(res, (len + 1)*(len + 1));
		judge_square(matrix, i, j, res, len + 1);
	}
};

class Solution2 {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.size() == 0)return 0;
		int res = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j])+1;
				}
				res = max(res, dp[i][j]);
			}
		}
		return res*res;
	}
};
int main() {
	//1 0 1 0 0
	//	1 0 1 1 1
	//	1 1 1 1 1
	//	1 0 0 1 0
	vector<vector<char>> input;
	vector<char> temp = { '1','0','1','0','0' };
	input.push_back(temp);
	temp = { '1','0','1','1','1' };
	input.push_back(temp);
	temp = { '1','1','1','1','1' };
	input.push_back(temp);
	temp = { '1','0','0','1','0' };
	input.push_back(temp);

	//[["1", "0", "1", "0", "0"], 
	//["1", "0", "1", "1", "1"], 
	//["1", "1", "1", "1", "1"], 
	//["1", "0", "0", "1", "0"]]

	Solution2 mysolu;
	int res = mysolu.maximalSquare(input);

	return 0;
}