#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 100
//- 100 <= matrix[i][j] <= 100
//- 105 <= k <= 105
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if (n == 0)return 0;
        int m = matrix[0].size();
        int res = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> row(m, 0);
            for (int right = left; right < n; right++) {
                vec_add(row, matrix[right]);
                res = max(res, dp_col_sum(row, k));
            }
        }
        return res;
    }
private:
   
    void vec_add(vector<int>& v1, const vector<int>& v2) {
        for (int i = 0; i < v1.size() && i < v2.size(); i++) {
            v1[i] += v2[i];
        }
        return;
    }

    int dp_col_sum(const vector<int>& nums, int k) {
        int res = INT_MIN;
        int csum = 0;
        set<int> csum_set;
        //csum_set.insert(0);
        for (int i : nums) {
            csum += i;
            set<int> ::iterator iter = csum_set.lower_bound(csum - k);
            if (iter != csum_set.end()) {
                res = max(res, csum - *iter);
            }
            csum_set.insert(csum);
        }
        return res;
    }

};


int main() {
    /*  matrix = [[1, 0, 1], [0, -2, 3]], k = 2*/
    Solution mysolu;
    vector<vector<int>> matrix = { {1,0,1},{0,-2,3} };
    vector<vector<int>> matrix2 = { {2,2,-1} };
    vector<vector<int>> matrix3 = { {5,-4,-3,4},
                                                           {-3,-4,4,5},
                                                           { 5,  1,5,-4} };

    int k = 2;
    int res = mysolu.maxSumSubmatrix(matrix2,3);
    return 0;
}