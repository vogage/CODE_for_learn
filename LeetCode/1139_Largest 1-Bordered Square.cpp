#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        //find the '0' area
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> auxrowgrid(n,vector<int>(m,0));
        vector<vector<int>> auxcolgrid(n,vector<int>(m,0));
        // get the auxrow grid
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) cur++;
                else cur = 0;
                auxrowgrid[i][j] = cur;
            }
        }
        //get the auxcol grid
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) cur++;
                else cur = 0;
                auxcolgrid[i][j] = cur;
            }
        }
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (i + len >= n) break;
            for (int j = 0; j < m; j++) {
                if (j + len >= m) break;
                    if(grid[i][j]==0) continue;
                len = max(len, 1);
                for (int k = len ; k <= min(m, n); k++) {
                    if (validboardsquare(auxrowgrid, auxcolgrid, i, j, k)) len = max(len, k+1);
                }
            }
        }
        return len * len;
    }
private:
    bool validboardsquare(const vector<vector<int>>& auxrowgrid, const vector<vector<int>>& auxcolgrid, int i, int j, int& len) {
        //upboard
        if (i + len >= n || j + len >= m)return false;
        int up_board=auxrowgrid[i][j + len] - auxrowgrid[i][j];
        int down_board = auxrowgrid[i + len][j + len] - auxrowgrid[i + len][j];
        int left_board = auxcolgrid[i + len][j] - auxcolgrid[i][j];
        int right_board = auxcolgrid[i + len][j + len] - auxcolgrid[i][j + len];
       return up_board == len && down_board == len && left_board == len && right_board == len;
    }
private:
    int n;
    int m;
    
};

int main() {
    Solution mysolu;
    vector<vector<int>> grid = { {1,1,1},{1,0,1},{1,1,1} };
    vector<vector<int>> grid1 = { { 0,0,0,1 } };
    int res = mysolu.largest1BorderedSquare(grid1);
    return 0;
}