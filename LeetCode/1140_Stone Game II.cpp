#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> presum(n+1, 0);
        for (int i = n - 1; i >= 0; i--) presum[i] = presum[i +1] + piles[i];
        vector<unordered_map<int, int>> memo(n,unordered_map<int,int>());
        return dfs(presum, 0, 1, memo);
    }
private:
    int dfs(vector<int> presum, int p, int M, vector<unordered_map<int, int>>& memo) {
        if (memo[p].find(M) != memo[p].end())return memo[p][M];
        if (p + 2 * M >= presum.size()-1) memo[p][M] = presum[p];
        else {
            for (int i = 0; i < 2 * M; i++) {
                int cur = presum[p] - presum[p + i + 1];
                memo[p][M] = max(memo[p][M], cur + presum[p+i+1] - dfs(presum, p + i + 1, max(M, i + 1), memo));
            }
        }
        return memo[p][M];
    }
};

int main() {
    Solution mysolu;
    vector<int> piles = { 1,2,3,4,5,100 };
    int res = mysolu.stoneGameII(piles);
    return 0;
}