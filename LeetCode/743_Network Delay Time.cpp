#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int res = 0;
        //construct map
        unordered_map<int, vector<pair<int, int>>> road;
        for (auto m : times) {
            pair<int, int> p(m[1], m[2]);
            road[m[0]].push_back(p);    

        }
      




        for (int i = 1; i <= N; i++) {
            if (i == K)continue;
            vector<vector<bool>> visited(N + 1,vector<bool>(N+1,false));
           
            int dis_Ki = INT_MAX;
            dfs(road, visited, K, i, 0, dis_Ki);
            res = max(res, dis_Ki);
        }
        return res == INT_MAX ? -1 : res;
    }

    void dfs(unordered_map<int, vector<pair<int, int>>>& road, vector<vector<bool>>& visited, int start,
        int finish, int temp, int& disKi) {
        
        if (start == finish) {
            disKi = min(temp, disKi); return;
        }
        //if (visited[start]) return; 
       // visited[start] = true;
        for (auto m : road[start]) {    
            if (visited[start][m.first])continue;
            visited[start][m.first] = true;
            dfs(road, visited, m.first, finish, temp + m.second, disKi);
            visited[start][m.first] = false;
        }
        return;
    }
};

typedef unordered_map<int, int> mp;
typedef pair<int, int> pii;
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_map<int,mp> nodes;
        //contruct the relation
        for (auto &t : times) {
            if (nodes.find(t[0]) == nodes.end()) {
                mp tp;
                tp[t[1]] = t[2];
                nodes[t[0]]=tp;
            }
            else {
                nodes[t[0]][t[1]] = t[2];
            }
              
         
        }
        pq.push(pii(0, K));
        vector<bool> visited(N+1,false);
        int res = 0;
        while (!pq.empty()) {
            pii temp = pq.top();
            pq.pop();
            if (visited[temp.second]) continue;
            visited[temp.second] = true;
            int curNode = temp.second;
            int curDist = temp.first;
            res = curDist;
            N--;
            if (nodes.find(curNode) != nodes.end()) {
                for (auto& m : nodes[curNode]) {
                    pq.push(pii(m.second + curDist, m.first));

                }
            }
           
            
        }
        return N == 0 ? res : -1;

    }
};



int main() {
    vector<vector<int>> times = { {2, 1, 1},{2, 3, 1},{3, 4, 1} };
    int N = 4;
    int K = 2;
    Solution2 mysolu;
    int res = mysolu.networkDelayTime(times, N, 2);
    return 0;
}
