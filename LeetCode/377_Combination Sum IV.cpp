//
//  377_Combination Sum IV.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/11.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//
//The answer is guaranteed to fit in a 32-bit integer.


//Input: nums = [1,2,3], target = 4
//Output: 7
//Explanation:
//The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//Note that different sequences are counted as different combinations.

// constrains:

//1 <= nums.length <= 200
//1 <= nums[i] <= 1000
//All the elements of nums are unique.
//1 <= target <= 1000


class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
       vector<vector<vector<int>>> dp_vec(target+1,vector<vector<int>>());
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                int temp=i-nums[j];
                if(temp==0){
                    dp_vec[i].push_back(vector<int>(1,nums[j]));
                }else if(temp>0){
                    if(dp_vec[temp].size()!=0){
                        for(int k=0;k<dp_vec[temp].size();k++){
                            vector<int> temp_insert=dp_vec[temp][k];
                            temp_insert.push_back(nums[j]);
                            dp_vec[i].push_back(temp_insert);
                        }
                    }
                }else{
                    
                }
                
            }
        }
        return dp_vec[target].size();
        
    }
};

class Solution3{
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp_vec(target+1,0);
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                int temp=i-nums[j];
                if(temp==0){
                    dp_vec[i]++;
                    int see=dp_vec[i];
                }else if(temp>0){
                    dp_vec[i]=dp_vec[i]+dp_vec[temp];
                }else{
                    
                }
            }
        }
        return dp_vec[target];
    }
    
};

//private int[] dp;
//
//public int combinationSum4(int[] nums, int target) {
//    dp = new int[target + 1];
//    Arrays.fill(dp, -1);
//    dp[0] = 1;
//    return helper(nums, target);
//}
//
//private int helper(int[] nums, int target) {
//    if (dp[target] != -1) {
//        return dp[target];
//    }
//    int res = 0;
//    for (int i = 0; i < nums.length; i++) {
//        if (target >= nums[i]) {
//            res += helper(nums, target - nums[i]);
//        }
//    }
//    dp[target] = res;
//    return res;
//}

class Solution{
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp_vec=vector<int>(target+1,-1);
        dp_vec[0]=1;
        return helper(nums,target);
        
    }
private:
    int helper(vector<int>& nums,int target){
        if(dp_vec[target]!=-1){
            return dp_vec[target];
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(target>=nums[i]){
                res+=helper(nums,target-nums[i]);
            }
        }
        dp_vec[target]=res;
        return res;
    }
    
    vector<int> dp_vec;
};

int main(){
    Solution mysolu;
    vector<int> nums={1,2,3};
    int target=4;
    vector<int> nums1={4,2,1};
    int target1=32;
    vector<int> nums2={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111};
    int target2=999;
//    Line 10: Char 30: runtime error: signed integer overflow: 2147483647 + 1 cannot be represented in type '__gnu_cxx::__alloc_traits<std::allocator<int>, int>::value_type' (aka 'int') (solution.cpp)
//    SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:19:30
    
    int res=mysolu.combinationSum4(nums2,target2);
    return 0;
}
