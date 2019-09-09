#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;




class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		if (nums.size() == 0) return vector<vector<int>>();
		//no need to sort nums to save time
		vector<vector<int>> res;
		dfs(nums, 0, res);
		return res;
	}
	void dfs(vector<int>& nums, int index, vector<vector<int>>& res)
		//注意这两种方式的不同
		// 没有&，则每次调用函数是重新生成，因此可以不需要swap再换回来
		//但该方式消耗内存空间
	{
		if (index == nums.size())
		{
			res.push_back(nums);
			cout << "nums  which is push back:   ";
			for (int j = 0; j < nums.size(); j++) {
				cout << j << "<  " << nums[j]<<"<" ;

			}
			cout << endl;
			return;
		}
		unordered_set<int> record;
		for (int i = index; i < nums.size(); i++)
		{
			if (record.find(nums[i]) != record.end())
				continue;
			record.insert(nums[i]);
			swap(nums[i], nums[index]);
			cout << "swap" << "   ( " << i << " )" <<"  (" <<index <<")"<< endl;
			cout << "before dfs" << endl;
			cout << "nums in dfs:" << endl;

				for (int j = 0; j < nums.size(); j++) {
					cout <<"j= "<< j << " :  " << nums[j]<<":" ;

				}
			cout << endl;

			dfs(nums, index + 1, res);
			swap(nums[i], nums[index]);
		}
	}
};

int main() {
	Solution mysolu;
	vector<int> input = { 1,1,2 };
	vector<vector<int>> res = mysolu.permuteUnique(input);
	return 0;

}