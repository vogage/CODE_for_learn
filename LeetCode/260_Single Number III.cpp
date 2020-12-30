#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int diff = 0;
		for (int i = 0; i < nums.size(); i++) {
			diff = diff ^ nums[i];
		}
		int last = (diff) & (diff - 1) ^ (diff);
		int A = 0;
		int B = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (last&nums[i]) A = A ^ nums[i];
			else B = B ^ nums[i];
		}
		vector<int> res;
		res.push_back(A);
		res.push_back(B);
		return res;
	}
};