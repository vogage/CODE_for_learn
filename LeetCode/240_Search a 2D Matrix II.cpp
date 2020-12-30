#include<stdio.h>
#include<vector>
#include<stack>
#include<unordered_set>

using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int bais = 0;
		for (; bais < m; bais++) {
			if (matrix[bais][bais*n / m] >= target) break;
		}

		int ti = bais-1;
		int tj = bais * n / m-1;
		for (int i = 0; i < n; i++) {
			if (matrix[m - 1][i] == target)return true;
		}
		for (int j = 0; j < m; j++) {
			if (matrix[j][n - 1] == target)return true;
		}
		if (matrix[m - 1][n - 1] == target)return true;
		for (int i = ti; i >= 0&&i<matrix.size(); i--) {
			if (matrix[i][tj] == target)return true;
		}
		for (int j = tj; j >= 0&&j<matrix[0].size(); j--) {
			if (matrix[ti][j] == target)return true;
		}
		return false;
	}
};



class Solution2 {
	int m = 0;
	int n = 0;
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)return false;
		m = matrix.size();
		n = matrix[0].size();
		return helpsearch(matrix, 0, 0, target);

	}
	bool helpsearch(vector<vector<int>>& matrix, int i, int j, int target) {
		if (i == m || j == n)return false;
		if (matrix[i][j] == target)return true;
		if (i + 1 < m&&j + 1 < n&&matrix[i + 1][j + 1] < target) return helpsearch(matrix, i + 1, j + 1, target);
		return helpsearch(matrix, i + 1, j, target) || helpsearch(matrix, i, j + 1, target);
	}
};

class Solution3 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)return false;
		
		int m = matrix.size();
		int n = matrix[0].size();
		int left = 0;
		while (left < n&&matrix[0][left] <= target) { 
			if (matrix[0][left] == target)return true;
			left++;
		}
		if (left == 0) return false;
		int down = 0;
		while (down < m&&matrix[down][left - 1] <= target) {
			if (matrix[down][left - 1] == target)return true;
			down++;
		}
		if (down == m)return false;
		int right = left-1;
		while (right >= 0 && matrix[down][right] >= target) {
			if (matrix[down][right] == target)return true;
			right--;
		}
		int down2 = down;
		if (right < 0)right = 0;
		while (down2 < m&&matrix[down2][right]<=target) {
			if (matrix[down2][right] == target) return true;
			down2++;
		}
		return false;
			
		

		

	
	   
	}

};
struct SimpleHash {
	size_t operator()(const std::pair<int, int>& p) const {
		return p.first ^ p.second;
	}
};

class Solution4 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		stack<pair<int, int>> st;
		pair<int, int> p = { 0, 0 };
		unordered_set<pair<int,int>,SimpleHash> pair_set;
		st.push(p);
		while (!st.empty()) {
			pair<int, int> temp = st.top();
			st.pop();
			if (matrix[temp.first][temp.second] == target) return true;
			pair<int, int> down(temp.first + 1, temp.second);
			pair<int, int> right(temp.first, temp.second + 1);
			

			if (down.first < m&&matrix[down.first][down.second] <= target && pair_set.find(down) == pair_set.end()) {
				st.push(down);
				pair_set.insert(down);
			}
			
			if (right.second < n&&matrix[right.first][right.second] <= target && pair_set.find(right) == pair_set.end()) {
				st.push(right);
		    	pair_set.insert(right);
			}
			
		}
		return false;
	}
};

class Solution5 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)return false;
		int m = matrix.size();
		int n= matrix[0].size();
		int row = 0;
		int col = n-1;
		while (true) {
			if (matrix[row][col] == target) return true;
			else if (matrix[row][col] < target) {
				row++;
				if (row == m)return false;

			}
			else {
				col--;
				if (col < 0)return false;
			}
		}
		return false;
	}
};






int main() {

	//[1, 4, 7, 11, 15],
	//	[2, 5, 8, 12, 19],
	//	[3, 6, 9, 16, 22],
	//	[10, 13, 14, 17, 24],
	//	[18, 21, 23, 26, 30]
	Solution5 mysolu;
	vector<vector<int>> input  ;
	vector<int> temp = { 1, 4, 7, 11, 15 };
	input.push_back(temp);
	temp = { 2, 5, 8, 12, 19 };
	input.push_back(temp);
	temp = { 3, 6, 9, 16, 22 };
	input.push_back(temp);
	temp = { 10, 13, 14, 17, 24 };
	input.push_back(temp);
	temp = { 18, 21, 23, 26, 30 };
	input.push_back(temp);
	vector<vector<int>> input2;

	vector<vector<int>> input3;
	vector<int> temp2 = { -5 };
	input3.push_back(temp2);

	vector<vector<int>> input4;
	vector<int> temp4 = { -1,3 };
	input4.push_back(temp4);

	vector<vector<int>>input5;
	vector<int> temp5 = { 1,3,5,7 };
	input5.push_back(temp5);
	temp5 = { 2,4,6,8 };
	input5.push_back(temp5);

	vector<vector<int>> input6;
	vector<int> temp6 = { 1,3,5,7,9 };
	input6.push_back(temp6);
	temp6 = { 2,4,6,8,10 };
	input6.push_back(temp6);
	temp6 = { 11,13,15,17,19 };
	input6.push_back(temp6);

	vector<vector<int>> input7;
	vector<int> temp7 = { 1,1 };
	input7.push_back(temp7);

	//[[3, 3, 8, 13, 13, 18], 
	//	[4, 5, 11, 13, 18, 20],
	//	[9, 9, 14, 15, 23, 23],
	//	[13, 18, 22, 22, 25, 27],
	//	[18, 22, 23, 28, 30, 33], 
	//	[21, 25, 28, 30, 35, 35],
	//	[24, 25, 33, 36, 37, 40]]
	//21

	vector<vector<int>> input8;
	vector<int> temp8 = { 3, 3, 8, 13, 13, 18 };
	input8.push_back(temp8);
	temp8 = { 4, 5, 11, 13, 18, 20 };	input8.push_back(temp8);
	temp8 = { 9, 9, 14, 15, 23, 23 };	input8.push_back(temp8);
	temp8 = { 13, 18, 22, 22, 25, 27 };	input8.push_back(temp8);
	temp8 = { 18, 22, 23, 28, 30, 33 };	input8.push_back(temp8);
	temp8 = { 21, 25, 28, 30, 35, 35 };	input8.push_back(temp8);
	temp8 = { 24, 25, 33, 36, 37, 40 };	input8.push_back(temp8);



	bool res = mysolu.searchMatrix(input8, 21);

	return 0;
}