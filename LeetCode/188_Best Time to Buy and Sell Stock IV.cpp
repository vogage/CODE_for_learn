#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2)return 0;
		vector<int> res(prices.size(), 0);
		for (int i = 0; i < k; i++) {
			int initial = i * 2;
			for (int j = initial+1; j < prices.size(); j++) {
				
					cal_sub_maxProfit(initial, i, j, res, prices);
				
			}
		}
		return res.back();
	}
	void cal_sub_maxProfit(int initial,int k,int j, vector<int> &res, vector<int> & prices) {
		
		pair<int, int> min;
		min.first = prices[initial];
		min.second = initial;
		for (int i = initial + 1; i <= j; i++) {
			if (prices[i] < min.first) {
				min.first = prices[i];
				min.second = i;
			}
		}
		if (min.second == j) {
			res[j] = res[j-1];
		}
		else {
			pair<int, int>max_after_min(prices[min.second + 1], min.second + 1);
			for (int i = min.second + 2; i <= j; i++) {
				if (max_after_min.first < prices[i]) {
					max_after_min.first = prices[i];
					max_after_min.second = i;
				}
			}
			if(k>0)res[j] = max(res[min.second-1] + max_after_min.first - min.first,res[j]);
			else {
				res[j] = max_after_min.first - min.first;
			}
		}
		return;
	}
};

class Solution2 {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.size() < 2)return 0;
		vector<int> res(prices.size(), 0);
		if (k > prices.size() / 2)return quicksolve(prices);
		for (int i = 0; i < k; i++) {
			int initial = i * 2;
			vector<int> temp = res;
			
			for (int j = initial + 1; j < prices.size(); j++) {

				cal_sub_maxProfit(initial, i, j, res, prices,temp);

			}
		}
		return res.back();
	}
	void cal_sub_maxProfit(int initial, int k, int sell, vector<int> &res, vector<int> & prices,vector<int>& before_res) {
		
		int buy_index=initial;
		if (k == 0) {
			for (int buy = initial; buy < sell; buy++) {
				int temp = prices[sell] - prices[buy];
				res[sell] = max(res[sell], temp);
				res[sell] = max(res[sell], res[sell - 1]);
			}
		}
		else {
			for (int buy = initial; buy < sell; buy++) {
				int temp = prices[sell] - prices[buy];
				res[sell] = max(before_res[buy - 1] + temp, res[sell]);
				res[sell] = max(res[sell], res[sell - 1]);
			}
		}
		return;
	}

	int quicksolve(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); i++) {
			res += max(0, prices[i] - prices[i - 1]);
		}
		return res;

	}
};



//public int maxProfit(int k, int[] prices) {
//	int len = prices.length;
//	if (k >= len / 2) return quickSolve(prices);
//
//	int[][] t = new int[k + 1][len];
//	for (int i = 1; i <= k; i++) {
//		int tmpMax = -prices[0];
//		for (int j = 1; j < len; j++) {
//			t[i][j] = Math.max(t[i][j - 1], prices[j] + tmpMax);
//			tmpMax = Math.max(tmpMax, t[i - 1][j - 1] - prices[j]);
//		}
//	}
//	return t[k][len - 1];
//}
class Solution3 {
public:
	int maxProfit(int k, vector<int>& prices) {
		int len = prices.size();
		vector<vector<int>> t(k + 1, vector<int>(len, 0));
		for (int i = 1; i <= k; i++) {
			int tempMax = -prices[0];
			for (int j = 1; j < len; j++) {
				// 1,2,4,2,5,7,2,4,9,0
				t[i][j] = max(t[i][j - 1], prices[j] + tempMax);
				tempMax = max(tempMax, t[i - 1][j - 1] - prices[j]);

			}
		}
		return t[k][len - 1];
	}
};
//
//
//private int quickSolve(int[] prices) {
//	int len = prices.length, profit = 0;
//	for (int i = 1; i < len; i++)
//		// as long as there is a price gap, we gain a profit.
//		if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
//	return profit;
//}



int main() {
	vector<int> input = { 2,4,1 };
	vector<int> input2 = { 3,2,6,5,0,3 };
	vector<int> input3 = { 2,1,4,5,2,9,7 };
	vector<int> input4 = { 1,2,4,2,5,7,2,4,9,0 };
	vector<int> input5 = { 1,4,1,4,3,1 };
	int k = 2;
	Solution3 mysolu;
	int res = mysolu.maxProfit(k, input4);
	return 0;
}