#include<stdio.h>
#include<vector>

using namespace std;

//Suppose you have n integers labeled 1 through n.
//A permutation of those n integers perm(1 - indexed) is considered a beautiful arrangement 
//if for every i(1 <= i <= n), either of the following is true:
//
//perm[i] is divisible by i.
//i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.

//I think we could use memorization to improve the backtracking since there are many overlap subproblems.
//For example, N = 10, index 1 choose 4 and 2 choose 8 
//vs 
//1 choose 8 and 2 choose 4, the left subproblems are overlaped.



class Solution {
public:
    int countArrangement(int n) {
        used = vector<bool>(n + 1, false);
        count = 0;
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        
        dfs( n, nums);
        return count;
    }
private:
    void dfs(int pos,vector<int>& nums) {       
        if (pos == 0) {
            count++;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i+1]) {
                if (nums[i] % pos == 0 || pos % nums[i] == 0) {
                    used[i + 1] = true;
                    dfs(pos-1, nums);
                    used[i + 1] = false;
                }
            }
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    int count;
    vector<bool> used;
};


int main() {

    //The first beautiful arrangement is[1, 2]:
    //-perm[1] = 1 is divisible by i = 1
    //    - perm[2] = 2 is divisible by i = 2
    //    The second beautiful arrangement is[2, 1] :
    //    -perm[1] = 2 is divisible by i = 1
    //    - i = 2 is divisible by perm[2] = 1
    Solution mysolu;
    int res = mysolu.countArrangement(2);
	return 0;
}