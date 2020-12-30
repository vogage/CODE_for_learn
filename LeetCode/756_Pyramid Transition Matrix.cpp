#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_set>
#include<stack>

using namespace std;






class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<vector<int>>> v(7,vector<vector<int>>(7,vector<int>(7,0)));
       // int count = allowed.size();
        for (int i = 0; i < allowed.size(); i++) {
            v[allowed[i][0] - 'A'][allowed[i][1] - 'A'][allowed[i][2] - 'A']++;
           // v[allowed[i][1] - 'A'][allowed[i][0] - 'A'][allowed[i][2] - 'A']++;
        }
        return dfs(v, bottom);
    }
    bool dfs(vector<vector<vector<int>>>& v, string bottom) {
        if (bottom.size() == 1)return true;
        
   
        vector<string> temp;
        temp.push_back("");
        for (int i = 0; i < bottom.size() - 1; i++) {
            int m = bottom[i] - 'A';
            int n =  bottom[i + 1] - 'A';
            vector<string> temp2;
            for (int j = 0; j < 7; j++) {
                if (v[m][n][j] != 0) {
                   // roof+= (j + 'A');
                    for (string t : temp) {
                        //string str = t + (j + 'A');
                        temp2.push_back(t + string(1,j + 'A'));
                    }
                 
                 
                    
                }
            }
            if (temp2.size() == 0)return false;
            temp = temp2;

        }
      //  if (temp.back().size() != bottom.size() - 1) return false;
        for (auto t : temp) {
            if (dfs(v, t))return true;
        }
        return false;
    }
};

class Solution2 {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_set<string> invalid;
        // 7 characters from A to G, size 49 is sufficient.
        vector<vector<char>> edges(49);
        for (string& s : allowed) {
            int key = (s[0] - 'A') * 7 + s[1] - 'A';
            edges[key].push_back(s[2]);
        }
        return helper(invalid, bottom, edges);
    }
private:
    bool helper(unordered_set<string>& invalid, string& bottom, vector<vector<char>>& edges) {
        if (bottom.size() <= 1) return true;
        if (invalid.count(bottom)) return false;
        int n = bottom.size();
        // early termination if next level string is impossible
        for (int i = 0; i < n - 1; i++) {
            int key = (bottom[i] - 'A') * 7 + bottom[i + 1] - 'A';
            if (edges[key].empty()) {
                invalid.insert(bottom);
                return false;
            }
        }
        // try all possible strings (from backtracking) of next level
        string path(n - 1, 'A');
        if (dfs(invalid, bottom, edges, path, 0)) return true;
        invalid.insert(bottom);
        return false;
    }
    bool dfs(unordered_set<string>& invalid, string& s, vector<vector<char>>& edges, string& path, int idx) {
        // find a possible string of next level
        if (idx + 1 == s.size()) return helper(invalid, path, edges);
        int key = (s[idx] - 'A') * 7 + s[idx + 1] - 'A';
        for (char c : edges[key]) {
            path[idx] = c;
            if (dfs(invalid, s, edges, path, idx + 1)) return true;
        }
        return false;
    }
};

int main() {
    Solution mysolu;
    string bottom = "BCD";
    vector<string>allowed = { "BCG", "CDE", "GEA", "FFF" };
    string bottom2 = "DB";
        vector<string> allowed2 = { "BDD", "ACA", "CBA", "BDC", "AAC", "DCB", "ABC", "DDA", "CCB" };
        string bottom3 = "EAGAEFF"; //GFEEGF
        vector<string>allowed3 = { "BGG", "AGF", "AGD", "AGC", "AGB", "CCE", "CCD", "EGA", "CCA", 
            "DCD", "DCB", "DBD", "DBF", "FFF", "FFE", "FFA", "GBF", "GBD", "GBE", "FDE", "GBC", "BED",
            "AEE", "DEA", "EEA", "DEG", "CEG", "CED", "CEB", "CEA", "GCF", "GEB", "BDB", "AFD", "AFE",
            "AFA", "AFC", "ECD", "DDA", "DDF", "EFG", "CBF", "CBD", "ACG", "ACF", "BCA", "BCB", "EFB", 
            "ECG", "ECF", "ECE", "DGA", "DGG", "CGG", "GGE", "GGD", "FED", "FEA", "BBB", "ADD", "DFD",
            "DFF", "DFA", "CDE", "EDA", "CDA", "EDE", "FBA", "FBE", "AAE", "CAG", "CAF", "CAD", "DAE",
            "EAG", "GAE", "GAD", "GAB", "GAA", "ABD", "EBB", "CFF", "CFB", "CFC", "GFB", "GFA" };
    bool res = mysolu.pyramidTransition(bottom3, allowed3);
    return 0;
}