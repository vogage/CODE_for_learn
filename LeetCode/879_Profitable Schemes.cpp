#include<vector>

using namespace std;

class Node {
public:
    Node(int _profit, int _group, int _scheme) :profit(_profit), group(_group), scheme(_scheme) {};
    int profit;
    int group;
    int scheme;
};
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<long>> dp_pre(minProfit + 1,vector<long>(n + 1,0));
        vector<vector<long>> dp(minProfit + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for (int i = 0; i < profit.size(); i++) {
            dp_pre = dp;
            for (int p1 = 0; p1 <= minProfit; p1++) {
                int p2 = min(p1 + profit[i], minProfit);
                for (int g1 = 0; g1 <= n - group[i]; g1++) {
                    int g2 = g1 + group[i];
                    dp[p2][g2] += dp_pre[p1][g1];
                    dp[p2][g2] %= mod;
                }
            }
        }
        long res = 0;
        for (int i = 0; i <= n; i++) {
            res += dp[minProfit][i];
            res %= mod;
        }
        return (int)res;
    }
};

int main() {
    Solution mysolu;
    //n = 10, minProfit = 5, group = [2, 3, 5], profit = [6, 7, 8]
    vector<int> group = { 2, 3, 5 };
    vector<int> profit = { 6, 7, 8 };
    int n = 10;
    int minProfit = 5;

   // 1
   //     1
   //     [2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 2, 1, 2, 1, 1, 2, 1, 2, 1, 2, 2, 2, 2,
   //  1, 1, 2, 2, 2, 1, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 
   // 1, 2, 2, 2, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 1, 
   // 1, 2, 2, 1, 1, 2, 2, 1, 2, 2, 1, 1, 2, 2, 2, 2, 2]
   //      [2, 1, 2, 2, 2, 1, 0, 1, 2, 0, 0, 2, 2, 1, 1, 1, 2, 0, 1, 1, 2, 0, 2, 2, 1, 0, 1, 
  //  0, 1, 2, 2, 1, 1, 2, 0, 2, 1, 1, 1, 1, 1, 2, 0, 1, 0, 2, 2, 2, 2, 2, 0, 1, 1, 2, 1, 0, 1, 
  //      0, 0, 2, 1, 0, 2, 0, 2, 1, 1, 1, 0, 1, 0, 1, 2, 2, 0, 1, 1, 2, 2, 0, 1, 0, 0, 1, 1, 2,
  //      2, 2, 2, 1, 0, 0, 1, 2, 1, 1, 1, 1, 0, 1]

    vector<int> group1 = { 2,2,2,2,2,2,1,2,1,1,2,1,2,2,2,1,2,1,1,2,1,2,1,2,2,2,2,1,
        1,2,2,2,1,1,2,1,2,2,2,1,2,2,2,2,1,2,2,1,2,2,1,1,1,1,1,1,2,2,2,2,1,1,1,2,1,1,1,2,
        1,1,1,2,1,1,1,2,2,1,1,2,2,2,1,1,2,2,1,1,2,2,1,2,2,1,1,2,2,2,2,2 };
    vector<int> profit1 = { 2,1,2,2,2,1,0,1,2,0,0,2,2,1,1,1,2,0,1,1,2,0,2,2,1,0,1,0,
        1,2,2,1,1,2,0,2,1,1,1,1,1,2,0,1,0,2,2,2,2,2,0,1,1,2,1,0,1,0,0,2,1,0,2,0,2,1,1,1,
        0,1,0,1,2,2,0,1,1,2,2,0,1,0,0,1,1,2,2,2,2,1,0,0,1,2,1,1,1,1,0,1 };
    int res = mysolu.profitableSchemes(1, 1, group1, profit1);

    return 0;

}