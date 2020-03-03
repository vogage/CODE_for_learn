#include<stdio.h>
#include<vector>
#include<string>



using namespace std;

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ans;
		if (nums.size() == 0)return ans;
		vector<pair<int, int>> res;
		pair<int, int> p;
		p.first = nums[0]; p.second = nums[0];
		res.push_back(p);
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == res.back().second + 1) {
				res.back().second++;
			}
			else {
				pair<int, int>temp;
				temp.first = nums[i];
				temp.second = nums[i];
				res.push_back(temp);
			}
		}
		
		for (auto pp : res) {
			if (pp.first == pp.second) {
				ans.push_back(to_string(pp.first));

			}
			else {
				string str = to_string(pp.first);
				str += "->";
				str += to_string(pp.second);
				ans.push_back(str);
			}
		}
		return ans;


	}
};


int main() {
	Solution mysolu;
	vector<int> input = { 0,1,2,4,5,7};
	vector<int> input1 = { 0,2,3,4,6,8,9 };
	vector<string> res = mysolu.summaryRanges(input1);
	return 0;
}