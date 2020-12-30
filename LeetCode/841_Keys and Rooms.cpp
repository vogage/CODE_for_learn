#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int n = rooms.size();
		vector<bool> visited(n, false);
		dfs(rooms, visited, 0, n);
		return n == 0;
    }
	void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int i, int& n) {
		if (n == 0)return;
		if (visited[i])return;
		n--;
		visited[i] = true;
		for (auto j : rooms[i]) {
			dfs(rooms, visited, j, n);
		}
	}
};

int main() {
	Solution mysolu;
	vector<vector<int>> rooms{ {1},{2},{3},{}};
	bool res = mysolu.canVisitAllRooms(rooms);
	return 0;
}