#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>

using namespace std;


bool cmp(string& str1, string& str2) {
    return str1.size() < str2.size();
}

bool beChain(string& str1, string& str2) {
    if (str1.size() + 1 != str2.size()) return false;
    int i1 = 0;
    int i2 = 0;
    bool isdif = false;
    while (i1 < str1.size() && i2 < str2.size()) {
        if (str1[i1] == str2[i2]) {
            i1++;
            i2++;
        }
        else {
            i2++;
            isdif = true;
        }
    }
        if (!isdif) i2++;
        return i1 == str1.size() && i2 == str2.size();
    
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        map<int, vector<int>> lenmap;
        for (int i = 0; i < words.size(); i++) {
            lenmap[words[i].size()].push_back(i);
        }
        int res = 1;
        vector<int> dp(words.size(), 1);
        for (auto samelenstr : lenmap) {
            int len = samelenstr.first;
            if (lenmap.find(len + 1) == lenmap.end()) continue;
            else {
                for (int ks = 0; ks < samelenstr.second.size(); ks++) {
                    for (int kb = 0; kb < lenmap[len + 1].size(); kb++) {
                        int index1 = samelenstr.second[ks];
                        int index2 = lenmap[len + 1][kb];
                        if (beChain(words[index1], words[index2])) {
                            dp[index2] = max(dp[index2], dp[index1] + 1);
                            res = max(dp[index2], res);
                        }
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<string> words = { "a","b","ba","bca","bda","bdca" };
    int res = mysolu.longestStrChain(words);
    return 0;
}