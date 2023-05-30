#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

//Given an array of intervals intervals where intervals[i] = [starti, endi], 
//return the minimum number of intervals 
//you need to remove to make the rest of the intervals non - overlapping.

static bool cmp(vector<int>& interval1, vector<int>& interval2) {
    return interval1[1] < interval2[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        if (n == 0)return 0;
        int count = 1;
        int temp_end = intervals[0][1];
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] >= temp_end) {
                count++;
                temp_end = intervals[i][1];
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       /* {1, 2}, { 2, 3 }, { 3, 4 }, { 1, 3 }*/
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<vector<vector<int>>> dp(intervals.back()[1] +1,vector<vector<int>>());
        for (int i = 1; i <= intervals.back()[1]; i++) {
            dp[i] = dp[i - 1];
            for (int j = 0; j < n; j++) {         
                if (intervals[j][1] >i)break;             
                if (can_put(dp[i], intervals[j])) {
                    if (dp[i].size() < (dp[intervals[j][0]].size() + 1)) {
                        dp[i].push_back(intervals[j]); 
                    }
                }
               
            }
        }
        return n - dp.back().size();
    }
    bool can_put(const vector<vector<int>>& intervals_set, const vector<int>& interval) {
        for (vector<int> v : intervals_set) {
            if (is_overlap(v, interval))return false;
        }
        return true;
    }

    bool is_overlap(const vector<int> &interval1,const vector<int> &interval2){
        if (interval1[0]<=interval2[0] && interval1[1]>interval2[0]) return true;
        if (interval1[0] >= interval2[0] && interval1[1] <= interval2[1])return true;
        if (interval1[0] < interval2[1] && interval1[1] >= interval2[1])return true;
        return false;
    }
};

int main() {
    vector<vector<int>>  intervals{ {1, 2},{2, 3},{3, 4},{1, 3} };
    Solution mysolu;
    int res = mysolu.eraseOverlapIntervals(intervals);
    return 0;
}

