#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> res;
        unordered_map<int, pair<int, int>> carryMap;
        carryMap[-2] = { 0,1 };
        carryMap[-1] = { 1,1 };
        carryMap[0] = { 0,0 };
        carryMap[1] = { 1,0 };
        carryMap[2] = { 0,-1 };
        carryMap[3] = { 1,-1 };
        int carry = 0;
        int i = 0;
        while(i<n||i<m||carry){
            int val =(i < n ? arr1[n-1-i] : 0)+ (i < m ? arr2[m-1-i] : 0) + carry;
            pair<int, int> temp = carryMap[val];
            res.push_back(temp.first);
            carry = temp.second;
            i++;
       }
        while (res.back() == 0) res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<int> arr1 = { 1, 1, 1, 1, 1 };
    vector<int> arr2 = { 1, 0, 1 };
    vector<int> res = mysolu.addNegabinary(arr1, arr2);
    return 0;
}
