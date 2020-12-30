#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int>tails(nums.size(), 0);
		int size = 0;
		for (auto x:nums) {
			int i = 0;
			int j = size;
			while (i != j) {
				int m = (i + j) / 2;
				if (tails[m] < x) {
					i = m + 1;
				}
				else {
					j = m;
				}
			}
			tails[i] = x;
			if(i==size) size++;
			
		}
		return size;
	}
};

int main() {
	Solution mysolu;
	vector<int> nums = { 10,9,2,5,3,7,101,18 };
	                                      //  {-1,-7,3,-2,4,94,-83}
	int res = mysolu.lengthOfLIS(nums);
	return 0;
}