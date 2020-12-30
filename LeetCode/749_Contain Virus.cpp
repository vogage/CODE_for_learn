#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>

using namespace std;


class region {
public:
    unordered_set<int> infected=unordered_set<int>();
    unordered_set<int> uninfected_neighbors=unordered_set<int>();
    int need_walls=0;
  // region() { infected = unordered_set<int>(), uninfected_neighbors = unordered_set<int>(), need_walls = 0; };
};

bool operator < (region& r1, region& r2) {
    return r1.uninfected_neighbors.size() < r2.uninfected_neighbors.size();
}

class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        //seed , the infected area
        int m = grid.size();
        if (m == 0)return 0;

        int n = grid[0].size();

        int res = 0;
        //vector<region> Regions;
       

        while (true) {
            vector<region>Regions;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        region rg;
                        dfs(i, j, grid,visited, rg);
                        Regions.push_back(rg);

                    }
                }
            }
            if (Regions.size() == 0) break;
            sort(Regions.begin(), Regions.end());
            region rg = Regions.back();
            Regions.pop_back();
            for (int pos : rg.infected) {
                int i = pos / n;
                int j = pos % n;
                grid[i][j] = 2;
            }
            for (auto &r : Regions) {
                for (int pos : r.uninfected_neighbors) {
                    int i = pos / n;
                    int j = pos %n;
                    grid[i][j] = 1;
                }
            }
            res += rg.need_walls;
        }
        return res;

    }
    void dfs(int i, int j, vector<vector<int>>& grid,vector<vector<bool>>& visited, region& R) {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2) {
            return;
        }
        if (grid[i][j] == 0) {
            R.uninfected_neighbors.insert(i * n + j);
            R.need_walls++;
            return;
        }
        if (grid[i][j] == 1) {
            R.infected.insert(i * n + j);
            if (visited[i][j])return;

        }
        visited[i][j] = true;
        dfs(i + 1, j, grid, visited, R);

        dfs(i - 1, j, grid, visited, R);
        dfs(i , j+1, grid, visited, R);
        dfs(i, j-1, grid, visited, R);

    }
    
};

int main() {
    Solution mysolu;
    vector<vector<int>> grid = { {0,1,0,0,0,0,0,1},
 {0,1,0,0,0,0,0,1},
 {0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0} };
    int res = mysolu.containVirus(grid);
    return 0;
}