#include<stdio.h>
#include<vector>
#include<set>
#include<iostream>
#include<unordered_map>

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

class Solution3 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		unordered_map<long long, long long> m_bucket;
		for (int i = 0; i < nums.size(); i++) {
			long long map_num = (long long)nums[i] - INT_MIN;
			long long bucket = map_num / ((long long)t + 1);
			if (m_bucket.find(bucket) != m_bucket.end() ||
				(m_bucket.find(bucket - 1) != m_bucket.end() && map_num - m_bucket[bucket - 1] <= t) ||
				(m_bucket.find(bucket + 1) != m_bucket.end() && m_bucket[bucket + 1] - map_num <= t))
				return true;
			if (m_bucket.size() > k) {
				long long remove_bucket = ((long long)nums[i - k] - INT_MIN) / ((long long)t + 1);
				auto it = m_bucket.find(remove_bucket);
				if (it != m_bucket.end()) m_bucket.erase(it);
			}
			m_bucket.insert(pair<long long, long long>(bucket, map_num));
		}
		return false;
	}
};

int main() {
	Solution3 mysolu;
	vector<int> num = { 1,5,9,1,5,9 };
	vector<int> num2 = { 1,2,3,1 };
	vector<int> num3 = { 2147483647, -2147483647 };

	cout << "sizeof(int): " << sizeof(int) << endl;
	cout << "sizeof(long):  " << sizeof(long) << endl;

	//int k = 1;
	//int t = 2147483647;
	int k = 2;
	int t = 3;
	bool res=mysolu.containsNearbyAlmostDuplicate(num, k, t);
	return 0;
}