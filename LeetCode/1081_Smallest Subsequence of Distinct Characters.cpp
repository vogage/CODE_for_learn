#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

struct Node {
    char c;
    int index;
    bool changable;
    Node() :c('&'), index(-1), changable(false) {}
    Node(char c, int i) :c(c), index(i), changable(false) {}
};

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> seen(26, false);
        vector<int> last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int charIndex = s[i] - 'a';
            if (seen[charIndex]) continue;
            seen[charIndex] = true;
            while (!res.empty() && s[i]<res.back() && last[res.back() - 'a']>i) {
                seen[res.back() - 'a'] = false;
                res.pop_back();
               
            }
            res.push_back(s[i]);
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    string s = "cbacdcbc";
    string res = mysolu.smallestSubsequence(s);
    return 0;
}