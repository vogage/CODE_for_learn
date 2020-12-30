#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;






class Solution {
public:
    int res=0;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        res = amount + 1;
        int index = coins.size()-1;
        coinChange2(coins, index,amount,0);
        return res>amount?-1:res;
    }
   void coinChange2(vector<int>&coins,int index,int amount,int count) {
       if (index < 0)return;
       int number = amount / coins[index];
       for (int i = number; i >= 0; i--) {
           int remain = amount - i * coins[index];
           int newcount = count +i;
           if (remain > 0 && newcount < res) {
               coinChange2(coins, index - 1, remain, newcount);
           }
           else if (newcount < res) {
               res = newcount; break;
           }
       }
       return;
    }
};

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for (int i = 185;i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if(coins[j]<=i)dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1: dp[amount];
    }
};

int main() {
    Solution mysolu;
    //vector<int> coins = { 1,2,5 };
    //int amount = 11;

    //vector<int> coins = { 2 };
    //int amount = 3;

    vector<int> coins = { 186, 419, 83, 408 };
    int amount = 6249;
    int ans = mysolu.coinChange(coins, amount);
    return 0;
}