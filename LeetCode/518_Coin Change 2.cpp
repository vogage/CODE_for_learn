#include<vector>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;

//1 <= coins.length <= 300
//1 <= coins[i] <= 5000
//All the values of coins are unique.
//0 <= amount <= 5000

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> picks(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); i++) {
            picks[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                if (i >= 1) {
                    picks[i][j] += picks[i - 1][j] + (j - coins[i] >= 0 ? picks[i][j - coins[i]] : 0);
                }
                else {
                    picks[i][j] += j - coins[i] >= 0 ? picks[i][j - coins[i]] : 0;
                }

            }
        }
        return picks[coins.size()-1][amount];
    }
private:

};


int main() {
    Solution mysolu;
    //Input: amount = 5, coins = [1, 2, 5]
    vector<int> coins = { 1, 2, 5 };
    int amount = 5;
    int res = mysolu.change(amount, coins);
    return 0;
}