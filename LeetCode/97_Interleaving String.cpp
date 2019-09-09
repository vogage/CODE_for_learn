#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		typedef pair<int, int> index;
		unordered_set<int> visited;
		queue<index> q;
		q.push(index(-1, -1));

		int cols = s2.size() + 1;
		while (!q.empty()) {
			index idx = q.front();
			q.pop();

			int i = idx.first + 1;
			int j = idx.second + 1;

			if (i == s1.size() && j == s2.size()) {
				return i + j == s3.size();
			}

			if (i + j < s3.size()) {
				char next = s3[i + j];
				if (i < s1.size() && s1[i] == next) {
					if (visited.insert((i + 1) * cols + j).second) {
						q.push(index(i, j - 1));
					}
				}
				if (j < s2.size() && s2[j] == next) {
					if (visited.insert(i * cols + j + 1).second) {
						q.push(index(i - 1, j));
					}
				}
			}
		}

		return false;
	}
};




class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size())return false;

		vector<vector<bool>> table;
		for (int i = 0; i < s1.size() + 1; i++) {
			vector<bool> temp;
			for (int j = 0; j < s2.size(); j++) {
				temp.push_back(false);
			}
			table.push_back(temp);
		}


		for (int i = 0; i < s1.size() + 1; i++) {
			for (int j = 0; j < s2.size() + 1; j++) {
				if (i == 0 && j == 0) table[i][j] = true;
				else if (j == 0) table[i][j] = table[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				else if (i == 0) table[i][j] = table[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				else table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

			}
		}
		return table[s1.size()][s2.size()];

	}

};


int main() {
	string s1 = "";
	string s2 = "";
	string s3 = "";
	Solution mysolu;
	bool res = mysolu.isInterleave(s1, s2, s3);
	return 0;
}