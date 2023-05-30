#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int digits_size = digits.size();
        string target = to_string(n);
        vector<int> dp(target.size() + 1, 0);
        dp[target.size()] = 1;
       
        for (int k = target.size() - 1; k >= 0; k--) {
            for (int j = 0; j < digits.size(); j++) {
                if (digits[j][0] < target[k]) dp[k] += pow(digits_size, target.size() - k - 1);
                if (digits[j][0] == target[k]) dp[k] += dp[k + 1];
            }
        }

        for (int i = 1; i < target.size(); i++) {
            dp[0] += pow(digits_size, i);
        }
        return dp[0];
    }
};


int main() {
    vector<string> digits = { "1", "4", "9" };
    int n = 1000000000;

    vector<string> digits1 = { "1", "3", "5", "7" };
    int n1 = 100;

    vector<string> digits2 = { "7" };
    int n2 = 8;

    vector<string> digits3 = { "3","4","8" };
    int n3 = 4;

    vector<string> digits4 = { "5", "6" };
    int n4 = 19;

    vector<string> digits5 = { "5","7","8" };
    int n5 = 59;
    Solution mysolu;
    int res = mysolu.atMostNGivenDigitSet(digits1, n1);
	return 0;
}