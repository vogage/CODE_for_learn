#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, cur, res;
        for (int i = 0; i < arr.size(); i++) {
            cur = {arr[i] };
            for (int j : prev) cur.insert(j |arr[i]);
            for (int k : cur)res.insert(k);
            prev = cur;
        }
        return res.size();



        
    }
};


int main() {
    Solution mysolu;
    vector<int> arr = { 1,1,2 };
    int res = mysolu.subarrayBitwiseORs(arr);

	return 0;
}