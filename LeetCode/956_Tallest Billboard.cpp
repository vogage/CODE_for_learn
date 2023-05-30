#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution4 {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int x : rods) {
            unordered_map<int, int> cur(dp);
            for (auto it : cur) {
                int d = it.first;
                dp[d + x] = max(dp[d + x], cur[d]);
                dp[abs(d - x)] = max(dp[abs(d - x)], cur[d] + min(d, x));
            }
        }
        return dp[0];
    }
};



class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        
        unordered_map<int, int> diff_sum_pair;   //to record the max sum pair of the same difference
        diff_sum_pair[0] = 0;
        
        for (int i = 0; i <rods.size(); i++) {
            unordered_map<int,int> temp_map (diff_sum_pair);
            for (auto m : temp_map) {
                int diff1 = abs(m.first - rods[i]);
                diff_sum_pair[diff1] = max(diff_sum_pair[diff1], m.second + rods[i]);
                int diff2 = m.first + rods[i];
                diff_sum_pair[diff2] = max(diff_sum_pair[diff2], m.second + rods[i]);
            }
        }

        return diff_sum_pair[0] / 2;
    }
   
};


//time limit exceeding
class Solution2 {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int half_sum = 0;
        for (int i : rods) half_sum += i;
        half_sum = half_sum / 2;
        unordered_map<int, vector<int>> sum_map;
        vector<int> mem(1 << n, 0);
        sort(rods.begin(), rods.end());
        int res = 0;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        mem[i] = rods[j]; break;
                    }
                    else {
                        mem[i] = rods[j] + mem[prev];
                        break;
                    }
                }
            }
           // if (mem[i] >half_sum)break;
            if (sum_map.find(mem[i]) != sum_map.end()) {
                for (int k = 0; k < sum_map[mem[i]].size(); k++) {
                    if ((i & sum_map[mem[i]][k]) == 0)res = max(res, mem[i]);
                }
            }
            sum_map[mem[i]].push_back(i);
        }
        return 0;
    }

private:
    void dfs(vector<int>& rods, int index, int mask,int left_sum, int right_sum, int& res) {
        
    }

    unordered_set<int> masks_set;
};


int main() {
    Solution mysolu;
    vector<int> rods = { 1,2,3,4,5,6 };
    vector<int> rods1 = { 1,2,4,8,16,32,64,128,256,512,50,50,50,150,150,150,100,100,100,123 };
    int res = mysolu.tallestBillboard(rods);

	return 0;
}