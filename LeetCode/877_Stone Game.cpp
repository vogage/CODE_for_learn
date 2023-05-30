//
//  877_Stone Game.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/28.
//

#include <stdio.h>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        len=piles.size();
        pair<int,int> res=dfs(0,len-1,piles);
        return res.first>res.second;
    }
private:
    pair<int,int> dfs(int i,int j,vector<int>& piles){
        if(i>=j)return pair<int,int>(0,0);
        int index=get_key(i, j);
        if(piles_map.find(index)!=piles_map.end())return piles_map[index];
        
        //fisrt choice : select the left
        pair<int,int> left_right=dfs(i+1,j-1,piles);
        left_right.first+=piles[i];left_right.second+=piles[j];
        pair<int,int> left_left=dfs(i+2,j,piles);
        left_left.first+=piles[i];left_left.second+=piles[i+1];
        
        pair<int,int> left_res=left_right.first>left_left.first?left_left:left_right;
        
        //second choice: select the right
        pair<int,int> right_left=dfs(i+1,j-1,piles);
        right_left.first+=piles[j];right_left.second+=piles[i];
        pair<int,int> right_right=dfs(i,j-2,piles);
        right_right.first+=piles[j];right_right.second+=piles[j-1];
        
        pair<int,int> right_res=right_left.first>right_right.first?right_right:right_left;
        
        pair<int,int> res=left_res.first>right_res.first?left_res:right_res;
        piles_map[index]=res;
        
        return res;
        
        
    }
    unordered_map<int,pair<int,int>> piles_map;
    int len;
    int get_key(int i,int j){
        return i*len+j;
    }
};

int main(){
    Solution mysolu;
    vector<int> piles={5,3,4,5};
    bool res=mysolu.stoneGame(piles);
    
    return 0;
}
