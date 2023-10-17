#include<vector>

using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        for (int end = arr.size() - 1; end >=1; end--) {
            if (arr[end] == end + 1) continue;
            int c = 0;
            for (; c < end; c++) if (arr[c] == end + 1) break;
            res.push_back(c);
            reverse(arr.begin(), arr.begin() + c+1);
            res.push_back(end);
            reverse(arr.begin(), arr.begin() + end+1);
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<int> arr = { 3, 2, 4, 1 };
    vector<int> res = mysolu.pancakeSort(arr);
    return 0;
}