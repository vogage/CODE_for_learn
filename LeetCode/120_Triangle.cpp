#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int> temp;
		int res = INT_MAX;
		DFS(triangle, 0, 0,0,res);
		return res;
	}
	void DFS(vector<vector<int>>& triangle,  int i, int j,int sum,int &res) {
		if (i >= triangle.size()) { res = min(res, sum); return; }
		DFS(triangle, i + 1, j, sum + triangle[i][j], res);
		DFS(triangle, i + 1, j + 1, sum + triangle[i][j], res);
	}
};

class Solution2 {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int res = INT_MAX;
		for (int i = 1; i < triangle.size(); i++) {
			triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
			for (int j =1; j < triangle[i].size()-1; j++) {
				triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j - 1], triangle[i - 1][j]);
			}
			triangle[i].back() = triangle[i].back() + triangle[i - 1].back();
		}
		for (int j = 0; j < triangle.back().size(); j++) {
			res = min(res, triangle.back()[j]);
		}
		return res;
	}

};

int main() {
	vector<vector<int>> input;
	input.push_back(vector<int>({ 2 }));
	input.push_back(vector<int>({ 3,4 }));
	input.push_back(vector<int>({ 6,5,7 }));
	input.push_back(vector<int>({ 4, 1, 8, 3 }));
	Solution2 mysolu;
	int res = mysolu.minimumTotal(input);
	return 0;
}