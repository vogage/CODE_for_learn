#include<vector>
#include<list>

using namespace std;

//Given an array nums which consists of non-negative integers and an integer m,
//you can split the array into m non-empty continuous subarrays.
//
//Write an algorithm to minimize the largest sum among these m subarrays.

struct Node {
    int sum_val;
    pair<int, int> index;
    Node(int a, int b, int c) :sum_val(a), index({ b,c }) {}
};


class Solution {
public:
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;

        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            }
            else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }

        }

        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }

    int splitArray(vector<int>& nums, int m) {

        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }

        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {

            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;

            // Find the minimum splits. If splitsRequired is less than
            // or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
            }
            else {
                // Move towards right if splitsRequired is more than m
                left = maxSumAllowed + 1;
            }
        }

        return minimumLargestSplitSum;
    }
};




class Solution3 {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> nums_dp(m + 1, vector<int>(n, 0));
        nums_dp[1][n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--) {
            nums_dp[1][i] = nums[i] + nums_dp[1][i + 1]; 
        }

        for (int i = 1; i <= m-1; i++) {
            for (int cur = n - i - 1; cur >= 0; cur--) {
                int temp_min = INT_MAX;
                for (int k = cur; k < n - i; k++) {
                    int temp_max = max(sum(cur, k, nums), nums_dp[i][k+1]);
                    temp_min = min(temp_min, temp_max);
                }
                nums_dp[i+1][cur] = temp_min;
            }

        }

        int res = 0;
        for (auto i : nums_dp[m]) res = max(res, i);
        return res;
    }
private:
    int sum(int begin, int end, vector<int>& nums) {
        int res = 0;
        for (int i = begin; i <= end; i++) {
            res += nums[i];
        }
        return res;
    }

};


class Solution2 {
public:
    int splitArray(vector<int>& nums, int m) {
        list<Node> nums_sum;
        for (int i = 0; i < nums.size(); i++) {
            Node temp_node(nums[i],i,i+1);
            nums_sum.push_back(temp_node);
        }
        while (nums_sum.size() > m) {
          auto p= two_sum_min(nums_sum);
          merge_node_list(p, nums_sum);
        }
        int max_res = INT_MIN;
        for (auto p = nums_sum.begin(); p != nums_sum.end(); p++) {
            max_res = max(max_res, p->sum_val);
        }
        return max_res;
    }
private:
    list<Node>::iterator two_sum_min(list<Node>& nums_sum) {
        pair<int, int> p;
        int res_min = INT_MAX;
        list<Node>::iterator min_iter = nums_sum.begin();
        auto iter_left = nums_sum.begin();
        auto iter_right = nums_sum.begin();
        iter_right++;
        while (iter_right != nums_sum.end()) {
            int temp_two_sum = iter_left->sum_val + iter_right->sum_val;
            if (temp_two_sum < res_min) {
                min_iter = iter_left;
                res_min = temp_two_sum;
            }
            iter_left++;
            iter_right++;
        }
        return min_iter;
    }

    void merge_node_list(list<Node>::iterator& it, list<Node>& nums_sum) {
        auto it0 = it; it++;
        Node temp_new_node(it0->sum_val + it->sum_val, it0->index.first, it->index.second);
        nums_sum.insert(it, temp_new_node);
        nums_sum.erase(it);
        nums_sum.erase(it0);
        return;
    }
};

//The answer is between maximum value of input array numbers and sum of those numbers.
//Use binary search to approach the correct answer.We have l = max number of array;
//r = sum of all numbers in the array; Every time we do mid = (l + r) / 2;
//Use greedy to narrow down leftand right boundaries in binary search.
//
//3.1 Cut the array from left.
//3.2 Try our best to make sure that the sum of numbers between each two cuts(inclusive) is large enough but still less than mid.
//3.3 We'll end up with two results: either we can divide the array into more than m subarrays or we cannot.
//
//If we can, it means that the mid value we pick is too small 
//because we've already tried our best to make sure each part holds as many non-negative numbers as we can 
//but we still have numbers left. So, it is impossible to cut the array into m parts and make sure each parts is no larger than mid. 
//We should increase m. This leads to l = mid + 1;
//If we can't, it is either we successfully divide the array into m parts and the sum of each part is less than mid, 
//or we used up all numbers before we reach m. 
//Both of them mean that we should lower mid because we need to find the minimum one. This leads to r = mid - 1;

int main() {
// Input: nums = [7, 2, 5, 10, 8], m = 2
// Output : 18
// Explanation :
//	There are four ways to split nums into two subarrays.
//	The best way is to split it into[7, 2, 5] and [10, 8],
// where the largest sum among the two subarrays is only 18
    vector<int> nums = { 7, 2, 5, 10, 8 };
    int m = 2;
    Solution mysolu;
    int res = mysolu.splitArray(nums, m);
    return 0;

}