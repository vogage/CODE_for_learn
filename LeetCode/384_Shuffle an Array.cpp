//
//  384_Shuffle an Array.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/13.
//

#include <stdio.h>
//Given an integer array nums, design an algorithm to randomly shuffle the array.
//
//Implement the Solution class:
//
//Solution(int[] nums) Initializes the object with the integer array nums.
//int[] reset() Resets the array to its original configuration and returns it.
//int[] shuffle() Returns a random shuffling of the array.
//
//
//Example 1:
//
//Input
//["Solution", "shuffle", "reset", "shuffle"]
//[[[1, 2, 3]], [], [], []]
//Output
//[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
//
//Explanation
//Solution solution = new Solution([1, 2, 3]);
//solution.shuffle();    // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must be equally likely to be returned. Example: return [3, 1, 2]
//solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
//solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]
//
//
//
//Constraints:
//
//1 <= nums.length <= 200
//-106 <= nums[i] <= 106
//All the elements of nums are unique.
//At most 5 * 104 calls will be made to reset and shuffle.
#include<vector>
#include<unordered_set>

using namespace std;


class Solution{
    
private:
    vector<int> origin;
    static bool cmp(pair<int,int>& p1,pair<int,int> &p2){
        return p1.first<p2.first;
    }
    
public:
    Solution(vector<int>& nums) {
        origin=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n=origin.size();
        vector<int> res(n,0);
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++){
            pair<int,int> p(rand(),i);
            vp.push_back(p);
        }
        sort(vp.begin(),vp.end(),cmp);
        for(int i=0;i<n;i++){
            res[i]=origin[vp[i].second];
        }
        return res;
        
        
    }

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main(){
    vector<int> input={1,2,3};
    Solution mysolu(input);
    vector<int> res=mysolu.shuffle();
    return 0;
}
