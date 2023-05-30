#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> arr_map;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            arr_map[arr[i]] = i;
            for (int j = 0; j < i; j++) {
                int k = arr_map.find(arr[i] - arr[j]) == arr_map.end() ? -1 : arr_map[arr[i] - arr[j]];
                dp[j][i] = (arr[i] - arr[j] < arr[j] && k >= 0) ? dp[k][j] + 1 : 2;
                res = max(res, dp[j][i]);
            }
        }
        return res>2?res:0;
        
    }
private:

};


int main() {
    Solution mysolu;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<int> arr2 = { 2,4,5,6,7,8,11,13,14,15,21,22,34 };
    vector<int> arr3 = { 1,3,5 };
    int res = mysolu.lenLongestFibSubseq(arr);
	return 0;
}