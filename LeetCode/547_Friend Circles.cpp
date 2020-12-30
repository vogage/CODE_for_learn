#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() == 0) return 0;
        vector<unordered_set<int>> v_set(1,unordered_set<int>(0));
        v_set[0].insert(0);
        for (int i = 1; i < M.size(); i++) {
            bool flag = false;
            for (int j = i-1; j >= 0; j--) {
                if (M[i][j]) {
                    for (auto& s : v_set) {
                        if (s.find(j) != s.end()) {
                            s.insert(i); flag = true; 
                            break;
                        }
                    }
                 
                }
            }
            if (!flag) {
                unordered_set<int> temp;
                temp.insert(i);
                v_set.push_back(temp);
            }
        }
        return v_set.size();
    }
};

class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0)return 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int cout = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (!visited[i][j]&&M[i][j]){
                    dfs(M, visited, i, j,n);
                    cout++;
                }
            }
        }
        return cout;
    }
    void dfs(vector<vector<int>>& M, vector<vector<bool>>& visited, int i, int j,int n) {
        if (i < 0 || i >= n || j < 0 || j >= n)return;
        if (visited[i][j])return;
        visited[i][i] = true;
        visited[i][j] = true;
        visited[j][i] = true;
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            if (M[i][k]) {
                dfs(M, visited, k, i, n);
            }
        }
        return;
    }
};

int main() {
    Solution2 mysolu;
    vector<vector<int>> input = { {1,1,0} ,
 {1,1,0},
        {0,0,1} };
    vector<vector<int>> input2 = { {1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1} };

    int res = mysolu.findCircleNum(input2);
    return 0;
}