#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N <= 0)return 0;
        int MOD = 1000000007;
        vector<vector<int>> count(m, vector<int>(n, 0));
        count[i][j] = 1;
        int result = 0;
        vector<vector<int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };
        for (int step = 0; step < N; step++) {
            vector<vector<int>> temp(m, vector<int>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (auto d : dirs) {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                            result = (result + count[r][c]) % MOD;
                        }
                        else {
                            temp[nr][nc] =( count[r][c] + temp[nr][nc])%MOD;
                        }
                    }
                }
            }
            count = temp;

        }
        return result;
    }
};

int main() {
    return 0;
}