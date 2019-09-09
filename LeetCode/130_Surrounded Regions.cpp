#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
template<>struct hash<pair<int, int>> {
	inline size_t operator()(const pair<int, int> &v) const {
		hash<int> int_hasher;
		return int_hasher(v.first) ^ int_hasher(v.second);
	}
};
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)return;
		//unordered_set<pair<int, int>> m;
		for (int i = 0; i < board.size(); i++) {
			if (board[i][0] == 'O') change_neibour(board, i, 0);
			if (board[i][board[0].size() - 1]=='O') change_neibour(board, i, board[0].size()-1);
		}
		for (int j = 0; j < board[0].size(); j++) {
			if (board[0][j] == 'O') change_neibour(board, 0, j);
			if (board[board.size() - 1][j]=='O') change_neibour(board, board.size()-1, j);
		}
		//change 'B' and 'O'
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'B')board[i][j] = 'O';
				else if (board[i][j] == 'O')board[i][j] = 'X';
			}
		}
	}
	void change_neibour(vector<vector<char>>& board, int i, int j) {
		queue<pair<int, int>> q;
		q.push(pair<int, int>(i, j));
		board[i][j] = 'B';
		while (!q.empty()) {
			pair<int, int> temp = q.front();
			q.pop();
			
			
			pair<int, int> left = pair<int, int>(temp.first, temp.second - 1);
			pair<int, int>right = pair<int, int>(temp.first, temp.second + 1);
			pair<int, int> up = pair<int, int>(temp.first - 1, temp.second);
			pair<int, int> down = pair<int, int>(temp.first + 1, temp.second);
			if (left.second >= 0) { 
				if (board[left.first][left.second] =='O') {
				
					q.push(left);
					board[left.first][left.second] = 'B';
				}
			}
			if (right.second < board[0].size()) {
				if (board[right.first][right.second] == 'O') {
				
					q.push(right);
					board[right.first][right.second] = 'B';
				}
			}
			if (up.first >= 0) {
				if (board[up.first][up.second] == 'O') {
				
					q.push(up);
					board[up.first][up.second] = 'B';
				}
			}
			if (down.first < board.size()) {
				if (board[down.first][down.second] == 'O') {
					
					q.push(down);
					board[down.first][down.second] = 'B';
				}
			}
		}
	}
};
	
int main() {
	
	vector<char> c1 = { 'x','x', 'x', 'x' };
	vector<char> c2 = { 'x','o', 'o', 'x', };
	vector<char> c3 = { 'x','x', 'o', 'x', };
	vector<char> c4 = { 'x','o', 'x', 'x', };
	//vector<char> c1 = { 'o','o','o' };
	//vector<char> c2 = { 'o','o','o' };
	//vector<char> c3 = { 'o','o','o' };
	vector<vector<char>> input;
	//[["X", "O", "X", "X"], ["O", "X", "O", "X"], ["X", "O", "X", "O"], ["O", "X", "O", "X"], ["X", "O", "X", "O"], ["O", "X", "O", "X"]]

	vector<vector<char>> input2;
	vector<char> i1 = { 'x','o','x','x' };
	vector<char>i2 = { 'o','x','o','x' };
	vector<char> i3 = { 'x','o','x','o' };
	vector<char> i4 = { 'o','x','o','x' };
	vector<char> i5 = { 'x','o','x','o' };
	vector<char> i6 = { 'o','x','o','x' };
	input.push_back(c1);
	input.push_back(c2);
	input.push_back(c3);
	input.push_back(c4);

	input2.push_back(i1);
	input2.push_back(i2);
	input2.push_back(i3);
	input2.push_back(i4);
	input2.push_back(i5);
	input2.push_back(i6);



	vector<vector<char>> input3;
	vector<char> p1 = { 'o','x','x','o','x' };
	vector<char> p2 = { 'x','o','o','x','o' };
	vector<char> p3 = { 'x','o','x','o','x' };
	vector<char> p4 = { 'o','x','o','o','o' };
	vector<char> p5 = { 'x','x','o','x','o' };

	input3.push_back(p1);
	input3.push_back(p2);
	input3.push_back(p3);
	input3.push_back(p4);
	input3.push_back(p5);

	for (int i = 0; i < input3.size(); i++) {
		for (int j = 0; j < input3[0].size(); j++) {
			input3[i][j] += 'A' - 'a';
		}
	}
	
	Solution mysolu;
	mysolu.solve(input3);
	return 0;
}