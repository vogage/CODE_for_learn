#include<stdio.h>
#include<vector>

using namespace std;


//Note: Please solve it without division and in O(n).

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res;
		vector<int> before(nums.size(),1);


		for (int i =1; i < nums.size(); i++) {
			before[i] = before[i - 1] * nums[i - 1];
		}
		vector<int> after(nums.size(),1);
		for (int i = nums.size() - 2; i >= 0; i--) {
			after[i] = after[i + 1] * nums[i + 1];
		}
		for (int i = 0; i < nums.size(); i++) {
			res.push_back(before[i] * after[i]);
		}
		return res;
	}
};


int main() {
	Solution mysolu;
	vector<int>input = {1, 2, 3, 4};
	vector<int> res = mysolu.productExceptSelf(input);


	return 0;
}