#include<stdio.h>
#include<vector>

using namespace std;


class Solution {
public:
	int findMin(vector<int>& nums) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin < end) {
			int mid = (begin + end) / 2;
			if (nums[mid] > nums[end]) {
				begin = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return nums[begin];
	}
};

int main() {
	vector<int> input = { 3,4,5,1,2 };
	Solution mysolu;
	int res = mysolu.findMin(input);
	return 0;
}