#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//Each node has either 0 or 2 children;
//The values of arr correspond to the values of each leaf in an in - order traversal of the tree.
//The value of each non - leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        //sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<vector<int>> intervalMax(n,vector<int>(n,0));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int i = 0; i < n; i++) {
            int temp = 0;
            for (int j = i; j >=0; j--) {
                temp = max(temp, arr[j]);
                intervalMax[j][i] = temp;
            }
        }
   
        

        for (int i = 0; i < n; i++) {
            for (int j = i-1 ; j >= 0; j--) {
                for (int k = i-1; k >= j; k--) {
                    dp[j][i] = min(dp[j][i],dp[j][k] + dp[k + 1][i] + intervalMax[j][k] * intervalMax[k + 1][i]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution mysolu;
    vector<int> arr = { 6,2,4 };
    vector<int> arr1 = { 7,12,8,10 };
    vector<int> arr2 = { 15,13,5,3,15 };
    int res = mysolu.mctFromLeafValues(arr2);
    return 0;
}