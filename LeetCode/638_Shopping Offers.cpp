#include<stdio.h>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = INT_MAX;
        int n = special.size();
        dfs(price, special, 0, needs, 0, res);
        return res;

    }
    void dfs(vector<int>& prices, vector<vector<int>>& special, int k, vector<int>& needs, int temp, int& res) {
        int n = special.size();
        if (temp > res)return;
        if (k == n) {
            for (int i = 0; i < needs.size(); i++) {
                temp += needs[i] * prices[i];
            }
            res = min(temp, res);
        }
        for (int i = k; i < n; i++) {
         
            int k = max_specital(needs, special, i);
            if (k == 0) {
                vector<int> temp_needs = needs;
                int temp2 = temp;
                dfs(prices, special, k + 1, temp_needs, temp2, res);
            }
            else {
           
                for (int j=k; j >= \; j--) {
                      vector<int> temp_needs = needs;
                      int temp2 = temp;

                    // int temp_total = total;
                  // 
                    refresh_needs(temp_needs, special, temp2, i, j);
                    dfs(prices, special, k + 1, temp_needs, temp2, res);
                }
            }
        }
        return;
    }
    void refresh_needs(vector<int>& temp_needs, vector<vector<int>>& special, int& temp2, int i, int j) {
        for (int k = 0; k < temp_needs.size(); k++) {
            temp_needs[k] = temp_needs[k] - j * special[i][k];

        }
        temp2 = temp2 + j * special[i].back();
        return;
    }
    int max_specital(vector<int>& needs, vector<vector<int>>& special, int i) {
        if (special.size() == 0)return 0;
        //先假设没有多买
        int res = INT_MAX;
        for (int j = 0; j < needs.size(); j++) {
            if (special[i][j])res = min(res, needs[j] / special[i][j]);
        }
        return res;
    }
};

void operator+=(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

void operator-=(vector<int>& a, const vector<int>& b) {
    for (int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

bool operator<(const vector<int>& a, const int& n) {
    for (int i : a)
        if (i < n)
            return true;
    return false;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if (needs < 0)
            return INT_MAX;

        int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);

        for (auto& offer : special) {
            if (cost + offer.back() >= m) // pruning
                continue;
            needs -= offer;
            m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
            needs += offer;
        }

        return m;
    }
};






int main() {
    Solution mysolu;
    vector<int> prices = { 2, 5 };
    vector<vector<int>> speical = { {3, 0, 5},{1, 2, 10} };
        
    vector<int> needs = { 3, 2 };
    int res = mysolu.shoppingOffers(prices, speical, needs);
    return 0;
}