#include <vector>
#include <queue>
#include <queue>
#include <unordered_set>
using namespace std;

//1 <= stones.length <= 30
//1 <= stones[i] <= 100

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int s : stones) sum += s;
        int theory = sum / 2;
        int res = 0;
        unordered_set<int> stoneset;
        stoneset.insert(0);
        for (int s : stones) {
            unordered_set<int> tempset = stoneset;
            for (auto t : tempset) {
                int temp = t + s;
                if (temp <= theory) {
                    res = max(res, temp);
                    stoneset.insert(temp);
                }
            }
           
        }
        return sum - res * 2;
    }
private:

};

int main() { 
    Solution mysolu;
    vector<int> stones = { 2,7,4,1,8,1 };
    vector<int> stones1 = { 31,26,33,21,40 };
    vector<int> stones2 = { 89,23,100,93,82,98,91,85,33,95,72,98,63,46,17,91,92,72,77,79,99,96,55,72,24,98,79,93,88,9 };
    int res = mysolu.lastStoneWeightII(stones);
    return 0;
}