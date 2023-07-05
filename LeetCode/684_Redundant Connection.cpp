//
//  684_Redundant Connection.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/25.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       
    }
private:
    
};


int main(){
    Solution mysolu;
    vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> edges2={{1,2},{1,3},{2,3}};
    vector<vector<int>> edges3={{1,3},{3,4},{1,5},{3,5},{2,3}};
    vector<int> res=mysolu.findRedundantConnection(edges);
    return 0;
}
