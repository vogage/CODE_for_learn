#include<stdio.h>
#include<string>
#include<vector>


using namespace std;

class Solution {
public:

		vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
			vector<string> res;
		/*	int m = board.size();
			int n = board[0].size();*/
		//	vector<vector<bool>> touched(m, vector<bool>(n, false));
			for (string i : words) {
				TRYDFS(board,i, res);
			}
			return res;
		}

		void TRYDFS(vector<vector<char>>&board, string str, vector<string>& res) {
			int m = board.size();
			int n = board[0].size();

			vector<vector<bool>>touched(m,vector<bool>(n,false));
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if (board[i][j]==str[0]&&DFS(board, touched, i, j, str, 0)) { res.push_back(str); return; }
				}
			}
			return;
		}
		bool DFS(vector<vector<char>>& board, vector<vector<bool>>& touched, int i, int j, string str, int index) {
			if (index == str.size())return true;
			if (!(i >= 0 && i < board.size()))return false;
			if (!(j >= 0 && j < board[0].size()))return false;
			if (touched[i][j])return false;
			if (board[i][j] == str[index]) {
				touched[i][j] = true;
				if (DFS(board, touched, i + 1, j, str, index + 1))return true;
				if (DFS(board, touched, i - 1, j, str, index + 1))return true;
				if (DFS(board, touched, i, j + 1, str, index + 1))return true;
				if (DFS(board, touched, i, j - 1, str, index + 1))return true;
				touched[i][j] = false;
			}
			return false;
		}
};


class Solution2 {
public:

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> res;
		/*	int m = board.size();
			int n = board[0].size();*/
			//	vector<vector<bool>> touched(m, vector<bool>(n, false));
		
			TRYDFS(board,words, res);
		
		return res;
	}

	void TRYDFS(vector<vector<char>>&board, vector<string>& words, vector<string>& res) {
		int m = board.size();
		int n = board[0].size();

		vector<vector<bool>>touched(m, vector<bool>(n, false));
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				vector<string>temp_words;
				for (auto str : words) {
					if (board[i][j] == str[0]){
						temp_words.push_back(str);
					}
				}
				if (temp_words.size()) DFSvec(board, touched, i, j, temp_words,0,res);
			}
		}
		return;
	}
	bool DFSvec(vector<vector<char>>& board, vector<vector<bool>>& touched, int i, int j, vector<string>& temp_words, int index,vector<string>& res) {
			vector<string> temp;	
			//vector<string> temp2;
	/*		if (!(i >= 0 && i < board.size()))return false;
			if (!(j >= 0 && j < board[0].size()))return false;*/
			if (temp_words.size() == 0)return false;
			for (auto str : temp_words){
				if (str.size() == index) {
					if (find(res.begin(), res.end(),str) == res.end()) {
						res.push_back(str);
					}
				}
				else {
					if ((i >= 0 && i < board.size()) && (j >= 0 && j < board[0].size())) {
						if (board[i][j] == str[index]) {
							temp.push_back(str);
						}
					}
				}
				
			}
		//	temp_words = temp2;
		//		
		//	
		//if (temp_words.size() == 0)return false;
		if (!(i >= 0 && i < board.size()))return false;
		if (!(j >= 0 && j < board[0].size()))return false;
		if (touched[i][j])return false;
		//for (auto str : temp_words) {
		//	if (board[i][j] == str[index]) {
		//		temp.push_back(str);
		//	}
		//}
			if (temp.size()) {
				touched[i][j] = true;
				if (DFSvec(board, touched, i + 1, j, temp, index + 1, res))return true;
				if (DFSvec(board, touched, i - 1, j, temp, index + 1, res))return true;
				if (DFSvec(board, touched, i, j + 1, temp, index + 1, res))return true;
				if (DFSvec(board, touched, i, j - 1, temp, index + 1, res))return true;
				touched[i][j] = false;
			}
		return false;
	}

	//bool DFS(vector<vector<char>>& board, vector<vector<bool>>& touched, int i, int j, string str, int index) {
	//	if (index == str.size())return true;
	//	if (!(i >= 0 && i < board.size()))return false;
	//	if (!(j >= 0 && j < board[0].size()))return false;
	//	if (touched[i][j])return false;
	//	if (board[i][j] == str[index]) {
	//		touched[i][j] = true;
	//		if (DFS(board, touched, i + 1, j, str, index + 1))return true;
	//		if (DFS(board, touched, i - 1, j, str, index + 1))return true;
	//		if (DFS(board, touched, i, j + 1, str, index + 1))return true;
	//		if (DFS(board, touched, i, j - 1, str, index + 1))return true;
	//		touched[i][j] = false;
	//	}
	//	return false;
	//}
};

int main() {
	vector<vector<char>> board;
	vector<char> input = { 'o','a','a','n' };
	board.push_back(input);
	input = { 'e','t','a','e' };
	board.push_back(input);
	input = { 'i','h','k','r' };
	board.push_back(input);
	input = { 'i','f','l','v' };
	board.push_back(input);
	vector<string> words = { "oath","pea","eat","rain" };

	vector<vector<char>> board1;
	input = { 'a','a' };
	board1.push_back(input);
	vector<string> words1 = { "aa" };

	//[["a", "a", "a", "a"], ["a", "a", "a", "a"], 
	//["a", "a", "a", "a"], ["a", "a", "a", "a"],
	//["b", "c", "d", "e"], ["f", "g", "h", "i"],
	//["j", "k", "l", "m"], ["n", "o", "p", "q"], 
	//["r", "s", "t", "u"], ["v", "w", "x", "y"], 
	//["z", "z", "z", "z"]]

	vector<vector<char>> board3;
	input = { 'a','a','a','a' };
	board3.push_back(input);
	input = { 'a','a','a','a' };
	board3.push_back(input);
	input = { 'a','a','a','a' };
	board3.push_back(input);
	input = { 'a','a','a','a' };
	board3.push_back(input);
	input = { 'b','d','c','e' };
	vector<string> words3 = { "aaaaaaaaaaaaaaaa","aaaaaaaaaaaaaaab",
		"aaaaaaaaaaaaaaac","aaaaaaaaaaaaaaad","aaaaaaaaaaaaaaae",
		"aaaaaaaaaaaaaaaf","aaaaaaaaaaaaaaag","aaaaaaaaaaaaaaah",
		"aaaaaaaaaaaaaaai","aaaaaaaaaaaaaaaj","aaaaaaaaaaaaaaak",
		"aaaaaaaaaaaaaaal" };

	Solution2 mysolu;
	vector<string> res = mysolu.findWords(board, words);
	return 0;
}