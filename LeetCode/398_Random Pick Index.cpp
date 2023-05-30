//
//  398_Random Pick Index.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/3/29.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> index_map;
    Solution(vector<int>& nums) {
       
        for(int i=0;i<nums.size();i++){
            index_map[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(index_map.find(target)==index_map.end())return NULL;
        else{
            vector<int> target_index_num=index_map[target];
            return target_index_num[rand()%(target_index_num.size())];
            
        }
    }
};

int main()
{
    vector<int> nums={1,2,3,3,3};
    Solution *mysolu=new Solution(nums);
    int ans1=mysolu->pick(3);
    int ans2=mysolu->pick(1);
    int ans3=mysolu->pick(3);
    return 0;
}
