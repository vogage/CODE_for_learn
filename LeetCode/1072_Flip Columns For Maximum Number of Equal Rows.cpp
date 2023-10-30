#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_map<string, int> FlipOrderMap;
        for (int i = 0; i < matrix.size(); i++) {
            int top = matrix[i][0];
            string temp = "";
            for (int j = 1; j < matrix[i].size(); j++) {
                if (top == matrix[i][j]) temp += "0";
                else temp += "1";
            }
            FlipOrderMap[temp]++;
        }
        int res = 0;
        for (auto m : FlipOrderMap) {
            res = max(res, m.second);
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<vector<int>> matrix = { {0, 0, 0},{0, 0, 1},{1, 1, 0} };
    int res = mysolu.maxEqualRowsAfterFlips(matrix);
    return 0;
}