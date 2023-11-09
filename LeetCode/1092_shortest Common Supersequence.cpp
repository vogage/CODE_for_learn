#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<string>> dp(str1.size()+1, vector<string>(str2.size()+1, ""));
        for (int i = 0; i < str1.size(); i++) {
            for (int j = 0; j < str2.size(); j++) {
                if (str1[i] == str2[j]) {
                    if (dp[i + 1][j + 1].size() < dp[i][j].size() + 1) dp[i + 1][j + 1] = dp[i][j] + str1[i];
                }
                else { 
                   /* dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j+1]);
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i+1][j]);*/
                    if (dp[i + 1][j + 1].size() < dp[i][j + 1].size()) dp[i + 1][j + 1] = dp[i][j + 1];
                    if (dp[i + 1][j + 1].size() < dp[i + 1][j].size())dp[i + 1][j + 1] = dp[i + 1][j];

                }
            }
        }
        string comstr = dp[str1.size()][str2.size()];
        string res = "";
        int i = 0, j = 0;
        for (auto c : comstr) {
            while (str1[i] != c) { res += str1[i]; i++; }
            while (str2[j] != c) { res += str2[j]; j++; }
            res += c;
            i++; j++;
        }
        return res+str1.substr(i)+str2.substr(j);
    }
private:
   
};

int main() {
    Solution mysolu;
    string str1 = "abac";
    string str2 = "cab";
    string str11 = "bbbaaaba";
    string str21 = "bbababbb";
    string res = mysolu.shortestCommonSupersequence(str1, str2);
    return 0;
}

