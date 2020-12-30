#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;

        int n = matrix.size();
        if (n == 0)return res;
        int m = matrix[0].size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        //pacific
        for (int i = 0; i < n; i++) {
            dfs(matrix, pacific, i, 0,n,m);
        }
        for (int j = 0; j < m; j++) {
            dfs(matrix, pacific, 0, j,n, m);
        }
        //atlantic
        for (int i = 0; i < n; i++) {
            dfs(matrix, atlantic, i, m-1, n, m);
        }
        for (int j = 0; j < m; j++) {
            dfs(matrix, atlantic, n-1,j, n, m);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    vector<int> temp = { i,j };
                    res.push_back(temp);
                }
            }
        }
        return res;

    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& pacific, int i, int j,int n,int m) {
       // if (i < 0 || i >= n || j < 0 || j >= m)return;
        if (pacific[i][j] == true) return;
        pacific[i][j] = true;
        int temp = matrix[i][j];
        if (good_index(i - 1, j, n, m) && temp <= matrix[i - 1][j]) dfs(matrix, pacific, i - 1, j, n, m);
        if (good_index(i + 1, j, n, m) && temp <= matrix[i + 1][j]) dfs(matrix, pacific, i + 1, j, n, m);
        if (good_index(i , j-1, n, m) && temp <= matrix[i ][j-1]) dfs(matrix, pacific, i , j-1, n, m);
        if (good_index(i , j+1, n, m) && temp <= matrix[i][j+1]) dfs(matrix, pacific, i, j+1, n, m);
    }

    bool good_index(int i, int j, int n, int m) {
        return !(i < 0 || i >= n || j < 0 || j >= m);
    }
};


int main() {

    vector<vector<int>> input = {
        {1 ,  2  , 2  , 3 ,5},
        {3 ,  2  , 3  ,4, 4},
        {2  , 4  ,5,   3, 1 },
        {6 ,  7,  1,  4 ,  5 },
         {5,1 ,  1   ,2 ,  4}
    };

    Solution mysolu;
    vector<vector<int>> ans = mysolu.pacificAtlantic(input);
	return 0;
}