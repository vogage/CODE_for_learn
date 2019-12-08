#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0)return 0;
		queue<int> q;
		
		int temp = 0;
		int i = 0;
		for (; i < nums.size()&&temp<s; i++) {
			temp = temp + nums[i];
			q.push(nums[i]);
		}
		if (temp < s)return 0;
		int count = i;
		int res = count;
		while (temp - q.front() >= s) {
			count--;
			temp = temp - q.front();
			q.pop();
		}
		for (; i < nums.size(); i++) {
			
				temp = temp - q.front();
				q.pop();
				temp = temp + nums[i];
				q.push(nums[i]);
				while (temp - q.front() >= s) {
					count--;
					temp = temp - q.front();
					q.pop();
				}
				
		}
		return count;
	}
};

int main() {
	Solution mysolu;
	//s = 7, nums = [2,3,1,2,4,3]
	int s = 7;
	vector<int> nums = { 2,3,1,2,4,3 };
	int s1 = 4;
	vector<int>nums1 = { 1,4,4 };
	//int res = mysolu.minSubArrayLen(s, nums);
	vector<int> nums2 = { 1,2,3,4,5 };
	int s2 = 11;
	int res2 = mysolu.minSubArrayLen(s2, nums2);
	return 0;
}

