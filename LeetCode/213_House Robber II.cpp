#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		if (nums.size() == 1)return nums[0];
		return max(subrob(nums, 0, nums.size() - 2), subrob(nums, 1, nums.size() - 1));
	}

	int subrob(vector<int>& nums, int begin, int end) {
		int include = 0, exclude = 0;
		for (int i = begin; i <= end; i++) {
			int in = include, ex = exclude;
			include =ex + nums[i];
			exclude = max(ex,in);
		}
		return max(include, exclude);
	}
};

int main() {
	vector<int> input = { 2,3,2 };
	vector<int> input2 = { 1,2,3,1 };
	Solution mysolu;
	int res = mysolu.rob(input2);

	return 0;
}