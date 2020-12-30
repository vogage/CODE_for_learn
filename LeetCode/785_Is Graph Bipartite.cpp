#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {//TLE
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> part1;
        unordered_set<int> part2;
        for (int i = 0; i < graph.size(); i++) {
            if (part1.find(i) != part1.end()) {
                if (part2.find(i) != part2.end()) {
                    return false;
               }
                else {
                    for (int j : graph[i]) {
                        if (part1.find(j) != part1.end())return false;
                        part2.insert(j);
                    }
                }
            }
            else {
                if (part2.find(i) != part2.end()) {
                    for (int j : graph[i]) {
                        if (part2.find(j) != part2.end())return false;
                        part1.insert(j);
                    }
                }
                else {
                    unordered_set<int> dsf_part1_1 = part1;
                    unordered_set<int> dsf_part1_2 = part2;
                    unordered_set<int> dsf_part2_1 = part1;
                    unordered_set<int> dsf_part2_2 = part2;
                    dsf_part1_1.insert(i);
                    for (int j : graph[i]) {
                        if (dsf_part1_1.find(j) != dsf_part1_1.end()) return false;
                        dsf_part1_2.insert(j);

                    }
                    dsf_part2_2.insert(i);
                    for (int j : graph[i]) {
                        if (dsf_part2_2.find(j) != dsf_part2_2.end()) return false;
                        dsf_part2_1.insert(j);

                    }
                    return dfs(dsf_part1_1, dsf_part1_2, i + 1, graph) || dfs(dsf_part2_1, dsf_part2_2, i + 1, graph);
                }
            }
        }
        return true;
    }

    bool dfs(unordered_set<int>& part1, unordered_set<int>& part2, int index_i, vector<vector<int>>& graph) {
        for (int i = index_i; i < graph.size(); i++) {
            if (part1.find(i) != part1.end()) {
                if (part2.find(i) != part2.end()) {
                    return false;
                }
                else {
                    for (int j : graph[i]) {
                        if (part1.find(j) != part1.end())return false;
                        part2.insert(j);
                    }
                }
            }
            else {
                if (part2.find(i) != part2.end()) {
                    for (int j : graph[i]) {
                        if (part2.find(j) != part2.end())return false;
                        part1.insert(j);
                    }
                }
                else {
                    unordered_set<int> dsf_part1_1 = part1;
                    unordered_set<int> dsf_part1_2 = part2;
                    unordered_set<int> dsf_part2_1 = part1;
                    unordered_set<int> dsf_part2_2 = part2;
                    bool f1 = true;
                    bool f2 = true;
                    dsf_part1_1.insert(i);
                    for (int j : graph[i]) {
                        if (dsf_part1_1.find(j) != dsf_part1_1.end()) { f1 = false; break; }
                        dsf_part1_2.insert(j);

                    }
                    dsf_part2_2.insert(i);
                    for (int j : graph[i]) {
                        if (dsf_part2_2.find(j) != dsf_part2_2.end()) { f2 = false; break; }
                        dsf_part2_1.insert(j);

                    }
                    if (f1) { f1 = dfs(dsf_part1_1, dsf_part1_2, i + 1, graph); }
                    if (f2) { f2 = dfs(dsf_part2_1, dsf_part2_2, i + 1, graph); }
                    return f1 || f2;
                }
            }
        }
        return true;
    }
};

class Solution2 {//two color  // neighbor is differeent color    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);
        for (int i = 0; i < n; i++) {
            if (colors[i]== 0&&!dfs(graph,i,colors,1)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph, int i, vector<int>& colors, int color) {
        if (colors[i] != 0 )return colors[i]==color;
        colors[i] = color;
        for (auto j : graph[i]) {
            if (!dfs(graph, j, colors, -color)) return false;
        }
        return true;
    }
};


int main() {
    Solution2 mysolu;
    vector<vector<int>> graph = { {1, 3},{0, 2},{1, 3},{0, 2} };
    vector<vector<int>> graph2 = { {1,2,3} ,{0,2},{0,1,3},{0,2} };
    vector<vector<int>> graph3 = { {1},{0,3},{3},{1,2} };
    bool res = mysolu.isBipartite(graph3);
	return 0;
}