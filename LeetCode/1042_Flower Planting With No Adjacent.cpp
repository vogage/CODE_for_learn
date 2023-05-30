#include<stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
        //You have n gardens, labeled from 1 to n, 
        //    and an array paths where paths[i] = [xi, yi] 
        //    describes a bidirectional path between garden xi to garden yi.
        //    In each garden, you want to plant one of 4 types of flowers.

        //All gardens have at most 3 paths coming into or leaving it.

        //Your task is to choose a flower type for each garden such that,
        //    for any two gardens connected by a path,
        //        they have different types of flowers.

        //Return any such a choice as an array answer, 
        //where answer[i] is the type of flower planted in the(i + 1)th garden.
        //    The flower types are denoted 1, 2, 3, or 4. 
        //    It is guaranteed an answer exists.
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> garden_path;
   
        for (int i = 0; i < paths.size(); i++) {
            garden_path[paths[i][0]].push_back( paths[i][1]);
            garden_path[paths[i][1]].push_back( paths[i][0]);
        }

        vector<int> res(n+1, 0);
      

        for (int i = 1; i < res.size(); i++) {
            vector<bool> flower_types = { true,true,true,true,true };
            for (auto k : garden_path[i]) {
                flower_types[res[k]] = false;
            }
            for (int j = 1; j < flower_types.size(); j++) {
                if (flower_types[j]) {
                    res[i] = j; break;
                }
             }
       }

        vector<int> res2(res.begin()+1, res.begin()+n+1);
        return res2;
    }
    
};

class Solution2 {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {

        vector<int> res(N);
        vector<vector<int>> G(N);
        for (vector<int>& p : paths) {
            G[p[0] - 1].push_back(p[1] - 1);
            G[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < N; ++i) {
            int colors[5] = {};
            for (int j : G[i])
                colors[res[j]] = 1;
            for (int c = 4; c > 0; --c)
                if (!colors[c])
                    res[i] = c;
        }
        return res;
    }
};
int main() {
    int n = 3;
    vector<vector<int>> paths = { {1,2},{2,3},{3,1} };
    Solution mysolu;
    vector<int> res = mysolu.gardenNoAdj(n, paths);
    return 0;
}