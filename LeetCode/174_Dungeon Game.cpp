#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;





class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		//¶þÎ¬vector ³õÊ¼»¯        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
		vector<vector<pair<int, int>>> res(dungeon.size(),vector<pair<int,int>>(dungeon[0].size(),pair<int,int>(0,0)));
		
		res[0][0].first = dungeon[0][0];
		res[0][0].second = dungeon[0][0];
		for (int i = 1; i < dungeon.size(); i++) {
			res[i][0].first = res[i - 1][0].first + dungeon[i][0];
			res[i][0].second = min(res[i - 1][0].second, res[i][0].first);
		}
		for (int j = 1; j < dungeon[0].size(); j++) {
			res[0][j].first = res[0][j - 1].first + dungeon[0][j];
			res[0][j].second = min(res[0][j - 1].second, res[0][j].first);

		}
		if (dungeon.size() > 1 && dungeon[0].size() > 1) {
			for (int i = 1; i < dungeon.size(); i++) {
				for (int j = 1; j < dungeon[0].size(); j++) {
					if (res[i - 1][j].second > res[i][j - 1].second) {
						res[i][j].first = res[i - 1][j].first + dungeon[i][j];
						res[i][j].second = min(res[i - 1][j].second, res[i][j].first);

					}
					else {
						res[i][j].first = res[i][j - 1].first + dungeon[i][j];
						res[i][j].second = min(res[i][j - 1].second, res[i][j].first);
					}

				}

			}
		}
		return res[res.size() - 1][res[0].size() - 1].second > 0 ? 1 : 1 - res[res.size() - 1][res[0].size() - 1].second;
	}
};

class Solution2 {
	int ans = INT_MIN;
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		vector<vector<pair<int, int>>> res(dungeon.size(), vector<pair<int, int>>(dungeon[0].size(), pair<int, int>(0, 0)));
		res[0][0].first = dungeon[0][0];
		res[0][0].second = dungeon[0][0];
		//for (int i = 1; i < dungeon.size(); i++) {
		//	res[i][0].first = res[i - 1][0].first + dungeon[i][0];
		//	res[i][0].second = min(res[i - 1][0].second, res[i][0].first);
		//}
		//for (int j = 1; j < dungeon[0].size(); j++) {
		//	res[0][j].first = res[0][j - 1].first + dungeon[0][j];
		//	res[0][j].second = min(res[0][j - 1].second, res[0][j].first);

		//}
		ans = dungeon[0][0];
		if (dungeon.size() > 1) calculate_ij_dungeon(0, 1,0, res, dungeon);
		if (dungeon[0].size() > 1)calculate_ij_dungeon(1, 0, 1, res, dungeon);
		return ans>0?1:1-ans;
	}
	void calculate_ij_dungeon(int flag,int i,int  j, vector<vector<pair<int, int>>> res, vector<vector<int>> &dungeon) {
		if (!(i < dungeon.size() && j < dungeon[0].size()))return;
		//flag : 0 down, 1 right
		if (flag == 0) {
			res[i][j].first = res[i - 1][j].first + dungeon[i][j];
			res[i][j].second = min(res[i - 1][j].second, res[i][j].first);

		}
		else {
			res[i][j].first = res[i][j - 1].first + dungeon[i][j];
			res[i][j].second = min(res[i][j - 1].second, res[i][j].first);
		}	
		calculate_ij_dungeon(1, i, j + 1, res, dungeon);
		calculate_ij_dungeon(0, i + 1, j, res, dungeon);
	
		if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) ans = max(ans, res[i][j].second);
		return;
	}
};
class Solution3 {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		vector<vector<int>> res(dungeon.size() + 1, vector<int>(dungeon[0].size()+1, INT_MAX));
		int M = dungeon.size();
		int N = dungeon[0].size();
		res[M][N - 1] = 1;
		res[M - 1][N] = 1;
		for (int i = M - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				int need = min(res[i + 1][j], res[i][j + 1]) - dungeon[i][j];
				res[i][j] = need > 0 ? need : 1;
			}
		}
		return res[0][0];
	}
};

int main() {
	vector<vector<int>> dungeon;
	vector<int> input= { -2,-3,3 };
	dungeon.push_back(input);
	input = { -5,-10,1 };
	dungeon.push_back(input);
	input = { 10,30,-5 };
	dungeon.push_back(input);

	vector<vector<int>> dungeon1;
	input = { 2,1 };
	dungeon1.push_back(input);
	vector<vector<int>> dungeon2;
	input = { 2 };
	dungeon2.push_back(input);
	input = { 1 };
	dungeon2.push_back(input);

	vector<vector<int>>dungeon3;
	input = { 1,-2,3 };
	dungeon3.push_back(input);
	input = { 2,-2,-2 };
	dungeon3.push_back(input);

	vector<vector<int>>dungeon4;
	input = { 1,-3,3 };
	dungeon4.push_back(input);
	input = { 0,-2,0 };
	dungeon4.push_back(input);
	input = { -3,-3,-3 };
	dungeon4.push_back(input);


	vector<vector<int>>dungeon5;
	input = { 0,0 };
	dungeon5.push_back(input);
	Solution3 mysolu;
	int res = mysolu.calculateMinimumHP(dungeon5);
	return 0;
}