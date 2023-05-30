#include<vector>

using namespace std;
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
class Solution {
public:
    int fib(int n) {
        if (n < 2)return n;
        vector<int>fib_nums(n + 1, 0);
        fib_nums[0] = 0;
        fib_nums[1] = 1;
        for (int i = 2; i <= n; i++) {
            fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
        }
        return fib_nums[n];
    }
};

int main() {
    Solution mysolu;
    int res = mysolu.fib(4);
    return 0;
}