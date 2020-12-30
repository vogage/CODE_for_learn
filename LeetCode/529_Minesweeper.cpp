#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0];
        int j = click[1];
        int n = board.size();
        int m = board[0].size();
        if (board[i][j] == 'M') {
            board[i][j] = 'X'; return board;
        }
        else {
            int count = 0;
            for (int r = -1; r <= 1; r++) {
                for (int c = -1; c <= 1; c++) {
                    int row = r + i;
                    int col = c + j;
                    if (r == 0 && c== 0) continue;
                    if (good_index(row, col, n, m)) { if (board[row][col] == 'M')count++; }
                }
            }
            if (count > 0) { board[i][j] = count + '0'; } 
            else{
                board[i][j] = 'B';
                for (int r = -1; r <= 1; r++) {
                    for (int c = -1; c <= 1; c++) {
                        int row = r + i;
                        int col = c + j;
                        if (r == 0 && c == 0)continue;
                        if (good_index(row,col,n,m)) {
                            if (board[row][col] == 'E') { 
                                vector<int> next_click = { row,col };
                                updateBoard(board, next_click);
                            }
                        }
                    }
                }
            }
        }
        return board;
      
    }
    
    

    bool good_index(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m)return false;
        return true;
    }
};

int main() {

    return 0;
}