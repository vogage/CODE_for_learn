#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),cmp);
        int n = envelopes.size();
        if (n <= 1)return n;
        vector<int> dp(n, 0);
        int size =1;
        dp[0] = envelopes[0][1];
        int cur = envelopes[0][0];

       for(int k=1;k<envelopes.size();k++){
            int i = 0, j = size;
            int index = binary_search(dp, i, j, envelopes[k][1]);
            if (index == size) {             
                size++;           
            }
            dp[index] = envelopes[k][1];            
        }
        return size;
    }

    int binary_search(vector<int>& nums, int i, int j,int target) {       
       /* sort(nums.begin(), nums.end());*/
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] < target) {
                i = m+1;
            }
            else {
                j = m;
            }
        }
        return i;
    }

private:
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] != v2[0]) {
            return v1[0] < v2[0];
        }
        else {
            return v1[1] > v2[1];
        }
    }
    bool can_fit(int i,int j,vector<vector<int>>& envelopes) {
        return envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1];
    }
    unordered_map<int, int> envelop_map;
    vector<bool> used;
  
};

int main() {
    Solution mysolu;
    vector<vector<int>> envelopes = { {5, 4},{6, 4},{6, 7},{2, 3} };
    vector<vector<int>> envelopes2 = { {1,1},{1,1},{1,1} };
    vector<vector<int>> envelopes3 = { {17,18 }, { 20, 4 }, { 4, 3 }, { 14, 6 }, { 16, 4 }, { 8, 11 }, { 17, 11 }, { 18, 7 }, { 20, 12 }};
    vector<vector<int>> envelopes4 = { {2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380} };
    vector<vector<int>> envelopes5 = { {4,5},{4,6},{6,7},{2,3},{1,1} };
    vector<int> binary_search_nums = { 2,6,8,3,5,1 };
  /*  int index = mysolu.binary_search(binary_search_nums,0,binary_search_nums.size()-1,4);*/
    int res = mysolu.maxEnvelopes(envelopes4);
    return 0;
}