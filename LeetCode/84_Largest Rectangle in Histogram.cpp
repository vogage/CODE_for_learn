#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
/*

//这个算法通过了  94 / 96 test cases passed.
//但还是算法复杂度过高
//
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res=0;
		int n = heights.size();
		for (int i = 1; i <= n; i++) {
			//从台阶数从1到n进行计算
			int temp = sub_largestRectangleArea(heights, i,n);
			res = max(temp, res);
		}
		return res;
	}


	int sub_largestRectangleArea(vector<int>& heights, int i,int n) {
		int res = 0;
		for (int j = 0; j <= n-i; j++) {
			int min_of_vector = get_sub_vector_min(heights,j,j+i);
			int temp = i * min_of_vector;
			res = max(res, temp);
		}
		return res;
	}

	int get_sub_vector_min(vector<int>&heights, int start, int end) {
		int temp = heights[start];
		for (int i = start + 1; i < end; i++) {
			temp = min(temp, heights[i]);
		}
		return temp;
	}
};
*/
/*
//这个方案可以说是多虑了，在你考虑更低的情况时，可以把相对高的给覆盖掉
//所以无需从最高的开始考虑，直接每个拿出来考虑即可
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.size() == 0)return 0;
		vector<pair<int, int>> heights2;
		//从小到大按索引依次保存
		save(heights, heights2);
		//从小到大计算最大的可能矩形
		int res=calculate(heights2);
		return res;
	}
	int calculate(vector<pair<int, int>>& heights2) {
		int start = 0; int end = heights2.size();
		int temp = heights2[start].first*(end - start);

		for (int i = 1; i < heights2.size(); i++) {
			int tall = heights2[i].first;
			int wide = find_the_wide(heights2, i);
			temp = max(temp, tall*wide);

		}
		temp = max(temp, heights2.back().first);
		return temp;
	}

	int find_the_wide(vector<pair<int, int>>& heights2, int i) {
		//截取vector部分片段
		
		//cout << i;
		vector<pair<int, int>>::const_iterator start = heights2.begin();
		vector<pair<int, int>>::const_iterator end = heights2.begin() + i;
		vector<pair<int, int>> heights2_left(start, end);

		int left = 0;
		int right = heights2.size()-1;

		while (heights2_left.back().first == heights2[i].first) heights2_left.pop_back();
		//从小于该高度的vector片段中找出left，和right的界限坐标
		for (int j = 0; j < heights2_left.size(); j++) {
			if (heights2_left[j].second < heights2[i].second) left = max(left, heights2_left[j].second);
			if (heights2_left[j].second > heights2[i].second) right = min(right, heights2_left[j].second);
		}
		int wide = right - left-1;
		if (right == i) wide++;
		return wide;
	}

	void save(vector<int>&heights, vector<pair<int, int>>& heights2) {
		for (int i = 0; i < heights.size(); i++) {
			pair<int, int> temp(heights[i], i);
			heights2.push_back(temp);
		}
		sort(heights2.begin(), heights2.end(), cmp);
	}

};
*/


class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		//每一个拿出来考虑
		int res = 0;
		for (int i = 0; i < heights.size(); i++) {
			res = max(res, find_the_i_th_max_rectangle_area(heights, i));
		}
		return res;
	}
	int find_the_i_th_max_rectangle_area(vector<int>&heights, int i) {
		int tall_of_i = heights[i];
		//找出左边界
		int left=i;
		
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] >= tall_of_i) left--;
			else break;
		}

		//找出右边界
		int right=i;
		for (int j = i+1; j < heights.size(); j++) {
			if (heights[j] >= tall_of_i) right++;
			else break;
		}

		int wide = right - left + 1;
		int res = wide * heights[i];
		return res;
	}
};
int main() {
	vector<int> input = {1,2,2 };
	Solution mysolu;
	int ans = mysolu.largestRectangleArea(input);
	return 0;
}