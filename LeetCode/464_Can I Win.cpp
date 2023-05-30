#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//In the "100 game" two players take turns adding, to a running total, any integer from 1 to 10. 
//The player who first causes the running total to reach or exceed 100 wins.
//
//What if we change the game so that players cannot re-use integers ?
//
//For example, two players might take turns drawing from a common pool of numbers from 1 to 15 
//without replacement until they reach a total >= 100.
//
//Given two integers maxChoosableInteger and desiredTotal, 
//return true if the first player to move can force a win, otherwise, return false.Assume both players play optimally.

//-----------------------------------------------------------------------------------------------------------------------------------------
//1 <= maxChoosableInteger <= 20
//0 <= desiredTotal <= 300
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= maxChoosableInteger)return true;
        int sum = (maxChoosableInteger + 1) * maxChoosableInteger / 2;
        if (sum < desiredTotal)return false;
        used = vector<int>(maxChoosableInteger, false);
        return dfs(desiredTotal);

    }
private:
    vector<int> used;
    unordered_map<int, bool> choose_map;
    bool dfs(int desiredTotal) {
        if (desiredTotal <= 0)return false;
        int k = format_used(used);
        if (choose_map.find(k) != choose_map.end())return choose_map[k];
        for (int i = 0; i < used.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                if (!dfs(desiredTotal - i - 1)) {
                    choose_map[k] = true;
                    used[i] = false;
                    return true;
                }               
                used[i] = false;
            }
           
        }
        choose_map[k] = false;
        return false;
    }

    int format_used(const vector<int>& used) {
        int k = 0;
        for (int i = 0; i < used.size(); i++) {
            if (used[i]) {
                k = k | 1;              
            }
            k <<= 1;
        }
        return k;
    }
};


int main() {
    int maxChoosableInteger =10, desiredTotal = 40;
    Solution mysolu;
    bool res = mysolu.canIWin(maxChoosableInteger, desiredTotal);

    return 0;
}