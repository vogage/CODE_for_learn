#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>


using namespace std;


class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		//[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]
		vector<vector<int>> res;
		unordered_set<int> set_index;
		vector<int> index;
		for (auto v : buildings) {
			if (set_index.find(v[0]) == set_index.end()) {
				index.push_back(v[0]);
				set_index.insert(v[0]);
			}
			if (set_index.find(v[1]) == set_index.end()) {
				set_index.insert(v[1]);
				index.push_back(v[1]);
			}
		}
		sort(index.begin(), index.end());

		for (int i = 0; i < index.size(); i++) {

			int temp_high = 0;
			for (int j = 0; j < buildings.size(); j++) {
				if (index[i] < buildings[j][1] && index[i] >= buildings[j][0]) {

					temp_high = max(temp_high, buildings[j][2]);
				}
			}
			vector<int> temp;
			if (res.size()==0||temp_high != res.back().back()) {
				temp.push_back(index[i]);
				temp.push_back(temp_high);
				res.push_back(temp);
			}
		}
			return res;
	
	}

	





	
};

int main() {
	//[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]
	vector<vector<int>> input;
	vector<int> temp;
	temp = { 2,9,10 };
	input.push_back(temp);
	temp = { 3,7,15 };
	input.push_back(temp);
	temp = { 5,12,12 };
	input.push_back(temp);
	temp = { 15,20,10 };
	input.push_back(temp);
	temp = { 19,24,8 };
	input.push_back(temp);
	Solution mysolu;
	vector<vector<int>> res=mysolu.getSkyline(input);


	return 0;
}