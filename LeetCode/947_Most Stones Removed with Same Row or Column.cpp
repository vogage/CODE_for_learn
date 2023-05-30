#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//On a 2D plane, we place n stones at some integer coordinate points.Each coordinate 
//point may have at most one stone.
//
//A stone can be removed if it shares either the same row or the same column as another 
//stone that has not been removed.
//
//Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone,
//return the largest possible number of stones that can be removed.

class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {
		unordered_map<int, vector<int>> row_map;
		unordered_map<int, vector<int>> col_map;

		for (int i = 0; i < stones.size(); i++) {
			row_map[stones[i][0]].push_back(stones[i][1]);
			col_map[stones[i][1]].push_back(stones[i][0]);

		}
		int count_islands = 0;
		unordered_set<int> stones_set;
		//众所周知，基于红黑树(RB - Tree)的set与map是可以使用std::pair的，
		//	而unoredered_set与unordered_map的内部实现是基于哈希表(HashTable)，
		//	并没有直接提供pair接口，其原因与哈希表的特性相关。
		for (int i = 0; i < stones.size(); i++) {
			
			pair<int, int> search_start_stone(stones[i][0], stones[i][1]);
			int index = get_index(search_start_stone);
			if (stones_set.find(index) == stones_set.end()) {
				count_islands++;
				dfs(row_map, col_map, stones_set, search_start_stone.first, search_start_stone.second);
			}

		}
		return stones.size() - count_islands;
	}
	int get_index(pair<int,int> p) {
		return p.first * 10000 + p.second;
	}

	void dfs(unordered_map<int, vector<int>>& row_map, unordered_map<int, vector<int>>& col_map,
		unordered_set<int>& stones_set,int row,int col){
		//dfs搜索树
		pair<int, int> search_start_stone(row, col);
		int index = get_index(search_start_stone);
		if (stones_set.find(index) != stones_set.end()) return;
		stones_set.insert(index);
		for (int i = 0; i < row_map[row].size(); i++) {
			dfs(row_map, col_map, stones_set, row, row_map[row][i]);
		}
		for (int j = 0; j < col_map[col].size(); j++) {
			dfs(row_map, col_map, stones_set, col_map[col][j], col);
		}
		return;
	}
};


int main() {
	Solution mysolu;
//Input: stones = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
//Output : 5
//Explanation : One way to remove 5 stones is as follows :
//1. Remove stone[2, 2] because it shares the same row as[2, 1].
//2. Remove stone[2, 1] because it shares the same column as[0, 1].
//3. Remove stone[1, 2] because it shares the same row as[1, 0].
//4. Remove stone[1, 0] because it shares the same column as[0, 0].
//5. Remove stone[0, 1] because it shares the same row as[0, 0].
//Stone[0, 0] cannot be removed since it does not share a row / column with another stone still on the plane.

	vector<vector<int>> stones = { {0, 0} ,{0, 1},{1, 0},{1, 2},{2, 1},{2, 2} };
	vector<vector<int>> stones2 = { {0,0},{0,2},{1,1},{2,0},{2,2} };
	int res = mysolu.removeStones(stones);

	return 0;
}