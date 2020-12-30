#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
         vector<int> visited(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
          
            //if (find(ans.begin(), ans.end(), i) != ans.end()) continue;
            if (dfs(graph, visited, i)) ans.push_back(i);
        }
       // sort(ans.begin(), ans.end());
        return ans;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visied,int i) {
        if (visied[i]==1) return true;
        if (visied[i] == 2)return false;
        visied[i] = 2;
        for (int j : graph[i]) {
            if (!dfs(graph, visied, j))return false;
        }
        visied[i] = 1;
        return true;
    }
    
};

int main() {
    Solution mysolu;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<vector<int>> graph2 = { {},{0,2,3,4},{3},{4},{} };

    vector<int >res = mysolu.eventualSafeNodes(graph2);

    return 0;
}