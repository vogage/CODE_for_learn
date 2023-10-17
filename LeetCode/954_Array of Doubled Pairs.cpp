#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> arrMap;
        for (auto i : arr) arrMap[i]++;
        for (auto m = arrMap.begin(); m != arrMap.end(); m++) {
            if (m->second == 0) continue;
            if (m->first < 0) {
                if (arrMap[m->first / 2] < m->second) return false;
                else arrMap[m->first / 2] -= m->second;
            }
            else if (m->first == 0) { if (m->second % 2 == 1)return false; }
            else {
                if (arrMap[m->first * 2] < m->second)return false;
                else arrMap[m->first * 2] -= m->second;
            }
        }
        return true;
    }
};

int main() {
    Solution mysolu;
    vector<int>  arr = { 1,2,4,16,8,4 };
    vector<int> arr1 = { 2,4,0,0,8,1 };
    bool res = mysolu.canReorderDoubled(arr1);
    return 0;
}