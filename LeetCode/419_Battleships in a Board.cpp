//
//  419_Battleships in a Board.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/13.
//

#include <stdio.h>
#include<vector>

using namespace std;


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        if(n==0)return 0;
        int m=board[0].size();
        vector<bool> flag(m,false);
        return Cal(board,flag);
    }
private:
    int Cal(vector<vector<char>>& board,vector<bool>& flag){
        int res=0;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    if((j==0||!flag[j-1])&&(!flag[j])) res++;
                    flag[j]=true;
                }else{
                    flag[j]=false;
                }
            }
        }
        return res;
    }
};


int main(){
    vector<vector<char>> board={{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}};
    Solution mysolu;
    int res=mysolu.countBattleships(board);
    return 0;
}
