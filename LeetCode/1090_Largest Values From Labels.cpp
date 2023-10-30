#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first > p2.first;
}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int, int>> cands;
        for (int i = 0; i < labels.size() && i < values.size(); i++) {
            cands.push_back(pair<int, int>(values[i], labels[i]));
        }
        sort(cands.begin(), cands.end(), cmp);
        unordered_map<int, int> labelMap;
        int res = 0;
        for (int i = 0; i < cands.size()&&numWanted; i++) {
            if (labelMap[cands[i].second]++ >= useLimit) continue;
            res += cands[i].first;
            numWanted--;
        }
        return res;
    }
};

class Solution2 {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        unordered_map<int, priority_queue<int, vector<int>, less<int>>> LabelMap;
        for (int i = 0; i < values.size() && i < labels.size(); i++) {
            LabelMap[labels[i]].push(values[i]);
        }
        vector<int> res(numWanted + 1, 0);
        for (auto m : LabelMap) {
            for (int j = 0; j < useLimit&&m.second.size(); j++) {
                int temp = m.second.top();
                m.second.pop();
                vector<int> pre = res;
                for (int i = 1; i <= numWanted; i++) {
                    res[i] = max(res[i], pre[i - 1] + temp);
                    
                }
            }
        }
        return res.back();
    }
};


int main() {
    Solution mysolu;
    vector<int> values = { 9, 8, 8, 7, 6 };
    vector<int> labels = { 0, 0, 0, 1, 1 };
    int numWanted = 3;
    int useLimit = 1;
    int res = mysolu.largestValsFromLabels(values, labels, numWanted, useLimit);
    return 0;
}