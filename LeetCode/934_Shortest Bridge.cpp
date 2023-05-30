#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
	int shortestBridge(vector<vector<int>>& grid) {
		unordered_set<int> grid_set1;
		int res = INT_MAX;
		int n = grid.size();
		if (n == 0)return 0;
		int m = grid[0].size();
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j]==1) {
					dfs_get_island_1(grid, grid_set1, i, j,n,m);
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		unordered_set<int> grid_set2=grid_set1;
		bfs(grid, grid_set1, grid_set2,n, m, 0, res);

		return res;
	}
	void dfs_get_island_1(vector<vector<int>>&grid, unordered_set<int>& grid_set, int i, int j,int n,int m) {
		if (i < 0 || i >= n) return;
		if (j < 0 || j >= m)return;
		int index = get_index(i, j, n);
		if (grid[i][j] == 1) {
			if (grid_set.find(index) != grid_set.end())return;
			grid_set.insert(index);
			dfs_get_island_1(grid, grid_set, i+1, j, n, m);
			dfs_get_island_1(grid, grid_set, i, j+1, n, m);
			dfs_get_island_1(grid, grid_set, i-1, j, n, m);
			dfs_get_island_1(grid, grid_set, i, j-1, n, m);
		}
		return;
	}
	void bfs(vector<vector<int>>& grid, unordered_set<int>& grid_set1, unordered_set<int> grid_set2, int n,int m, int temp, int& res) {
		pair<int, int> p;
		unordered_set<int> grid_set3;
		for (auto index : grid_set2) {
			 p = extract_index(index,n);
		
			vector<vector<int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
			for (int k = 0; k < dir.size(); k++) {
				int i = p.first + dir[k][0];
				int j = p.second + dir[k][1];

				if (isnew_grid(grid_set1, i, j, n, m)) {
					if (grid[i][j] == 1) {
						res = min(res, temp);
						return;
					}
					int grid_new_index = get_index(i, j, n);
					grid_set3.insert(grid_new_index);
					grid_set1.insert(grid_new_index);
				}
			}
		}
		
		bfs(grid, grid_set1, grid_set3, n, m, temp+1, res);
	}
	bool isnew_grid(unordered_set<int>& grid_set,int i,int j, int n, int m) {
		if (i < 0 || i >= n) return false;
		if (j < 0 || j >= m)return false;
		if (grid_set.find(get_index(i, j, n)) != grid_set.end()) return false;
		return true;
	}

	int get_index(int i, int j,int n) {
		return i * n + j;
	}
	pair<int, int> extract_index(int index,int n) {
		pair<int,int> p;
		p.first = index / n;
		p.second = index % n;
		return p;
	}

};


class Solution2 {
	struct Cell {
		size_t x;
		size_t y;

		Cell(size_t first, size_t second) : x(first), y(second) {}
	};

public:
	int shortestBridge(vector<vector<int>>& grid) {
		dist.resize(grid.size(), vector<int>(grid.size(), max_int));

		dfsFirstIslandAndFillBfsQueue(grid);

		int shortest_bridge = max_int;

		while (!bfs_queue.empty()) {
			Cell curr = bfs_queue.front();
			bfs_queue.pop();

			for (int i = 0; i != 4; ++i) {
				Cell next(curr.x + dx[i], curr.y + dy[i]);

				if (!isValidCell(grid, next)) {
					continue;
				}

				const bool is_cell_in_second_island =
					(grid[next.x][next.y] == 1 && dist[next.x][next.y] == max_int);
				const int curr_parent_dist = dist[curr.x][curr.y] + 1;

				if (is_cell_in_second_island) {
					shortest_bridge = min(shortest_bridge, curr_parent_dist - 1);
				}
				else if (curr_parent_dist < dist[next.x][next.y]) {
					dist[next.x][next.y] = curr_parent_dist;

					bfs_queue.push(Cell(next.x, next.y));
				}
			}
		}

		return shortest_bridge;
	}

private:
	// Finds the first "1" cell and traverses the connected component of it in
	// a DFS fashion to mark all cells in the first matrix. This also builds a
	// queue of the visited cells for processing them in later steps.
	void dfsFirstIslandAndFillBfsQueue(vector<vector<int>>& grid) {
		for (int i = 0; i != grid.size(); ++i) {
			for (int j = 0; j != grid.size(); ++j) {
				if (dist[i][j] == max_int && grid[i][j] == 1) {
					dfs(grid, Cell(i, j));
					return;
				}
			}
		}
	}

	void dfs(vector<vector<int>>& grid, Cell c) {
		dist[c.x][c.y] = 0;
		bfs_queue.push(c);

		for (int k = 0; k != 4; ++k) {
			Cell n(dx[k] + c.x, dy[k] + c.y);

			if (isValidCell(grid, n) && grid[n.x][n.y] == 1 &&
				dist[n.x][n.y] == max_int) {
				dfs(grid, n);
			}
		}
	}

	static bool isValidCell(vector<vector<int>>& grid, Cell c) {
		return c.x >= 0 && c.y >= 0 && c.x < grid.size() && c.y < grid[0].size();
	}

private:
	// Keeps track of shortest distances from a given node to any of the nodes
	// from the first found island. It also serves as a "visited" structure during
	// the DFS, i.e. when we encounter 1 from the first island we mark the
	// distance as -1.
	vector<vector<int>> dist;
	queue<Cell> bfs_queue;

	static constexpr int dx[4] = { 0, 1, 0, -1 };
	static constexpr int dy[4] = { 1, 0, -1, 0 };
	static constexpr int max_int = numeric_limits<int>::max();
};

int main() {
	Solution2 mysolu;

	vector<vector<int>> grid_input;
	//[[1, 1, 1, 1, 1], [1, 0, 0, 0, 1], [1, 0, 1, 0, 1], [1, 0, 0, 0, 1], [1, 1, 1, 1, 1]]
	vector<int> grid_row1 = { 1, 1, 1, 1, 1 };
	vector<int> grid_row2 = { 1, 0, 0, 0, 1 };
	vector<int> grid_row3 = { 1, 0, 1, 0, 1 };
	vector<int> grid_row4 = { 1, 0, 0, 0, 1 };
	vector<int> grid_row5 = { 1, 1, 1, 1, 1 };
	grid_input.push_back(grid_row1);
	grid_input.push_back(grid_row2);
	grid_input.push_back(grid_row3);
	grid_input.push_back(grid_row4);
	grid_input.push_back(grid_row5);

	vector<vector<int>> grid_input1 = { {0,1},{1,0} };
	int res = mysolu.shortestBridge(grid_input);
	return 0;
}