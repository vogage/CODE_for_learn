#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> ArrMap;
        long long res = 0, Mod = 1000000007;
    
        for (int i = 0; i < arr.size(); i++) {
            ArrMap[arr[i]]++;
        }
        for (int begin = 0; begin < arr.size(); begin++) {
            ArrMap[arr[begin]]--;
            unordered_map<int, int> tempMap = ArrMap;
            for (int mid = begin + 1; mid < arr.size(); mid++) {
                tempMap[arr[mid]]--;
                int thirdval = target - arr[begin] - arr[mid];
            
                res += tempMap[thirdval];
                res = res % Mod;

            }
            
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    //arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5], target = 8
    vector<int> arr = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5 };
    int target = 8;
    int res = mysolu.threeSumMulti(arr, target);
	return 0;
}