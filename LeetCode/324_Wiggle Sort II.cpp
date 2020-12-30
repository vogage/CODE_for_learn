#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp=nums;
        int n = nums.size();
        int m = (n + 1) >> 1;
        for (int i = m - 1, j = 0; i >= 0; i--, j = j + 2) {
            nums[j] = temp[i];
        }
        for (int i = n - 1, j = 1; i >= m; i--, j = j + 2) {
            nums[j] = temp[i];
        }
    }
};

class Solution2 {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy = nums;
        int m = (n + 1) >> 1;
        int median = KthSmallNumber(nums, m);
        for (int i = 0, j = 0, k = n - 1; j <= k;) {
            if (copy[j] < median) {
                swap(copy, i++, j++);
            }
            else if (copy[j] > median) {
                swap(copy, j, k--);
            }
            else {
                j++;
            }
        }
        for (int i = m - 1, j = 0; i >= 0; i--, j += 2) {
            nums[j] = copy[i];
        }
        for (int i = n - 1, j = 1; i >= m; i--, j += 2) {
            nums[j] = copy[i];
        }
    }

    int KthSmallNumber(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        k--;
        while (l < r) {
            int m = getMiddle(nums, l, r);
            if (m < k) {
                l = m + 1;
            }
            else if (m > k) {
                r = m - 1;
            }
            else {
                break;
            }
        }
        return nums[k];
    }

    int getMiddle(vector<int>& nums, int l, int r) {
        int i = l;
        for (int j = l + 1; j <= r; j++) {
            if (nums[j] < nums[l]) swap(nums, ++i, j);
        }
        swap(nums, l, i);
        return i;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
};

int main() {
    vector<int> nums = { 1, 5, 1, 1, 6, 4 };
    vector<int> nums2 = { 1,1,2,1,2,2,1 }; 
    vector<int> nums3 = { 4,5,5,5,5,6,6,6 };
    int n = 10;
    int m = (n | 1);
    Solution2 mysolu;
    mysolu.wiggleSort(nums);
	return 0;
}