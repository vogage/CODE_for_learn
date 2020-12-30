#include<stdio.h>
#include<vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();       
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int total = m * n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) { visited[i][j] = true; total--; }
            }
        }
        update(matrix, visited,1, total);
        return matrix;
    }
    void update(vector<vector<int>>& matrix, vector<vector<bool>>&temp_visited,int temp, int& total) {
        if (total == 0)return;
        vector<vector<bool>> visited = temp_visited;
        vector<vector<int>> dirts = { {-1,0},{1,0},{0,-1},{0,1} };
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (visited[i][j]) continue;
                for (auto dirt : dirts) {
                    int row = i + dirt[0];
                    int col = j + dirt[1];
                    if (row>=0&&row<matrix.size()&&col>=0&&col<matrix[0].size()) {
                        if (visited[row][col]) {
                            temp_visited[i][j] = true;
                            matrix[i][j] = temp;
                            total--;
                            break;
                        }
                    }
                }
            }
        }
        update(matrix, temp_visited, temp + 1, total);
    }
};

int main() {
    Solution mysolu;
    vector<vector<int>> input = {
        {0,0,0},{0,1,0}, {1,1,1} };
    vector<vector<int>> res = mysolu.updateMatrix(input);
    return 0;
}