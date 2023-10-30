#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class cmp {
public:
    bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second > p2.second;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_set<int> visited;
        visited.insert(0);
        if (grid[0][0] == 1)return -1;
        pq.push(pair<int, int>(0, 1));
        int n = grid.size();
        while (!pq.empty()) {
            pair<int, int> temp = pq.top();
            pq.pop();
            int x = temp.first / n;
            int y = temp.first % n;
            if (x == n - 1 && y == n - 1)return temp.second;
            for (int i = 0; i < adjdir.size(); i++) {
                int x1 = x + adjdir[i][0];
                int y1 = y + adjdir[i][1];
                if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || visited.find(x1 * n + y1) != visited.end() || grid[x1][y1] == 1) continue;
                visited.insert(x1 * n + y1);
                pq.push(pair<int, int>(x1 * n + y1, temp.second + 1));
            }
            for (int i = 0; i < diagdir.size(); i++) {
                int x1 = x + diagdir[i][0];
                int y1 = y + diagdir[i][1];
                if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n || visited.find(x1 * n + y1) != visited.end() || grid[x1][y1] == 1) continue;
                visited.insert(x1 * n + y1);
                pq.push(pair<int, int>(x1 * n + y1, temp.second + 1));
            }
        }
        return -1;
    }
private:
    vector<vector<int>> adjdir = { {0,1},{0,-1},{-1,0},{1,0} };
    vector<vector<int>> diagdir = { {1,1},{1,-1},{-1,1},{-1,-1} };
};


int main() {
    Solution mysolu;
    vector<vector<int>> grid = { {0, 0, 0},{1, 1, 0},{1, 1, 0} };
    vector<vector<int>> grid1 = { {0, 0, 0},{1, 0, 0},{1, 1, 0} };
    int res = mysolu.shortestPathBinaryMatrix(grid1);
    return 0;
   
}
