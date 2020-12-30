#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);
        unordered_map<int, unordered_set<int>> mrich;
        for (auto r : richer) {
            mrich[r[1]].insert(r[0]);
        }
        for (int i = 0; i < n; i++) {
        
            dfs(mrich, quiet, ans, i, i);
        }
        return ans;
    }
    void dfs(unordered_map<int, unordered_set<int>>& mrich, vector<int>& quiet, vector<int>& ans, int i,int j) {
        if (ans[j] != -1) { if (quiet[ans[i]] > quiet[ans[j]]) { ans[i] = ans[j]; }; return; }
        if(ans[i]==-1) ans[i] = j;
        for (auto s : mrich[j]) {
            if (quiet[s] < quiet[ans[i]]) {
                ans[i] = s;
            }
            dfs(mrich, quiet, ans, i, s);
        }

    }
};

int main() {
    Solution mysolu;
    vector<vector<int>> richer = { {1, 0},{2, 1},{3, 1},{3, 7},{4, 3},{5, 3},{6, 3} };
    vector<int> quiet = { 3, 2, 5, 4, 6, 1, 7, 0 };
    vector<vector<int>> richer1 = { {0,1},{1,2} };
    vector<int> quiet1 = { 0,1,2 };
    vector<int> ans = mysolu.loudAndRich(richer1, quiet1);
    return 0;
}