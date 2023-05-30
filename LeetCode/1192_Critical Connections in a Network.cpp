#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //    How can "rank" help us with removing cycles ? 
    //    Imagine you have a current path of length k during a DFS.
    //    The nodes on the path has increasing ranks from 0 to k and incrementing by 1. 
    //    Surprisingly, your next visit finds a node that has a rank of p where 0 <= p < k.
    //    Why does it happen ? Aha!You found a node that is on the current search path!
    //    That means, congratulations, you found a cycle!

    //    But only the current level of search knows it finds a cycle.
    //    How does the upper level of search knows, 

    //    if you backtrack ? Let's make use of the return value of DFS: 
    //        dfs function returns the minimum rank it finds. 
    //        During a step of search from node u to its neighbor v, 

    //        if dfs(v) returns something smaller than or equal to rank(u), 
    //            then u knows its neighbor v helped it to find a cycle back to u or u's ancestor.
    //            So u knows it should discard the edge(u, v) which is in a cycle.

    //    After doing dfs on all nodes, all edges in cycles are discarded.
    //            So the remaining edges are critical connections.


    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> connect_map_out;
        unordered_map<int, vector<int>> connect_map_in;
        for (int i = 0; i < connections.size(); i++) {            
            connect_map_out[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> node(n + 1, -2);
        node[1] = 0;
        dfs(1, connect_map_out, node);
        vector<vector<int>> res;
       

    }

private:
    int dfs(int source, unordered_map<int, vector<int>>& connect_map_out, vector<int>& node) {
        int level = node[source];
        for (int i = 0; i < connect_map_out[source].size(); i++) {
            int target = dfs(connect_map_out[source][i], connect_map_out, node);
            if(target!=-2)
        }
};


int main() {
    vector<vector<int>> connections = { {0,1},{1,2},{2,0},{1,3} };
    Solution mysolu;
    vector<vector<int>> res = mysolu.criticalConnections(4, connections);
    return 0;
}