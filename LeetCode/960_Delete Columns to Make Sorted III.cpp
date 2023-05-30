#include<queue>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
	Node(vector<char> _strs_colum, int _num_delete) :strs_colum(_strs_colum), num_delete(_num_delete) {}
	vector<char> strs_colum;
	int num_delete;
};

class Solution {
public:
	int minDeletionSize(vector<string>& strs) {
		int n = strs.size();
		int m = strs[0].size();
		vector<int> dp(m, 1);
		int res = INT_MAX;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < i; j++) {
				for (int k = 0; k < n; k++) {
					if (strs[k][j] > strs[k][i]) break;
					if (k == n-1 && dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
					}
				}
			}
			res = min(res, m - dp[i]);
		}
		return res;
	}
};
class Solution3 {
public:
	int minDeletionSize(vector<string>& strs) {
		unordered_map<string,int> strs_map;
		int n = strs.size();
		int m = strs[0].size();
		string temp(n, 'a');
		strs_map[temp] = 0;
		for (int i = 0; i < m; i++) {
			unordered_map<string, int>next_map;

			for (auto p : strs_map) {
				string current_column = p.first;
				bool current_column_satisfy = true;
				for (int k = 0; k < n; k++) {
					if (current_column[k] > strs[k][i]) {
						current_column_satisfy = false; break;
					}
					current_column[k] = strs[k][i];
				}
				if (current_column_satisfy) {
					if (next_map.find(current_column) != next_map.end()) {
						next_map[current_column] = min(p.second, next_map[current_column]);
					}
					else {
						next_map[current_column] = p.second;
					}
				}
				if (next_map.find(p.first) != next_map.end()) {
					next_map[p.first] = min(next_map[p.first], p.second+1);
				}
				else {
					next_map[p.first] = p.second + 1;
				}
				
			}
			strs_map = next_map;
		}
		int res = INT_MAX;
		for (auto p : strs_map) {
			res = min(res, p.second);
		}
		return res;
	}
};


class Solution2 {
public:
	int minDeletionSize(vector<string>& strs) {
		queue<Node> iter_q;
	
		int len = strs[0].size();
		int n = strs.size();
		Node temp(vector<char>(n,'a'), 0);
		iter_q.push(temp);
		for (int i = 0; i < len; i++) {
			int m = iter_q.size();
			for (int j = 0; j < m; j++) {
				Node prev = iter_q.front();
				Node cur = prev;
				iter_q.pop();
				bool current_column_satisfy = true;
				for(int k=0;k<n;k++){
					if (cur.strs_colum[k] > strs[k][i]) {
						current_column_satisfy = false;
						break;
					}
					else if (cur.strs_colum[k] < strs[k][i]) {
						cur.strs_colum[k] = strs[k][i];
					}
				
				}
				//1.the prev satisfy the curent colum
				// just reserve
				//2.need renew 
				//reserve the current colum
				//renew the current biggest char in everystring
				//delete the current colum
				if (current_column_satisfy) {
					iter_q.push(cur);
				}
				prev.num_delete++;
				iter_q.push(prev);
			}
		}
		int res = INT_MAX;
		while (!iter_q.empty()) {
			res = min(res, iter_q.front().num_delete);
			iter_q.pop();
		}
		return res;
	}
};


int main() {
	Solution mysolu;
	vector<string> strs = { "babca", "bbazb" };
	vector<string> strs1 = { "aaababaabaababaaabbaaaabbabbbababbaaabbabbbbbabaaaaabbabbbbbaaababaaaaabaaabbbbbaaabbabababaabbaabab",
		"aaaaaaaaaaabbaaaabaaaaabaabaabbbaabaaaaaababbbbabaabababbaabababaaabbabaaaaaaaaabbbaabbabbaaaaaaaabb" };
	vector<string> strs2 = { "cbbdabc" };
	int res = mysolu.minDeletionSize(strs2);
	return 0;
}