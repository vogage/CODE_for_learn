#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Node {
public:

private:
    unordered_set<int> Primes;
    int cnt;
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        return res;
    }
private:
    int gcd(int a, int b) {
        if (b == 0)return a;
        return gcd(b, a % b);
    }
};

int main() {
    Solution mysolu;
    vector<int> nums = { 2, 3, 6, 7, 4, 12, 21, 39 };
    int res = mysolu.largestComponentSize(nums);
    return 0;
}