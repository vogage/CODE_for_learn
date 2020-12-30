#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
         int n = boxes.size(); 
         int res = INT_MIN;
        if (n==0)return 0;
        for (int i = 0; i < boxes.size() - 1;) {
            int j = i + 1;
            while (j<boxes.size()&&boxes[j] == boxes[i]) {
                j++;
            }
            
            vector<int> ::iterator it = boxes.begin();
            vector<int> new_boxes1(it,it+i);
            vector<int> new_boxes2(it + j, it+n);
            new_boxes1.insert(new_boxes1.end(), new_boxes2.begin(), new_boxes2.end());
            res =max (res, (j - i)*(j-i) + removeBoxes(new_boxes1));
            i = j;
        }
        return res;
    }

};


class Solution2 {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                dp[i][j] = i+1;
                for (int k = j; k < j + i;) {
                    if (boxes[k+1] == boxes[j]) {
                        
                       
                        int n_left = k - j;
                         int left = k-j==0?0:dp[k-j-1][j+1];
                        while (k <j+i && boxes[k+1] == boxes[j]) k++;
                        int n_right = j + i - k;
                        int right = j + i - k  == 0 ? 0 : dp[j + i - k-1][k + 1];      
                          dp[i][j] = max(dp[i][j], left + (i+1-n_left-n_right) * (i+1 - n_left - n_right) + right);
                    }
                    k++;
                }
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
               
            }
        }
        return dp[n - 1][0];
    }
};


class Solution3 {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int j= 0; j < n; j++) {
            for (int k = 0; k <= j; k++) {
                dp[j][j][k] = (k + 1) * (k + 1);
            }
        }
        for (int l = 1; l < n; l++) {
            for (int j = l; j < n; j++) {
                int i = j - l;
                for (int k = 0; k <= i; k++) {
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; m++) {
                        if (boxes[m] == boxes[i]) {
                            res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
                    }
                    dp[i][j][k] = res;
                }
            }
        }
        return (n == 0 ? 0 : dp[0][n - 1][0]);
    }
};

class Solution4 {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return removeBoxesSub(boxes, 0, n - 1, 0, dp);
    }
    int removeBoxesSub(vector<int>& boxes, int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i > j)return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        for (; i + 1 <= j && boxes[i + 1] == boxes[i]; i++, k++);
        int res = (k + 1) * (k + 1) + removeBoxesSub(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; m++) {
            if(boxes[i]==boxes[m])
            res = max(res, removeBoxesSub(boxes, i + 1, m - 1, 0, dp) + removeBoxesSub(boxes, m, j, k + 1, dp));
        }
        dp[i][j][k] = res;
        return res;
    }
};

int main() {
    Solution4 mysolu;
    vector<int> input = { 1,3,2,2,2,3,4,3,1 };
    int res = mysolu.removeBoxes(input);
    return 0;
}