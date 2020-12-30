#include<stdio.h>
#include<vector>
#include<unordered_map>


using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<int, vector<int>> ring_map;
        int res = INT_MAX;
        int n = ring.size();
        for (int i = 0; i <n; i++) {
            ring_map[ring[i]].push_back(i);

        }
        dfs(ring_map,key,n, 0,0, 0, res);
      
        return res;
        
    }
    void dfs(unordered_map<int, vector<int>>& ring_map,string& key,int n, int index, int pre_index,int temp, int& res) {
        if (index == key.size()) {
            res = min(res, temp); return;
        }
        vector<int> selected = ring_map[key[index]];
        pair<int, int> p1(INT_MAX,0);
        pair<int, int> p2(INT_MAX, 0);
        for (int i = 0; i < selected.size(); i++) {
           //Ë³Ê±Õë
            int temp1= selected[i] == pre_index?0:(selected[i] < pre_index? selected[i] + n - pre_index : selected[i] - pre_index);
            if (p1.first > temp1) {
                p1.first = temp1;
                p1.second = selected[i];
            }
            //ÄæÊ±Õë
            int temp2 = selected[i] == pre_index?0:( selected[i] < pre_index ? pre_index - selected[i] : pre_index + n - selected[i]);
      
            if (p2.first > temp2) {
                p2.first = temp2;
                p2.second = selected[i];
            }
        }
        dfs(ring_map, key, n, index + 1, p1.second, temp + p1.first + 1, res);
        dfs(ring_map, key, n, index + 1, p2.second, temp + p2.first + 1, res);

    }
};

class Solution2 {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (ring[k] == key[i]) {
                        int diff = abs(k - j);
                        int step = min(diff, n - diff);
                        dp[i][j] = min(dp[i][j], step + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};

class Solution3 {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.length();
        int res =INT_MAX;
        unordered_map<char, vector<int>> ring_map;
        for (int i = 0; i < ring.size(); i++) {
            ring_map[ring[i]].push_back(i);
        }
        unordered_map<int, int> state;
        state[0] = 0;
        for (int i = 0; i < key.size(); i++) {
            unordered_map<int, int> new_state;
            for (auto target : ring_map[key[i]]) {
                new_state[target] = INT_MAX;
                for (auto p : state) {
                    new_state[target] = min(new_state[target], dist(p.first, target,n) + p.second);
                }
            }
            state = new_state;
        }
        for (auto p : state) {
            res = min(res, p.second);
        }
        return res + n;
    }
    int dist(int i, int j, int n) {
        return min(abs(i - j), n - abs(i - j));
    }
};

int main() {
    string ring = "godding";
    string key = "godding";
    Solution3 mysolu;
    int res = mysolu.findRotateSteps(ring,key);
    return 0;
}