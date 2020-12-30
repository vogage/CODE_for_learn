#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() < 0)return;
		bool flag = false;
		int m = board.size();
		int n = board[0].size();
		vector<vector<int>> board2 = board;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int die = 0;
				int live = 0;
				count_neighbors(board,i,j,die, live);
				//Any live cell with fewer than two live neighbors dies, as if caused by under - population.
			//Any live cell with two or three live neighbors lives on to the next generation.
			//Any live cell with more than three live neighbors dies, as if by over - population..
			//Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

	/*			[0, 1, 0],
					[0, 0, 1],
					[1, 1, 1],
					[0, 0, 0]*/
				if (live < 2) board2[i][j] = 0;
				if (live > 3) board2[i][j] = 0;
				if (live == 3) board2[i][j] = 1;
			}

			
		}
		board = board2;
	}

	void count_neighbors(vector<vector<int>>& board,int i,int j,int& die, int& live) {
		if (i - 1 >= 0) {
			if (j - 1 >= 0) {
				if (board[i - 1][j - 1]) {
					live++;
				}
				else {
					die++;
				}
			}
			if (board[i - 1][j]) {
				live++;
			}
			else {
				die++;
			}
			if (j + 1 < board[0].size()) {
				if (board[i - 1][j + 1]) {
					live++;
				}
				else {
					die++;
				}
			}
		}

		if (i + 1 < board.size()) {
			if (j - 1 >= 0) {
				if (board[i+ 1][j - 1]) {
					live++;
				}
				else {
					die++;
				}
			}
			if (board[i + 1][j]) {
				live++;
			}
			else {
				die++;
			}
			if (j + 1 < board[0].size()) {
				if (board[i + 1][j + 1]) {
					live++;
				}
				else {
					die++;
				}
			}
		}
		
		if (j - 1 >= 0) {
			if (board[i][j - 1]) {
				live++;
			}
			else {
				die++;
			}
		}

		if (j + 1 < board[0].size()) {
			if (board[i][j + 1]) {
				live++;
			}
			else {
				die++;
			}
		}
	}
};

class Solution2 {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (m == 0)return;
		int n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0;j< n; j++) {
				int count = 0;
				for (int k = max(i - 1, 0); k < min(i + 2, m); k++) {
					for (int s = max(j - 1, 0); s < min(j + 2, n); s++) {
						count += board[k][s] & 1;
					}
				}
				if (count == 3 || count - board[i][j] == 3) {
					board[i][j] |= 2;
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] =board[i][j]>> 1;
			}
		}
	}
};

int main() {
	Solution2 mysolu;
	vector<vector<int>> board;
	//[0, 1, 0],
	//	[0, 0, 1],
	//	[1, 1, 1],
	//	[0, 0, 0]
	vector<int> temp;
	temp = { 0,1,0 };
	board.push_back(temp);
	temp = { 0,0,1 };
	board.push_back(temp);
	temp = { 1,1,1 };
	board.push_back(temp);
	temp = { 0,0,0 };
	board.push_back(temp);

	mysolu.gameOfLife(board);
	return 0;

}