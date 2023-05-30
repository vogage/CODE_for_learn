#include<vector>

using namespace std;
//You are given an array prices where prices[i] is the price of a given stock on the ith day, 
//and an integer fee representing a transaction fee.
//
//Find the maximum profit you can achieve.You may complete as many transactions as you like, 
//but you need to pay the transaction fee for each transaction.
//
//Note: You may not engage in multiple transactions simultaneously(i.e., you must sell the stock before you buy again).
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int  n = prices.size();
        vector<int> dp(n,0);
        //1.buy 2.sell 

        for (int i =1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], prices[i] - prices[j] - fee + (j-1>=0?dp[j - 1]:0));
               
           }
            dp[i] = max(dp[i], dp[i - 1]);
        }
       
        return dp[n-1];
    }
};

class Solution2 {
    int maxProfit(vector<int> prices, int fee) {
        // In day(0), cash(0) (stands for initial profit) is 0, hold(0) is -prices[0]
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // cash(i) = max(cash(i-1), hold(i-1) + prices[i] - fee)
            // cash(i-1) => not holding stock at the end of day(i-1), and do nothing on day(i)
            // hold(i-1) + prices[i] - fee => hold the stock at the end of day(i-1), sell it on day(i)
            // NOTE: so cash(i) >= cash(i-1)
            cash = max(cash, hold + prices[i] - fee);

            // hold(i) = max(hold(i-1), cash(i) - prices[i])
            // hold(i-1) => holding stock at the end of day(i-1), and do nothing on day(i)
            // cash(i) - prices[i] => because cash(i) >= cash(i-1), if selling stock on day(i) results in more cash in hand than cash(i-1), 
            // it makes sense to sell it on day(i) and buy it back instead of selling it on day(i-1) and buy it on day(i).
            // Take the following case as an example:
            // service fee: 1
            // prices: [5, 10, 15, ...]
            // cash[0, 4, 9, ...]
            // hold[-5, -5, ?, ...]
            // Now consider all possible values of hold(2):
            // 1. Do nothing: a = hold(1) = -5
            // 2. Sell on day(1), buy on day(2): b = cash(1) - price(2) = 4 - 15 = -9
            // 3. Sell on day(2), and buy again: c = hold(1) + p(2) - fee - p(2) = -5 + 15 - 1 - 15 = -6
            // c > b, so buying on day(2) results in more profit.
            // However, since a = -5, which is a better choice, finally, hold(2) is resolved to "-5", which is obvious because the price is keeping
            // rising, so the best choice would be buy it on day(0) and hold it.
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};

int main() {
//Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
//Output : 8
//Explanation : The maximum profit can be achieved by :
//-Buying at prices[0] = 1
//- Selling at prices[3] = 8
//- Buying at prices[4] = 4
//- Selling at prices[5] = 9
//The total profit is((8 - 1) - 2) + ((9 - 4) - 2) = 8.
    vector<int> prices = { 1, 3, 2, 8, 4, 9 };
    int fee = 2;

    vector<int> prices2 = { 1, 3, 7, 5, 10, 3 };
    int fee2 = 3;

    vector<int> prices3 = { 4, 5, 2, 4, 3, 3, 1, 2, 5, 4 };
    int fee3 = 1;
    Solution mysolu;
    int res = mysolu.maxProfit(prices2, fee2);
	return 0;
}