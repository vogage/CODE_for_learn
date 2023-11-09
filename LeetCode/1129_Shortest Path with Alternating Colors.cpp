#include<vector>
#include<unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //just change the visited machinism
        unordered_set<int> visited;
        vector<int> res(n, -1);
        //the node blue edge in [0,n), the node red edge in [n,2n)
        unordered_map<int, vector<int>> redEdgeMap;
        unordered_map<int, vector<int>> blueEdgeMap;
        for (int i = 0; i < redEdges.size(); i++) {
            redEdgeMap[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for (int j = 0; j < blueEdges.size(); j++) {
            blueEdgeMap[blueEdges[j][0]].push_back(blueEdges[j][1]);
        }
        int level = 0;
        queue<int> que;
        que.push(0);
        que.push(n);
        while (!que.empty()) {
            int sz = que.size();
            for (int i = 0; i < sz; i++) {
                int temp = que.front();
                que.pop();
                if (temp >= n) {
                    if (res[temp - n] == -1)res[temp-n] = level;
                    for (int k : redEdgeMap[temp - n]) {
                        if (visited.find(k) == visited.end()) {
                            que.push(k);
                            visited.insert(k);
                        }
                    }
                }
                else {
                    if (res[temp] == -1)res[temp] = level;
                    for (int k : blueEdgeMap[temp]) {
                        if (visited.find(k + n) == visited.end()) {
                            que.push(k + n);
                            visited.insert(k + n);
                        }
                    }
                }
            }
            level++;
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    int n = 5;
    vector<vector<int>> redEdges = { {0, 1}, { 1,2 }, { 2,3 }, { 3,4 } };
    vector<vector<int>> blueEdges = { {1, 2}, { 2,3 }, { 3,1 } };
    vector<int> res = mysolu.shortestAlternatingPaths(n, redEdges, blueEdges);

	return 0;
}