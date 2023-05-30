#include<stdio.h>
#include<unordered_map>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> relation_map;
        for (int i = 0; i < dislikes.size(); i++) { 
            relation_map[dislikes[i][0]].insert(dislikes[i][1]); 
            relation_map[dislikes[i][1]].insert(dislikes[i][0]);
        }
        unordered_set<int> p1;
        unordered_set<int> p2;
        return dfs(1, N, relation_map, p1, p2);
       
    }
    bool dfs(int i, int N, unordered_map<int, unordered_set<int>>& relation_map, 
        unordered_set<int>& p1, unordered_set<int>& p2) {
        if (i > N)return true;
        bool f1 = false;
        bool f2 = false;
        if (find_dislike(relation_map, p1, i)) {
            unordered_set<int>p1_1 = p1;
            unordered_set<int>p1_2 = p2;
            p1_1.insert(i);
            f1 = dfs(i + 1, N, relation_map, p1_1, p1_2);
        }
        if (find_dislike(relation_map, p2, i)) {
            unordered_set<int>p2_1 = p1;
            unordered_set<int>p2_2 = p2;
            p2_2.insert(i);
            f2 = dfs(i + 1, N, relation_map, p2_1, p2_2);
        }
        return f1 || f2;
    }
    bool find_dislike(unordered_map<int, unordered_set<int>>& relation_map, unordered_set<int>& p, int i) {
        for (int j : relation_map[i]) {
            if (p.find(j)!=p.end())return false;
        }
        return true;
    }
};
class Solution2 {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> relation_map;
        for (int i = 0; i < dislikes.size(); i++) {
            relation_map[dislikes[i][0]].insert(dislikes[i][1]);
            relation_map[dislikes[i][1]].insert(dislikes[i][0]);
        }
        unordered_set<int> p1;
        unordered_set<int> p2;
        for (auto m : relation_map) {
            dfs(m.first, relation_map, p1, p2);
        }
        for (auto i : p2) {
            if (p1.find(i) != p1.end())return false;
        }
        return true;
    }

    void dfs(int i, unordered_map<int, unordered_set<int>>& relation_map, 
        unordered_set<int>& p1, unordered_set<int>& p2) {
        if (p1.find(i) != p1.end() || p2.find(i) != p2.end()) return;
        p1.insert(i);
        for (auto j : relation_map[i]) {
            p2.insert(j);
            for (auto k : relation_map[j]) {
                dfs(k, relation_map, p1, p2);
            }
        }
        return;
    }
};


int main() {
    Solution2 mysolu;
    int N = 4;
    vector<vector<int>> dislikes = { {1, 2},{1, 3},{2, 4} };
    int N1 = 5;
    vector<vector<int>> dislikes1 = { {1, 2},{2, 3},{3, 4},{4, 5},{1, 5} };
    bool res = mysolu.possibleBipartition(N1, dislikes1);
    return 0;
}