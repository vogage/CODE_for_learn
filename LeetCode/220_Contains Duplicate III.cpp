#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>

using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

	}
};


class Solution2 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<long long> window; // set is ordered automatically 
		//1,5,9,1,5,9

		//[1,2,3,1], k = 3, t = 0
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) window.erase((long long)nums[i - k - 1]); // keep the set contains nums i j at most k
			// |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
			auto pos = window.lower_bound((long long)nums[i] -(long long) t); // x-nums[i] >= -t ==> x >= nums[i]-t 
			// x - nums[i] <= t ==> |x - nums[i]| <= t    
	/*		if (pos != window.end()) {
				long long temp = *pos - (long long)nums[i];
				long long temp2 = (long long)nums[i];
				long long temp3 = (long long)*pos;
				long long temp4 = temp3 - temp2;
				cout << temp << endl;
			}*/
			if (pos != window.end() && *pos -(long long) nums[i] <= (long long) t) return true;
			window.insert((long long)nums[i]);
		}
		return false;
	}
};

int main() {
	Solution2 mysolu;
	vector<int> num = { 1,5,9,1,5,9 };
	vector<int> num2 = { 1,2,3,1 };
	vector<int> num3 = { 2147483647, -2147483647 };

	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(long):  " << sizeof(long) << endl;

	int k = 1;
	int t = 2147483647;
	bool res=mysolu.containsNearbyAlmostDuplicate(num3, k, t);
	return 0;
}