#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;



/*
class Solution {
public:
	int maximalRectangle(vector<vector<string>>& matrix) {
		int res = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				res = max(res, find_i_j_position_max_rectangle(matrix, i, j));
				cout << "res= " << res << endl;
			}
		}
		return res;
	}
	int find_i_j_position_max_rectangle(vector<vector<string>>& matrix, int i, int j) {
		cout << "i= " << i << "  " << "j= " << j << endl;
		//每一个位置点寻找右下矩阵
		if (matrix[i][j] == "0")return 0;
		else {
			//以右为尊
			int right = j + 1;
		
			for (int pos_j = right; pos_j < matrix[0].size(); pos_j++) {
				if (matrix[i][pos_j] == "1")right++;
				else break;
			}
		    //求下方长度
			int down = i + 1;
			for (int pos_i = down; pos_i < matrix.size(); pos_i++) {
				bool flag = true;
				for (int pos_j = j; pos_j < right ; pos_j++) {
					if (matrix[pos_i][pos_j] == "0") { flag = false; break; }
				}
				if (flag) down++;
				else break;
			}
			int right_first_max = (down - i)*(right - j);

			//以下为尊
			 down = i + 1;
			 for (int pos_i = down; pos_i < matrix.size(); pos_i++) {
				 if (matrix[pos_i][j] == "1") down++;
			 }
			//求右边长度
			 right = j + 1;
			 for (int pos_j = right; pos_j < matrix[0].size(); pos_j++) {
				 bool flag = true;
				 for (int pos_i = i; pos_i < down; pos_i++) {
					 if (matrix[pos_i][pos_j] == "0") { flag = false; break; }
				 }
				 if (flag)right++;
				 else break;
			 }
			 int down_first_max = (down - i)*(right - j);
			 return max(down_first_max,right_first_max);
		}
	}
};

*/


class Solution {
public:
	int maximalRectangle(vector<vector<string>> &matrix) {
		if (matrix.size() == 0)return 0;
		int res = 0,max_rec=0;
		int length = 1, wide = 1;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				
					// as root to search for a max size rectangle
				if (matrix[i][j] == "1") {
					max_rec = max(max_rec, 1);
					R_max_size_rectangle(matrix, i, i+1, j, j, max_rec,true);
					R_max_size_rectangle(matrix, i, i, j, j+1, max_rec, false);
				}
			}
		}
		return max_rec;
	}

	void R_max_size_rectangle(vector<vector<string>>& matrix, int i_start,int i_end, int j_start,int j_end,int &max_rec,bool length_or_width) {
		//if not meet the requirements, return
		if (!length_or_width) {
			if (j_end >= matrix[0].size())return;
			// can add a column??

			for (int i = i_start; i <= i_end; i++) {
				if (matrix[i][j_end] == "0") {
					return;
				}
			}

		}
	
		
		//cout << "i_start= " << i_start << "  j_start= " << j_start << "| length= " << i_end - i_start + 1 << " width= " << j_end - j_start + 1 << "  max_rec= " << max_rec << endl;
			//can add a row??
		
		if (length_or_width) {
			if (i_end >= matrix.size())return;
			for (int j = j_start; j <= j_end; j++) {
				if (matrix[i_end][j] == "0") {
					return;
				}
			}
		}
			max_rec = max(max_rec, (i_end - i_start + 1)*(j_end - j_start + 1));
			R_max_size_rectangle(matrix, i_start, i_end+1, j_start, j_end, max_rec,true);
			R_max_size_rectangle(matrix, i_start, i_end, j_start, j_end + 1, max_rec,false);
			//cout << "i_start= " << i_start << "  j_start= " << j_start << "| length= " << i_end - i_start + 1 << " width= " << j_end - j_start + 1 << "  max_rec= " << max_rec << endl;
		
		return;
	
		
	}
};
int main() {
	/*
	vector<vector<string>> input = {
		{"1","0","1","0","0"},
		{"1","0","1","1","1"},
		{"1","1","1","1","1"},
		{"1","0","0","1","0"}
	};
	*/
	/*
	vector<vector<string>> input = {
		{"1","0"},
	    {"1","0"}
	};
	*/
	/*
	vector<vector<string>> input = {
		{"1","1","0","1"},{"1","1","0","1"},{"1","1","1","1"}
	};
	*/
	
	vector<vector<string>> input={ 
		{"1","1","1","1","1","1","1","1"},
	{"1","1","1","1","1","1","1","0"},
	{"1","1","1","1","1","1","1","0"},
	{"1","1","1","1","1","0","0","0"},
	{"0","1","1","1","1","0","0","0"}
	};
	
	Solution mysolu;
	int ans = mysolu.maximalRectangle(input);
	return 0;
}