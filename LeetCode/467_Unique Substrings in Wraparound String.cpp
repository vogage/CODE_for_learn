#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0)return 0;
        vector<int> end_char(26, 0);
        int cout = 1;
        int res = 0;
        end_char[p[0]-'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25) {
                cout++;
            }
            else {               
                cout = 1;
            }
            end_char[p[i] - 'a'] = max(end_char[p[i] - 'a'], cout);
        }
        for (auto n : end_char) res += n;
        return res;
    }
private:
    string s = "abcdefghijklmnopqrstuvwxyz";
};

int main() {
    Solution mysolu;
    string p = "zab";
    string p1 = "cac";
    string p2 = "abaab";
    int res = mysolu.findSubstringInWraproundString(p);

    return 0;
}
