#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int Cat = 2, Mouse = 1, Draw = 0;
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(3, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));


        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for (int x : graph[c])if (x == 0) {
                    degree[m][c][2]--;
                    break;
                }
            }
        }

        queue<vector<int>> percolate_q;
        for (int i = 0; i < n; i++) {
            for (int t = 1; t <= 2; t++) {
                color[0][i][t] = Mouse;
                percolate_q.emplace(vector<int>{0, i, t, Mouse});
                if (i > 0) {
                    color[i][i][t] = Cat;
                    percolate_q.emplace(vector<int>{i, i, t, Cat});
                }
            }
        }

        while (!percolate_q.empty()) {
            vector<int> node = percolate_q.front();
            percolate_q.pop();
            int m = node[0];
            int c = node[1];
            int t = node[2];
            int result = node[3];
            for (vector<int> parent : parents(graph, m,c, t)) {
                int m2 = parent[0];
                int c2 = parent[1];
                int t2 = parent[2];
                if (color[m2][c2][t2] == Draw) {
                    if (t2 == result) {
                        color[m2][c2][t2] = result;
                        percolate_q.emplace(vector<int>{m2, c2, t2, result});
                    }
                    else {
                        degree[m2][c2][t2]--;
                        if (degree[m2][c2][t2] == 0) {
                            color[m2][c2][t2] = 3 - t2;
                            percolate_q.emplace(vector<int>{m2, c2, t2, 3 - t2});
                        }
                    }
                }
            }
        }
        return color[1][2][1];

    }

    vector<vector<int>> parents(vector<vector<int>> graph, int m, int c, int t) {
        vector<vector<int>> ans;
        if (t == 2) {
            for (int m2 : graph[m]) ans.push_back({ m2,c,1 });
        }
        else {
            for (int c2 : graph[c]) if(c2>0) ans.push_back({ m,c2,2 });
        }
        return ans;
    }
};


int main() {
    vector<vector<int>> graph = { {2, 5},{3},{0, 4, 5},{1, 4, 5},{2, 3},{0, 2, 3} };

    vector<vector<int>> graph1 = { {1,3},{0},{3},{0,2} };
    Solution mysolu;
    int res = mysolu.catMouseGame(graph);
	return 0;
}