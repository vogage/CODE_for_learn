#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size();
		vector<vector<int>> res;
		map<int, int> m1;
		for (int i = 0; i < n; i++) {
			m1[nums[i]]++;
		}

		vector<int> nums_only;
		for (auto m : m1) {
			nums_only.push_back(m.first);
		}
		
		res = find_all_subset(m1, nums_only);
		return res;
	}

	vector<vector<int>> find_all_subset(map<int, int> &m1, vector<int> &nums_only) {
		int len = nums_only.size();
		//ÓÐÃ»ÓÐ???
		vector<vector<int>> res;
		vector<int> temp;
		res.push_back(temp);
		for (int i = 0; i < len; i++) {
			//only one
			int len2 = res.size();

			if (m1[nums_only[i] ]== 1) {
				
				for (int j = 0; j < len2; j++) {
					temp = res[j];
					temp.push_back(nums_only[i]);
					res.push_back(temp);
				}
			}
			else {
				//not only one
				for (int j = 0; j < len2; j++) {
					temp = res[j];
					for (int k = 0; k < m1[nums_only[i]]; k++) {
						temp.push_back(nums_only[i]);
						res.push_back(temp);
					}
				}
			}
		}
		return res;
	}
};


int main() {
	vector<int> input = { 1,2,2 };
	Solution mysolu;
	vector<vector<int>> ans = mysolu.subsetsWithDup(input);
	return 0;
}