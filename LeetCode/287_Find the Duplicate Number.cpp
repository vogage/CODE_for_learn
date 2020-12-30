#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:



	int findDuplicate(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			res = res ^ nums[i];
		}
		for (int i = 0; i < nums.size(); i++) {
			int temp = res;
			for (int j = 0; j < nums.size(); j++) {
				if (i != j) {
					temp = temp ^ nums[j];
				}
			}
			if (temp == nums[i])return temp;
		}
		return 0;
	}
};

class Solution2 {
public:
	int findDuplicate(vector<int>& nums)
	{
		if (nums.size() > 1)
		{
			int slow = nums[0];
			int fast = nums[nums[0]];
			while (slow != fast)
			{
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			return nums[slow];
		
			fast = 0;
			while (fast != slow)
			{
				fast = nums[fast];
				slow = nums[slow];
			}
			return slow;
		}
		return -1;
	}
};

int main() {
	Solution2 mysolu;
	vector<int> input = { 1,3,4,2,2 };
	vector<int>input2 = { 2,5,9,6,9,3,8,9,7,1 };

	int res = mysolu.findDuplicate(input2);
	return 0;
}