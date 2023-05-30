#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
//    You are given an m x n integer matrix grid, and three integers row, col, and color.
//        Each value in the grid represents the color of the grid square at that location.
//
//    Two squares belong to the same connected component 
//        if they have the same color and are next to each other in any of the 4 directions.
//
//    The border of a connected component is all the squares in the connected component 
//        that are either 4 - directionally adjacent to a square not in the component, 
//        or on the boundary of the grid(the first or last row or column).
//
//    You should color the border of the connected component that contains the square grid[row][col] with color.

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> res=grid;
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<int> grid_set;
 
         dfs(grid, grid_set,res,row, col, n,m,color);

        return res;
    }

private:
    int get_index(int i, int j, int n) {
        return i * n + j;
    }

    void dfs(vector<vector<int>>& grid, unordered_set<int>& grid_set, 
        vector<vector<int>> &res, int i, int j, int n, int m, int color) {

        grid_set.insert(get_index(i, j, m));
        int component_color = grid[i][j];
        // [[1, 2, 1, 2, 1, 2], 
        //  [2, 2, 2, 2, 1, 2], 
        //  [1, 2, 2, 2, 1, 2]]
        if (is_border(grid, i, j, n, m, component_color)) {
            res[i][j] = color; 
        }

        if (i - 1 >= 0 && grid_set.find(get_index(i - 1, j, m)) == grid_set.end()) {
            if( grid[i-1][j] ==component_color) dfs(grid, grid_set, res, i - 1, j, n, m, color);
        }
        if (i +1<n && grid_set.find(get_index(i + 1, j, m)) == grid_set.end()) {
            if (grid[i +1][ j] == component_color) dfs(grid, grid_set, res, i + 1, j, n, m, color);
        }
        if (j- 1 >= 0 && grid_set.find(get_index(i, j-1, m)) == grid_set.end()) {
            if (grid[i][ j - 1] == component_color) dfs(grid, grid_set, res, i, j-1, n, m, color);
        }
        if (j+1<m && grid_set.find(get_index(i, j+1, m)) == grid_set.end()) {
            if (grid[i][j+1] == component_color) dfs(grid, grid_set, res,i, j+1, n, m, color);
        }
    }

    bool is_border(vector<vector<int>>& grid, int i, int j, int n, int m, int component_color) {
        if (i - 1 < 0 || i + 1 == n)return true;
        if (j - 1 < 0 || j + 1 == m)return true;
        if (grid[i - 1][j] != component_color ||
            grid[i + 1][j] != component_color ||
            grid[i][j - 1] != component_color ||
            grid[i][j + 1] != component_color)return true;
        return false;
    }
};


int main() {
//Input: grid = [[1, 2, 2], [2, 3, 2]], row = 0, col = 1, color = 3
//Output : [[1, 3, 3], [2, 3, 3]]
    Solution mysolu;
    vector<vector<int>> grid = { {1, 2, 2} ,{2, 3, 2} };

    //    1
    //    3
    //    1
    vector<vector<int>> grid1 = { {1, 2, 1, 2, 1, 2},{2, 2, 2, 2, 1, 2},{1, 2, 2, 2, 1, 2} };
    vector<vector<int>> res = mysolu.colorBorder(grid1, 1, 3, 1);
   return 0;
}