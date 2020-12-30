#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<string>>& grid) {
		if (grid.size() == 0)return 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == "1" && visited[i][j] == false) {
					dfs(grid, visited, i, j, n, m);
					res++;
				}
			}
		}
		return res;
	}
		void dfs(vector<vector<string>> & grid, vector<vector<bool>>& visited,
			int i, int j, int n, int m) {
			if (i < 0 || i >= n || j < 0 || j >= m) return;
			if (visited[i][j])return;
			visited[i][j] = true;
			if (grid[i][j] == "0")return;
			
			dfs(grid, visited, i-1, j, n, m);
			dfs(grid, visited, i+1, j, n, m);
			dfs(grid, visited, i, j-1, n, m);
			dfs(grid, visited, i, j+1, n, m);
		}
	
};

int main() {
	Solution mysolu;
	vector<vector<string>> grid = {
		{"1", "1", "1", "1", "0"},
			{"1", "1", "0", "1", "0"},
			{"1", "1", "0", "0", "0"},
			{"0", "0", "0", "0", "0"}
	};
	int ans = mysolu.numIslands(grid);
	return 0;

}