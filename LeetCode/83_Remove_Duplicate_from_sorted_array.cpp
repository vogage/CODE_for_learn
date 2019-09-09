#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int n = nums.size();
		if (n <= 2)return n;
		int len = 1;
		int temp = nums[0];
		int count = 1;
		int end = nums[n - 1];
		for (int i = 1; i < n;i++) {
			if (nums[i] < nums[i - 1]) {
				break;
			}
			if (nums[i] != temp) {
				
				temp = nums[i];
				count = 1;
				len++;

			}
			else {
				if (count < 2) {
					count++;
					len++;
				}
				else {
					if (nums[i] == end)break;
					swap_to_end(i, n, nums);
					//count = 0;
					i--;
				}
			}


		}

		return len;
	}
	void swap_to_end(int begin, int n, vector<int>&nums) {
		for (int i = begin; i +1< n; i++) {
			
				swap_two(i, i + 1, nums);
			}
		return;
	}
	void swap_two(int i, int j, vector<int>&nums) {
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
		return;
	}
};

int main() {
	Solution mycode;
	vector<int> nums = { 1,1,1};
	int len = mycode.removeDuplicates(nums);
	return 0;
}