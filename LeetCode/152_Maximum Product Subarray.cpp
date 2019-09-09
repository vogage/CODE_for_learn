#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int neg = 0;
		int pos = 0;
		int res = INT_MIN;

		if (nums.size() == 0)return res;
		if (nums.size() == 1)return nums[0];
		for (int temp : nums) {
			if (temp < 0) {
				if (neg == 0) {
					if (pos == 0) {
						neg = temp;
					}
					else {
						neg = pos * temp;
					}
					pos = 0;
				}
				else {
					int neg_temp = neg;
					if (pos != 0) { neg = pos * temp; }
					else {
						neg = temp;
					}
					pos = neg_temp * temp;
				}
			}
			else if (temp > 0) {
				if (pos == 0) {
					pos = temp;
					neg *= temp;
				}
				else {
					pos *= temp;
					neg *= temp;
				}
			}
			else {
				neg = 0;
				pos = 0;
			}

			res = max(res, pos);
		}
		return res;
	}

};

class Solution2 {
public:
	int maxProduct(vector<int>& nums) {
		int pos;
		int neg;
		int res;
		bool flag_pos = false;
		bool flag_neg = false;
		for (int temp : nums) {
			if (temp < 0) {
				if (!flag_neg) {
					if (flag_pos)
					{
						neg = temp * pos;
						pos = 0;
					}
					else {
						neg = temp;
					}
					flag_neg = true;
				}
				else {
					int temp_neg = neg;
					neg = pos * temp;
					pos = temp_neg * temp;
				}
				
			}
			else if (temp > 0) {
				if (!flag_pos) {
					pos = temp;
					flag_pos = true;
				}
				else {
					neg = neg * temp;
					pos = pos * temp;
				}
			}
			else {
				neg = 0;
				pos = 0;
			}
			res = max(res, pos);
		}
		return res;
	}
	
};


int main() {
	Solution mysolu;
		vector<int> input = { 2,3,-2,4 };
		vector<int> input2 = { -2 };
		vector<int> input3 = { -2,3,-4 };
		vector<int> input4 = { 7,-2,-4 };
		vector<int> input5 = { -1,-2,-9,-6 };
		vector<int>input6 = { 2,-5,-2,-4,3 };
		int res = mysolu.maxProduct(input6);
		return res;
}