#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
	//You are given an m x n binary matrix grid, 
	//	where 0 represents a sea cell and 1 represents a land cell.

	//A move consists of walking from one land cell to 
	//	another adjacent(4 - directionally) land cell or 
	//	walking off the boundary of the grid.

	//Return the number of land cells in grid for 
	//	which we cannot walk off the boundary of the grid 
	//	in any number of moves


    int numEnclaves(vector<vector<int>>& grid) {
		n = grid.size();
		if (n == 0) return 0;
		m = grid[0].size();
		for (int i = 0; i < n; i++) {	
				dfs(grid, i, 0);
				dfs(grid, i, m - 1);
		}
		for (int j = 1; j < m - 1; j++) {
			dfs(grid, 0, j);
			dfs(grid, n - 1, j);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) res++;
			}
		}
		return res;
    }

private:
	void dfs(vector<vector<int>>& grid, int i, int j) {
		if (!can_move(grid, i, j))return;
		grid[i][j] = 2;
		dfs(grid, i - 1, j);
		dfs(grid, i + 1, j);
		dfs(grid, i , j-1);
		dfs(grid, i , j+1);
	}
	bool can_move(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || i >= n)return false;
		if (j < 0 || j >= m)return false;
		if (grid[i][j] == 1)return true;
		return false;
	}
private:
	int n;
	int m;
	unordered_set<int> searched_set;
	int get_index(int i, int j, int n) {
		return i * n + j;
	}
};


int main() {
	Solution mysolu;
	vector<vector<int>> grid = { {0,0,0,0} ,{1,0,1,0},{0,1,1,0},{0,0,0,0} };
	vector<vector<int>> grid1 = { {0,1,1,0} ,{0,0,1,0},{0,0,1,0},{0,0,0,0} };

	int res = mysolu.numEnclaves(grid1);
	return 0;
}