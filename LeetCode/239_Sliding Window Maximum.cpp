#include<stdio.h>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0 || k == 0)return vector<int>();
		queue<int> q;
		int m = nums[0];
		vector<int> res;
		for (int i = 0; i < k; i++) {
			q.push(nums[i]);
			m = max(m, nums[i]);
		}
		res.push_back(m);
		for (int i = k; i < nums.size(); i++) {
			int fr = q.front();
			q.pop();
			if (fr == m) {
				m = nums[i];
				queue<int> temp;
				while (!q.empty()) {
					int t = q.front();
					q.pop();
					m = max(t, m);
					temp.push(t);
				}
				q = temp;
				q.push(nums[i]);
			}
			else {
				m = max(m, nums[i]);
				q.push(nums[i]);
			}
			res.push_back(m);
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 0 || nums.size() == 0) return vector<int>();
		vector<int> res;
		deque<int> deq;
		for (int i = 0; i < nums.size(); i++) {
			while (!deq.empty() && deq.front() < i - k + 1) {
				deq.pop_front();
			}
			while (!deq.empty() && nums[deq.back()] < nums[i]) {
				deq.pop_back();
			}
			deq.push_back(i);
			if (i >= k - 1) {
				res.push_back(nums[deq.front()]);
			}
		}
		return res;
	}
};
int main() {
	Solution2 mysolu;
	vector<int> input = { 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = mysolu.maxSlidingWindow(input, 3);
	return 0;
}