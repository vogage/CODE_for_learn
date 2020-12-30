#include<stdio.h>
#include<vector>

using namespace std;

class NumArray {
	vector<int> sums;
public:
	NumArray(vector<int>& nums) {
		sums = nums;
		for (int i = 1; i < nums.size(); i++) {
			sums[i] = sums[i - 1] + sums[i];
		}
	}

	void update(int i, int val) {
		if (i != 0) {
			int change = sums[i] - sums[i - 1];
			change = val - change;
			for (int j = i; j < sums.size(); j++) {
				sums[j] += change;
			}
		}
		else {
			int change = val - sums[0];
			for (int j = 0; j < sums.size(); j++) {
				sums[j] += change;
			}
		}

		
	}

	int sumRange(int i, int j) {
		if (i != 0) {
			return sums[j] - sums[i - 1];
		}
		else {
			return sums[j];
		}
	}
};


class NumArray2 {
	class SegmentTreeNode {
	public:
		int start;
		int end;
		SegmentTreeNode *left;
		SegmentTreeNode *right;
		int sum;

		SegmentTreeNode(int i,int  j) {
			start = i;
			end = j;
			left = nullptr;
			right = nullptr;
		}
	};

	SegmentTreeNode *root = nullptr;

public:
	NumArray2(vector<int>& nums) {
		root=build_segmentTree(nums, 0, nums.size() - 1);
	}

	int getmid(int start, int end) {
		return start + (end-start) / 2;
	}
	SegmentTreeNode *build_segmentTree(vector<int>&nums, int start, int end) {
		if (start > end) return nullptr;
		else{
			SegmentTreeNode *ret = new SegmentTreeNode(start, end);
			if (start == end) {
				ret->sum = nums[start];
			}
			else {
				int mid = getmid(start, end);
				ret->left = build_segmentTree(nums,start, mid);
				ret->right = build_segmentTree(nums,mid+1, end);
				ret->sum = ret->left->sum + ret->right->sum;
			}
			return ret;
		}
		return nullptr;
	}
	void update(int i, int val) {
		updateTree(root, i, val);
	}
	void updateTree(SegmentTreeNode* root, int i, int val) {
		if (root->start == root->end) {
			root->sum = val;
		}
		else {
			int mid = getmid(root->start, root->end);
			if (i > mid) {
				updateTree(root->right, i, val);

			}
			else {
				updateTree(root->left, i, val);
			}
			root->sum = root->left->sum + root->right->sum;
		}
	}
	int sumRange(int i, int j) {
		return sumTreeRange(root, i, j);
	}
	int sumTreeRange(SegmentTreeNode* root, int i, int j) {
		if (root->start == i && root->end == j)return root->sum;
		int mid = getmid(root->start, root->end);
		if (j <= mid) {
			return sumTreeRange(root->left, i, j);
		}
		else if(i>=mid+1){
			return sumTreeRange(root->right, i, j);
		}
		else {
			return sumTreeRange(root->left, i, mid) + sumTreeRange(root->right, mid+1, j);
		}
	}

};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

int main() {
	vector<int> nums = { 1,3,5 };
	//NumArray2* obj = new NumArray2(nums);
	//int param_2 = obj->sumRange(0, 2);
	//obj->update(1, 2);
	//int param_3 = obj->sumRange(0, 2);

	//["NumArray", "sumRange", "sumRange", "sumRange", "update", "update", "update", "sumRange", "update", "sumRange", "update"]
	//[[[0, 9, 5, 7, 3]], [4, 4], [2, 4], [3, 3], [4, 5], [1, 7], [0, 8], [1, 2], [1, 9], [4, 4], [3, 4]]
	nums = { 0,9,5,7,3 };
	NumArray2* obj2 = new NumArray2(nums);
	int pra1 = obj2->sumRange(4, 4);
	int pra2 = obj2->sumRange(2, 4);
	int pra3 = obj2->sumRange(3, 3);
	obj2->update(4, 5);
	obj2->update(1, 7);
	obj2->update(0, 8);
	int pra4 = obj2->sumRange(1, 2);
	obj2->update(1, 9);
	int pra5 = obj2->sumRange(4, 4);
	obj2->update(3, 4);
	return 0;
}