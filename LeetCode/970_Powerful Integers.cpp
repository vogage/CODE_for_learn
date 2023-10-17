#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> xpows = getPowNums(x, bound);
        vector<int> ypows = getPowNums(y, bound);
        unordered_set<int> visited;
        vector<int> res;
        for (int i = 0; i < xpows.size(); i++) {
            for (int j = 0; j < ypows.size(); j++) {
                int temp = xpows[i] + ypows[j];
                if (temp <= bound ) {
                    if (visited.find(temp) == visited.end()) {
                        visited.insert(temp);
                        res.push_back(temp);
                    }
                }
                else break;
            }
        }
        return res;
    }
private:
    vector<int> getPowNums(int x, int bound) {
        if (bound < 1)return vector<int>();
        if (x == 1) return vector<int>(1, 1);
        int temp = 1;
        vector<int> res;
        res.push_back(1);
        while (temp < bound) {
            temp = temp * x;
            res.push_back(temp);
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    //x = 2, y = 3, bound = 10
    int x = 2, y = 3, bound = 10;
    vector<int> res = mysolu.powerfulIntegers(x, y, bound);
	return 0;
}