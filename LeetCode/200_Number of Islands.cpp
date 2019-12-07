#include<stdio.h>
#include<vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int total = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (grid[i][j]=='1' ) {
					total++;
					change(i, j, grid);
				}
			}
		}
		return total;

	}

	void change(int i, int j, vector<vector<char>>& grid) {
		grid[i][j] = '0';
		if (i - 1 >= 0 && grid[i - 1][j] == '1') change(i - 1, j, grid);
		if (i + 1 < grid.size() && grid[i + 1][j] == '1')change(i + 1, j, grid);
		if (j - 1 >= 0 && grid[i][j - 1] == '1')change(i, j - 1, grid);
		if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')change(i, j + 1, grid);
		return;

	}
};

int main() {
	Solution mysolu;
	vector<vector<char>> grid;
	vector<char>input = { '1','1','1','1','0' };
	grid.push_back(input);
	input = { '1','1','0','1','0' };
	grid.push_back(input);
	input = { '1','1','0','0','0' };
	grid.push_back(input);
	input = { '0','0','0','0','0' };
	grid.push_back(input);
	int res = mysolu.numIslands(grid);
	return 0;
}