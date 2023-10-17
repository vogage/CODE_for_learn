#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<string> NumSet;
        //initial
        for (int i = 1; i <= 9; i++) {
            NumSet.insert(to_string(i));
        }
        for (int i = 0; i < n-1; i++) {
            unordered_set<string> temp;
            for (auto str : NumSet) {
                int e = str.back() - '0';
                if (e - k >= 0) temp.insert(str + to_string(e - k));
                if (e + k <= 9) temp.insert(str + to_string(e + k));
            }
            NumSet = temp;
        }
        vector<int> res;
        for (auto str : NumSet) res.push_back(stoi(str));
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<int> res = mysolu.numsSameConsecDiff(3,7);
    return 0;
}
