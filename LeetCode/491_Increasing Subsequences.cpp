#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> nums_set;
        if (nums.size() < 2)return res;
       // sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] > nums[i + 1])return res;
        }
        vector<int> seed = { nums[0],nums[1] };
        putinSet(nums_set, seed);
        for (int i = 1; i < nums.size(); i++) {
            refresh(res,nums_set, nums,i);
        }
        res.clear();
        for (auto s : nums_set) {
            vector<int> temp;
            while (s % 10) {
                int tail = s % 10;
                temp.push_back(tail);
                s = s / 10;
            }
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        }
        return res;
    }
    void refresh(vector<vector<int>>& res,unordered_set<int>&nums_set, vector<int>& nums,int index) {
        int n = res.size();
        for (int i = 0; i < index; i++) {
            vector<int> temp = { nums[i],nums[index] };
            res.push_back(temp);
            putinSet(nums_set, temp);
        }
        for (int i = 0; i < n; i++) {
            vector<int> temp = res[i];
            temp.push_back(nums[index]);
            res.push_back(temp);
            putinSet(nums_set, temp);
        }
    }

    void putinSet(unordered_set<int>& nums_set, vector<int>& seed) {
        int member = 0;
        for (int i = 0; i < seed.size(); i++) {
            member = member * 10 + seed[i];
        }
        if (nums_set.find(member) == nums_set.end()) {
            nums_set.insert(member);
        }
        return;
    }
};

class Solution2 {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 2)return res;
        //// sort(nums.begin(), nums.end());
        //for (int i = 0; i < nums.size() - 1; i++) {
        //    if (nums[i] > nums[i + 1])return res;
        //}
        if (nums[0] <= nums[1]) {
            vector<int> temp = { nums[0],nums[1] };
            res.push_back(temp);
        }
        int index = 0;
        for (; index < nums.size() - 1; index++) {
            if (nums[index] > nums[index + 1]) break;
        }
        for (int i = 2; i <= index; i++) {
            if (nums[i] == nums[i - 1]) {
                Equaladd(res, nums,i);
            }else{
                notEqualadd(res, nums,i);
            }
        }
        return res;
    }

    void notEqualadd(vector<vector<int>>& res, vector<int>& nums,int index) {
        int n = res.size();
        for (int i = 0; i < index; i++) {
            if (nums[i] <= nums[index])
            {
                vector<int> temp = { nums[i],nums[index] };
                if (i == 0 && nums[i] != nums[index]) res.push_back(temp);
                if (i > 0 && nums[i] != nums[i - 1])
                    res.push_back(temp);
            }
          
        }

        for (int i = 0; i < n; i++) {
                vector<int> temp = res[i];
                if (nums[index] >= temp.back()) {
                    temp.push_back(nums[index]);
                    res.push_back(temp);
                }

         }
        
        return;
    }
    void Equaladd(vector<vector<int>>& res, vector<int>& nums, int index) {
        int n = res.size();
        vector<int> temp = {nums[index-1],nums[index] };
        res.push_back(temp);

            for (int i = 0; i < n; i++) {
                if (res[i].back() == nums[index]) {
                    vector<int> temp = res[i];
                    temp.push_back(nums[index]);
                    res.push_back(temp);
                }
            }

        return;
    }
};

class Solution3 {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dsf(res, temp, nums, 0);
        return res;
    }
    void dsf(vector<vector<int>>& res, vector<int> temp, vector<int>& nums, int index) {
        if (temp.size() > 1) res.push_back(temp);
        unordered_set<int> nums_set;
        for (int i = index; i < nums.size(); i++) {
            if (nums_set.find(nums[i]) != nums_set.end()) continue;
            if (temp.size() == 0 || nums[i] >= temp.back()) {
                nums_set.insert(nums[i]);
                temp.push_back(nums[i]);
                dsf(res, temp, nums, i + 1);
                temp.pop_back();
            }

        }
    }
};

int main() {
    Solution3 mysolu;
    vector<int> input = { 4, 6, 7, 7 };
    vector<int> input2 = { 3,4,4,7};
    vector<vector<int>> res = mysolu.findSubsequences(input2);
    return 0;
}