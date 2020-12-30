#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res=0;
		 DFS(prices, res, 0,1,0);
		 return res;
		
	}
	void DFS(vector<int>& prices, int& res, int i,int flag1,int flag2) {
		//flag1: 1 can buy    0 not buy
		//flag2:1  can sell     0  not sell
		if (i >= prices.size())return;
		//1. buy
		int res_buy = res;
		buy(prices, res_buy, i, flag1,flag2);
		//2. sell
		int res_sell = res;
		sell(prices, res_sell, i, flag1,flag2);
		//3.cooldown
		int res_cooldown = res;
		cooldown(prices, res_cooldown, i, flag1,flag2);
		//4.do nothing ??
		res = max(res_buy, res_sell);
		res = max(res, res_cooldown);
	}
	void buy(vector<int>& prices, int& res, int i, int flag1,int flag2) {
		if (flag1 != 1) return;
		flag1 = 0;
		flag2 = 1;
		res = res - prices[i];
		DFS(prices, res, i + 1, flag1,flag2);
	}
	void sell(vector<int>&prices, int &res, int i, int flag1,int flag2) {
		if (flag2 != 1) return;
		flag2 = 0;
		res = res + prices[i];
		DFS(prices, res, i + 1, flag1,flag2);
	}
	void cooldown(vector<int>&prices, int &res, int i, int flag1,int flag2) {
		if(flag2==0) flag1 = 1;
		
		DFS(prices, res, i + 1, flag1,flag2);
	}
};


class Solution2 {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<int> buy(n, 0);
		vector<int> sell(n, 0);
		vector<int> cooldown(n, 0);
		sell[0] = -prices[0];
		cooldown[0] = INT_MIN;
		for (int i = 1; i < n; i++) {
			buy[i] = max(buy[i - 1], cooldown[i - 1]);
			sell[i] = max(sell[i - 1], buy[i - 1] - prices[i]);
			cooldown[i] = sell[i - 1] + prices[i];
		}
		return max(buy[n - 1], cooldown[n - 1]);
	}

};


int main() {
	Solution2 mysolu;
	vector<int> input = { 1,2,3,0,2 };
	vector<int> input1 = { 1,2,4 };
	int res = mysolu.maxProfit(input1);
	return 0;
}