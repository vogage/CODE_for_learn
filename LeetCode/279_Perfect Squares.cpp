#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int numSquares(int n) {
		int floor = 0;
		int res =INT_MAX;
		
		dp(n, floor,res);

		if (n % 3 == 0) {
			int n0 = sqrt(n/3);

			if(n/3-n0*n0==0)res = min(res, 3);
		}
		if (n % 2 == 0) {
			int n0 = sqrt(n / 2);
			if (n / 2 - n0 * n0 == 0)res = min(res, 2);
		}
		return res;
	}
	void dp(int n, int floor,int& res) {
		
		if (n == 0) {
			res = min(res, floor);
			return;
		}
		if (n == 1) {
			res = min(res, floor + 1);
			return;
		}
		int n1 = sqrt(n);
		dp(n - n1 * n1, floor + 1, res);
		return;
	}
};


class Solution2 {
public:
	int numSquares(int n) {
		int res = INT_MAX;
		dp(n, 0, res);
		return res;
	
	}
	void dp(int n, int floor,int &res) {
		if (n == 0) {
			res =min(res, floor);
			return;
		}
		
		if (floor >= res)return;
		for (int i = sqrt(n); i >0; i--) {
			int m = n - i * i;
		     
			dp(m, floor + 1, res);
		}
	}

};

class Solution3 {
public:
	int numSquares(int n) {
		if (n <= 0)return 0;
		vector<int> res(n + 1, INT_MAX); 
		res[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j*j <= i; j++) {
				//int as = res[i - j * j] + 1;
				res[i] = min(res[i], res[i-j*j]+ 1);
			}
		}
		return res.back();
	}
};

int main() {
	Solution3 mysolu;
	int res = mysolu.numSquares(254);
	return 0;
}