#include<stdio.h>
#include<vector>


using namespace std;

class NumMatrix {
	vector<vector<int>>sum;
public:
	NumMatrix(vector<vector<int>>& matrix) {
		sum = matrix;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				sum[i][j] = 0;
			}
		}
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				int left =j-1;
				int up = i-1;
				int bias = 0;
				if (left >= 0 && up >= 0)  bias = sum[up][left];
				if (up >= 0)  up = sum[up][j];
				else up = 0;
				if (left >= 0) left =sum[i][j - 1];
				else left = 0;
				sum[i][j] = up + left - bias + matrix[i][j];

				
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int up = 0;
		int left = 0;
		int bais = 0;
		if (row1 - 1 >= 0) up = sum[row1 - 1][col2];
		if (col1 - 1 >= 0) left = sum[row2][col1-1];
		if (row1 - 1 >= 0 && col1 - 1 >= 0) bais = sum[row1-1][col1-1];
		return sum[row2][col2] - left-up+bais;
	}
};


int main() {
	vector<vector<int>> input;
	vector<int> temp = { 3, 0, 1, 4, 2 };
	input.push_back(temp);
	temp = { 5, 6, 3, 2, 1 };
	input.push_back(temp);
	temp = { 1, 2, 0, 1, 5 };
	input.push_back(temp);
	temp = { 4, 1, 0, 1, 7 };
	input.push_back(temp);
	temp = { 1, 0, 3, 0, 5 };
	input.push_back(temp);
	vector<vector<int>> input2;
	temp = { 1 };
	input2.push_back(temp);
	temp = { -7 };
	input2.push_back(temp);
	/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
	NumMatrix* obj = new NumMatrix(input2);
	int param_1 = obj->sumRegion(0, 0, 0, 0);

	return 0;
}