#include<iostream>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', 
//'\', or blank space ' '. These characters divide the square into contiguous regions.
//
//Given the grid grid represented as a string array, return the number of regions.
//
//Note that backslash characters are escaped, so a '\' is represented as '\\'.

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        //构造一个map，用来搜索去过的地方
        unordered_map<int, vector<bool>> searched_map;
        int n = grid.size();
        if (n == 0)return 0;
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = get_index(i, j, n);
                if (searched_map.find(index) != searched_map.end()) {
                    if (searched_map[index][0]
                        && searched_map[index][1]
                        && searched_map[index][2]
                        && searched_map[index][3]) {
                        continue;
                    }
                    else {
                        res++;
                    }
                }
                else {
                    res++;
                }
                dfs(grid, searched_map, i, j, n, m);
            }
        }
        return res;
    }
    int get_index(int i, int j, int n) {
        return i*n+j;
    }
    void dfs(vector<string>& grid, unordered_map<int, vector<bool>>& searched_map,
        int i, int j, int n, int m) {
        int index = get_index(i, j, n);
        if (searched_map.find(index) != searched_map.end()) {
            if (searched_map[index][0]
                && searched_map[index][1]
                && searched_map[index][2]
                && searched_map[index][3]) {
                return;
            }
        }
        else {
            vector<bool> dir_map(4, false);
            searched_map[index] = dir_map;
        }

        if (i - 1 < 0) searched_map[index][2] = true;
        if (i >= n)searched_map[index][3] = true;
        if (j - 1 < 0) searched_map[index][0] = true;
        if (j >= m)searched_map[index][1] = true;

        // 0:   左
        // 1：右
        // 2：上
        // 3：下

        if (grid[i][j] == '\\'){
            
        }
        else if (grid[i][j] == '/') {

        }
        else if (grid[i][j] == ' ') {

        }
    }
};

class Solution2 {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        if (n == 0)return 0;
        int m = grid[0].size();
        vector<vector<bool>> grid_upscale(n * 3, vector<bool>(m * 3, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '\\') {
                    for (int k =0; k < 3; k++) {
                        grid_upscale[i * 3 + k][j * 3 + k] = true;
                    }
                }
                else if(grid[i][j]=='/') {
                    for (int k = 0; k < 3; k++) {
                        grid_upscale[i * 3 + k][(j + 1) * 3 - k - 1] = true;
                    }
                }
            }
        }
        int res = 0;
        int grid_n = grid_upscale.size();
        int grid_m = grid_upscale[0].size();
        for (int i = 0; i < grid_upscale.size(); i++) {
            for (int j = 0; j < grid_upscale[0].size(); j++) {
                if (grid_upscale[i][j] == true) continue;
                else {
                    res++;
                    dfs(grid_upscale, i, j,grid_n,grid_m);
                }
            }
        }
        return res;
    }


    void dfs(vector<vector<bool>>& grid_upscale, int i, int j,int grid_n,int grid_m) {
        if (i < 0 || i >= grid_n)return;
        if (j < 0 || j >= grid_m)return;
        if (grid_upscale[i][j])return;
        grid_upscale[i][j] = true;
        dfs(grid_upscale, i + 1, j, grid_n, grid_m);
        dfs(grid_upscale, i, j + 1, grid_n, grid_m);
        dfs(grid_upscale, i-1, j, grid_n, grid_m);
        dfs(grid_upscale, i, j-1, grid_n, grid_m);
    }
};

int main() {
    Solution2 mysolu;
    vector<string> input = { "/\\","\\/" };
    int res = mysolu.regionsBySlashes(input);
	return 0;
}
