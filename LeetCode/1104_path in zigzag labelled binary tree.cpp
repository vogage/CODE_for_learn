#include <vector>

using namespace std;


class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int temp = label;
        bool flag = true;
        int level = 1;
        while (level <= label) level = level << 1;
        while (label) {
            level = level >> 1;
            if (flag) {
                res.push_back(label);
            }
            else {
                res.push_back(level - 1 +( level<<1) - label);
            }
            label = label / 2;
            flag = !flag;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

int main() {
    Solution mysolu;
    int label = 14;
    int label1 = 26;
    int label2 = 16;
    vector<int> res = mysolu.pathInZigZagTree(label2);
    return 0;
}