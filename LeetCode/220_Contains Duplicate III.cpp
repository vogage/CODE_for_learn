#include<stdio.h>
#include<vector>
#include<set>

using namespace std;


class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

	}
};


class Solution2 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		set<int> window; // set is ordered automatically 
		//1,5,9,1,5,9
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) window.erase(nums[i - k - 1]); // keep the set contains nums i j at most k
			// |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
			auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
			// x - nums[i] <= t ==> |x - nums[i]| <= t    
			if (pos != window.end() && *pos - nums[i] <= t) return true;
			window.insert(nums[i]);
		}
		return false;
	}
};

int main() {
	Solution2 mysolu;
	vector<int> num = { 1,5,9,1,5,9 };
	int k = 2;
	int t = 3;
	bool res=mysolu.containsNearbyAlmostDuplicate(num, k, t);
	return 0;
}