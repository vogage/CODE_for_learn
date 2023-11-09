#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<string> board = { "abcde", "fghij", "klmno", "pqrst", "uvwxy", "z" };
        unordered_map<char, pair<int, int>> CharMap;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                CharMap[board[i][j]] = pair<int, int>(i, j);
            }
        }
        pair<int, int> pre(0, 0);
        string res = "";
        for (int i = 0; i < target.size(); i++) {
            pair<int, int> cur = CharMap[target[i]];
            int r = cur.first - pre.first;
            int c = cur.second - pre.second;
            
            if (r < 0) {
                while (r < 0) { res += "U"; r++; }
            }
            else {
                if (cur.first == board.size() - 1) r--;
                while (r > 0) { res += "D"; r--; }
            }
            if (c < 0) {
                while (c < 0) { res += "L"; c++; }
            }
            else {
                while (c > 0) { res += "R"; c--; }
            }
            if (cur.first == board.size() - 1) res += "D";
            res += "!";
            pre = cur;
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    
    string target = "leet";
    string res = mysolu.alphabetBoardPath(target);
	return 0;
}