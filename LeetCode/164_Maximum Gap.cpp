#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;


class Solution1 {
	struct ListNode {
		int val;
		ListNode* left;
		ListNode*right;
		ListNode(int x) :val(x), right(NULL), left(NULL) {}
	};
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)return 0;
		ListNode *p = new ListNode(nums[0]);
		ListNode *dummy = new ListNode(0);
	
		int gap=0;

		for (int i = 2; i < nums.size(); i++) {
			ListNode *add = new ListNode(nums[i]);
			if (add->val < p->val) {
				while (p->left&&add->val < p->left->val) p = p->left;
				if(p->left)dummy->right = p->left;
				add->right = p;
				add->left = dummy->right;

				if(dummy->right)dummy->right->right = add;
				p->left = add;
				int gap_right = add->right->val - add->val;
				gap = max(gap, gap_right);
				if (add->left) {
					int gap_left = abs(add->val - add->left->val);
					gap = max(gap_left, gap);
				}

				
			}
			else if(add->val>p->val){
				while (p->right&&p->right->val < add->val)p = p->right;
				if(p->right)dummy->right = p->right;
				add->left = p;
				add->right = dummy->right;
				p->right = add;
				if(dummy->right)dummy->right->left = add;
				int gap_right = add->val - add->left->val;
				gap = max(gap_right, gap);
				if (add->right) {
					int gap_left = add->right->val - add->val;
					gap = max(gap, gap_left);
				}
			}

		}
		return gap;
		
	}
};
class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)return 0;
		int nums_min = INT_MAX;
		int nums_max = INT_MIN;
		for (auto i : nums) {
			nums_min = min(nums_min, i);
			nums_max = max(nums_max, i);
		}
		if (nums_min == nums_max)return 0;
		int n_bucket = (nums_max - nums_min) / nums.size();
		vector<vector<int>>bucket(nums.size(), vector<int>());
		for (auto i : nums) {
			if (i == nums_min) {
				bucket[0].push_back(i);
			}
			else if(i==nums_max){
				bucket.back().push_back(i);
			}
			else {
				bucket[(i - nums_min) / n_bucket==bucket.size()?bucket.size()-1: (i - nums_min) / n_bucket].push_back(i);
			}
			
		}
		vector<pair<int, int>> bucket_pair(nums.size(), pair<int, int>());
		for (auto &p : bucket_pair) {
			p.first = INT_MAX;
			p.second = INT_MIN;
		}
		for (int i = 0; i < bucket.size(); i++) {
			for (int j = 0; j < bucket[i].size(); j++) {
				bucket_pair[i].first = min(bucket_pair[i].first, bucket[i][j]);
				bucket_pair[i].second = max(bucket_pair[i].second, bucket[i][j]);
			}
		}
		int res = 0;
		int previous = INT_MIN;
		for (int i = 0; i < bucket_pair.size(); i++) {
			if (bucket_pair[i].first == INT_MAX) {//the bucket is empty
				continue;
			}
			if (previous == INT_MIN) {
				previous = i;
				continue;
			}

			res = max(res, bucket_pair[i].first - bucket_pair[previous].second);
			previous = i;

		}
		return res;
	}
};
int main() {
	Solution mysolu;
	vector<int> input1 = { 3,6,9,1 };
	vector<int> input2 = { 1,10000 };
	vector<int> input3 = { 1,3,1000 };
	vector<int>input4 = { 100,3,2,1 };
	vector<int>input5 = { 1,1,1,1,5,5,5,5 };
	vector<int>input6 = { 12115,10639,2351,29639,31300,11245,16323,24899,8043,4076,17583,15872,19443,
		12887,5286,6836,31052,25648,17584,24599,13787,24727,12414,5098,26096,23020,25338,28472,4345,25144,
		27939,10716,3830,13001,7960,8003,10797,5917,22386,12403,2335,32514,23767,1868,29882,31738,30157,7950,
		20176,11748,13003,13852,19656,25305,7830,3328,19092,28245,18635,5806,18915,31639,24247,32269,29079,
		24394,18031,9395,8569,11364,28701,32496,28203,4175,20889,28943,6495,14919,16441,4568,23111,
		20995,7401,30298,2636,16791,1662,27367,2563,22169,1607,15711,29277,32386,27365,31922,26142,8792 };

	int res = mysolu.maximumGap(input6);
	return 0;
}