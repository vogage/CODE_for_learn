#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>


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

class Trnode {
public:
	
	unordered_map<char, Trnode*> children;
	bool isword = false;
	Trnode(bool b = false) {
		isword = false;
	}


};

class Trie {
public:
	Trnode* root;
	Trie() {
		root = new Trnode();
	}

	void add(string word) {
		Trnode* p = root;
		for (auto c : word) {
			if (p->children[c] == NULL) {
				p->children[c] = new Trnode();
			}
			p = p->children[c];
		}
		p->isword = true;
	}
};

class Solution3 {
public:

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		Trie *obj = new Trie();
		for (auto str : words) {
			obj->add(str);
		}
		vector<string> res;

		DFS(board, obj, res);
		return res;
	}
	void DFS(vector<vector<char>>& board, Trie* t, vector<string> &res) {
		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> touched(m, vector<bool>(n, false));
		for (auto p : t->root->children) {
			
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if (board[i][j] == p.first) { string temp = "";temp+= p.first; DFSvec(board, touched,i,j,p.second, temp, res); }
					
				}
			}
		}
	}
	void DFSvec(vector<vector<char>>& board, vector<vector<bool>>& touched,int i,int j,Trnode* root, string& temp,vector<string>& res) {
		if (root->isword) { res.push_back(temp); root->isword = false; }
		//if (!(i >= 0 && i < board.size()))return;
		//if (!(j >= 0 && j < board[0].size()))return;
		touched[i][j] = true;
		for (auto p : root->children) {
			if ( i + 1 < board.size()) {
				if ((!touched[i + 1][j]) && board[i + 1][j] == p.first) { 
					temp.push_back(p.first);
					DFSvec(board, touched, i + 1, j, p.second, temp, res);
					temp.pop_back();
				}

			}
			if (i - 1 >= 0 ) {
				if ((!touched[i - 1][j]) && board[i - 1][j] == p.first) {
					temp.push_back(p.first);
					DFSvec(board, touched, i - 1, j, p.second, temp, res);
					temp.pop_back();
				}

			}
			if (j + 1 < board[0].size()) {
				if ((!touched[i][j+1]) && board[i][j+1] == p.first) {
					temp.push_back(p.first);
					DFSvec(board, touched, i , j+1, p.second, temp, res);
					temp.pop_back();
				}

			}
			if (j - 1 >= 0) {
				if ((!touched[i][j-1]) && board[i][j-1] == p.first) {
					temp.push_back(p.first);
					DFSvec(board, touched, i, j-1 ,p.second, temp, res);
					temp.pop_back();
				}

			}
		}
		
		touched[i][j] = false;
		return;
	}
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

	vector<vector<char>> board4;
	input = { 's','e','e','n','e','w' };
	board4.push_back(input);
	input = { 't','m','r','i','v','a' };
	board4.push_back(input);
	input = { 'o','b','s','i','b','d' };
	board4.push_back(input);
	input = { 'w','m','y','s','e','n' };
	board4.push_back(input);
	input = { 'l','t','s','n','s','a' };
	board4.push_back(input);
	input = { 'i','e','z','l','g','n' };
	vector<string> words4 = { "bend", "benda", "besa", "besan" };

	//[["s", "e", "e", "n", "e", "w"], ["t", "m", "r", "i", "v", "a"], ["o", "b", "s", "i", "b", "d"], 
	//	["w", "m", "y", "s", "e", "n"], ["l", "t", "s", "n", "s", "a"], ["i", "e", "z", "l", "g", "n"]]
	
	Solution3 mysolu;
	vector<string> res = mysolu.findWords(board, words);
	return 0;
}