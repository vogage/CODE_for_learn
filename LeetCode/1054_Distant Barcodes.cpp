#include<unordered_map>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class cmp {
public:
    bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.second <  p2.second;
    }
};

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        if (n == 1)return barcodes;
        unordered_map<int, int> codeMap;
        for (auto c : barcodes) codeMap[c]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pque;
        for (auto m : codeMap) pque.push(m);
        int pos = 0;
        while (!pque.empty()) {
            pair<int, int> temp = pque.top();
            pque.pop();
            for (int cnt = 0; cnt < temp.second; cnt++, pos += 2) {
                if (pos >= barcodes.size()) pos = 1;
                barcodes[pos] = temp.first;
            }
        }
        return barcodes;
    }
};


int main() {
    Solution mysolu;
    vector<int>  barcodes = { 1, 1, 1, 1, 2, 2, 3, 3 };
    vector<int> barcodes1 = { 1, 1,2 };
    vector<int> barcodes2 = { 2,2,1,3 };
    vector<int> barcodes3 = { 2,2,2,1,5 };
    vector<int> res = mysolu.rearrangeBarcodes(barcodes3);
	return 0;
}
