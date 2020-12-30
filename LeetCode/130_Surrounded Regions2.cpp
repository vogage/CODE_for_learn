#include<stdio.h>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
    int n = 0;
    int m = 0;
    vector < vector<int>> dirs= { {-1, 0}, { 1,0 }, { 0,-1 }, { 0,1 }};

    void solve(vector<vector<string>>& board) {
        int n = board.size();
        int m = board[0].size();
      
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                if(dfs(board,visited, i, j,m,n)) board[i][j]="X";
            }
        }
        return;
        
    }
    bool dfs(vector<vector<string>>& board, vector<vector<bool>>& visited,
        int i, int j,int m,int n) {
        if (bad_index(i,j,m,n))return false;
        visited[i][j] = true;
        if (board[i][j] == "X")return true;
        bool flag = true;
       
        for (auto dir : dirs) { 
            int x =i; int y = j;
            x = x + dir[0];
            y = y + dir[1];

            if (!bad_index(x, y, m, n)) {           
               
                if (!visited[x][y]) {
                    //if (x < i || y < j) { flag = flag && board[x][y] == "X"; continue; }
                    flag = flag && dfs(board, visited, x, y, m, n);
                }
            }
            else {
                return false;
            }
        }
        if (flag) { 
            return true;
        }
        else {
            return false;
        }
    }
    bool bad_index(int i, int j, int m, int n) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
};

int main() {
    Solution mysolu;
    vector<vector<char>> input = { { 'X', 'X', 'X' ,'X'},
        {'X','O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X' } };
    vector<vector<string>> input2 = { {"O", "X", "X", "O", "X"},
        {"X", "O", "O", "X", "O"},{"X", "O", "X", "O", "X"},
        {"O", "X", "O", "O", "O"},{"X", "X", "O", "X", "O"} };

    mysolu.solve(input2);
    return 0;
}
