#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int findMin(vector<int>& nums) {
	//	if (nums.size() == 1)return nums[0];
	//	if (nums.size() == 2)return min(nums[0], nums[1]);
		int begin = 0;
		int end = nums.size() - 1;
		while (begin + 1 <= end && nums[begin] == nums[begin + 1]) begin++;

		while (end - 1 >= begin && nums[end] == nums[end - 1])end--;
		while (begin < end) {
			int mid = (begin + end) / 2;
			
			if (nums[mid] > nums[end]) {
				begin = mid + 1;
			}
			else {
				end = mid;
			}
			while (begin + 1 <=end&&nums[begin] == nums[begin + 1]) begin++;

			while (end - 1 >= begin&&nums[end] == nums[end - 1])end--;
		}
		return nums[begin];
	}
};

int main() {
	vector<int> input = { 3,3,1,3 };
	vector<int> input2 = { 1 };
	vector<int> input3 = { 1,3,3 };
	vector<int> input4 = { 3,1,1 };
	Solution mysolu;
	int res = mysolu.findMin(input4);
	return 0;
}


