#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


//A frog is crossing a river.
//The river is divided into some number of units, and at each unit, 
//there may or may not exist a stone.
//The frog can jump on a stone, but it must not jump into the water.
//
//Given a list of stones' positions (in units) in sorted ascending order, 
//determine if the frog can cross the river by landing on the last stone. ]
//Initially, the frog is on the first stone and assumes the first jump must be 1 unit.
//
//If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. 
//The frog can only jump in the forward direction.


class Solution {

public:
    bool canCross(vector<int>& stones) {
        stones_map[1].insert(1);
        stones_map[1].insert(2);
        for (int i = 2; i < stones.size(); i++) {
            stones_map[stones[i]] = unordered_set<int>();
        }
        vector<int> dir = { -1,0,1 };
        for (int i = 1; i < stones.size(); i++) {
            for (auto k : stones_map[stones[i]]) {
                int can_jump = k + stones[i];
                if (stones_map.find(can_jump) != stones_map.end()) {
                    stones_map[can_jump].insert(k);
                    stones_map[can_jump].insert(k-1);
                    stones_map[can_jump].insert(k+1);
                }
            }
        }
        return stones_map[stones.back()].size() > 0;
    }
private:
    unordered_map<int, unordered_set<int>> stones_map;
};

int main() {
    vector<int>stones = { 0, 1, 3, 5, 6, 8, 12, 17 };
    Solution mysolu;
    bool res = mysolu.canCross(stones);
	return 0;
}