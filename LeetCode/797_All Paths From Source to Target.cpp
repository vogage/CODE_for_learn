#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;



class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
       
     
        vector<int> temp;
        int n = graph.size() - 1;
        vector<bool> visited(n+2,false);
        temp.push_back(0);
        dfs(graph, visited, 0, n, temp, res);
        return res;
    }

    void dfs(vector<vector<int>>& graph, vector<bool> visited, int i, int n, vector<int>& temp, vector<vector<int>>& res) {
        if (visited[i])return;
        if (i == n) {
            res.push_back(temp);
            return;
        }
        visited[i] = true;
        for (int j : graph[i]) {
            temp.push_back(j);
            dfs(graph, visited, j, n, temp, res);
            temp.pop_back();
        }
        return;
    }
};

int main() {
    Solution mysolu;
    vector<vector<int>> graph = { {1,2} ,{3},{3},{} };
    vector<vector<int>> res = mysolu.allPathsSourceTarget(graph);
    return 0;
}