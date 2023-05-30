#include<stdio.h>
#include<unordered_set>

using namespace std;
//There is a 1 million by 1 million grid on an XY - plane, and the coordinates of each grid square are(x, y).
//
//We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square.
//There is also an array of blocked squares, 
//where each blocked[i] = [xi, yi] represents a blocked square with coordinates(xi, yi).
//
//Each move, we can walk one square north, east, south, 
//or west if the square is not in the array of blocked squares.We are also not allowed to walk outside of the grid.
//
//Return true if and only if it is possible to reach the target square from the source square
//through a sequence of valid moves.

//def isEscapePossible(self, blocked, source, target) :
//    blocked = set(map(tuple, blocked))
//
//    def dfs(x, y, target, seen) :
//    if not (0 <= x < 10 * *6 and 0 <= y < 10 * *6) or (x, y) in blocked or (x, y) in seen : return False
//        seen.add((x, y))
//        if len(seen) > 20000 or [x, y] == target: return True
//            return dfs(x + 1, y, target, seen) or \
//            dfs(x - 1, y, target, seen) or \
//            dfs(x, y + 1, target, seen) or \
//            dfs(x, y - 1, target, seen)
//            return dfs(source[0], source[1], target, set()) and dfs(target[0], target[1], source, set())



class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<int> blocked_set;
        for (int i = 0; i < blocked.size(); i++) {
            blocked_set.insert(get_index(blocked[i][0], blocked[i][1]));
        }
        return dfs(blocked_set, source[0], source[1], target[0], target[1]);
    }

    bool dfs(unordered_set<int>& blocked_set, int i, int j, int ti, int tj) {
        if (i < 0)return false;
        if (j < 0)return false;
        if (i == ti && j == tj)return true;
        int index = get_index(i, j);
        if (blocked_set.find(index) != blocked_set.end()) return false;
        blocked_set.insert(index);
        return dfs(blocked_set, i - 1, j, ti, tj) || dfs(blocked_set, i + 1, j, ti, tj) ||
            dfs(blocked_set, i, j - 1, ti, tj) || dfs(blocked_set, i, j + 1, ti, tj);
    }
private:
    int get_index(int i, int j) {
        return i * 1000000 + j;
    }
};

class Solution2 {
public:
    bool bfs(unordered_set<long long>& visited, vector<int>& s, vector<int>& t, int blocks) {
        vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        vector<pair<int, int>> q = { {s[0], s[1]} };
        while (!q.empty() && q.size() <= blocks) {
            vector<pair<int, int>> q1;
            for (auto p : q) {
                for (auto d : dirs) {
                    auto x = p.first + d[0], y = p.second + d[1];
                    if (x < 0 || x > 999999 || y < 0 || y > 999999) continue;
                    if (x == t[0] && y == t[1]) return true;
                    if (visited.insert(((long long)x << 32) + y).second) q1.push_back({ x, y });
                }
            }
            swap(q, q1);
        }
        return !q.empty();
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& s, vector<int>& t) {
        unordered_set<long long> vis_s, vis_t;
        //    0 <= blocked.length <= 200
        //    blocked[i].length == 2
        //    0 <= xi, yi < 106
        //    source.length == target.length == 2
        //    0 <= sx, sy, tx, ty < 106
        //    source != target
        //    It is guaranteed that source and target are not blocked.
        for (auto b : blocked) {
            if (abs(b[0] - s[0]) + abs(b[1] - s[1]) < 400) vis_s.insert(((long long)b[0] << 32) + b[1]);
            if (abs(b[0] - t[0]) + abs(b[1] - t[1]) < 400) vis_t.insert(((long long)b[0] << 32) + b[1]);
        }
        return bfs(vis_s, s, t, vis_s.size()) && bfs(vis_t, t, s, vis_t.size());
    }
};


int main() {
    vector<vector<int>> blocked = { {0,1},{1,0} };
    vector<int> source = { 0,0 };
    vector<int> target = { 0,2 };
    Solution mysolu;
    bool res = mysolu.isEscapePossible(blocked, source, target);
    return 0;
}