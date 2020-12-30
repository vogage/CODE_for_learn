#include<stdio.h>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        //put one
        int res =INT_MAX;
        unordered_map<char,int> hand_set;
        int total_hand = 0;
        for (auto c : hand) { hand_set[c]++; total_hand++; }
        dfs(board, hand_set, 0, res,total_hand);
        return res==INT_MAX?-1:res;

    }

    void dfs(string board, unordered_map<char,int>& hand_set, int temp, int& res,int &total_hand) {
        if (board.size() == 0) {
            res = min(res, temp); return;
        }
        if (temp > total_hand)return;
        for (int i = 0; i < board.size(); ) {
            if (i+1<board.size()&&board[i] == board[i + 1]) {
         
                unordered_map<char,int>::iterator it = hand_set.find(board[i]);                
           
                if (it != hand_set.end()&&it->second!=0) {
                    it->second--;
                     string left = board.substr(0, i);
                     string right = board.substr(i, board.size() - i);
                    string new_board = left + board[i] + right;
                    refresh(new_board, i);
                    dfs(new_board, hand_set, temp + 1, res,total_hand);
                   
                    if (i + 3 < board.size() && board[i + 2]  == board[i + 3]) {
                        char target = board[i + 2];
                        int index = i + 4;
                        for (; index < board.size(); index++) {
                            if (board[index] == target) break;
                        }
                        string left = board.substr(0, index+1);
                        string right = board.substr(index, board.size() - index-1);
                        string new_board2 = left + board[i] + right;
                        dfs(new_board2, hand_set, temp + 1, res, total_hand);

                    }
                    it->second++;
                }
                i++;
                i++;
            }
            else {
                unordered_map<char, int>::iterator it = hand_set.find(board[i]);
                string left = board.substr(0, i);
                string right = board.substr(i, board.size() - i);
                if (it != hand_set.end() && it->second > 1) {
                    it->second=it->second-2;

                    string new_board = left + board[i] + board[i]+right;
                    refresh(new_board, i);
                    dfs(new_board, hand_set, temp + 2, res, total_hand);
                    it->second=it->second+2;
                }
                i++;
            }
        }


    }


    void refresh(string& board, int index) {
        char c = board[index];
        int left = index;

        int right = index + 1;
        while (left > 0 && board[left-1] == c) {
            left--;
        }
        while (right < board.size() && board[right] == c) {
            right++;
        }
        if (right-left > 2) {
            string left_str = board.substr(0, left);
            string right_str = board.substr(right, board.size() - right );
            board = left_str + right_str;
            refresh(board,left);
        }
        return;
        
    }
   
    
};

int main() {
    string board = "WWRRBBWW";
    string hand = "WRBRW";
    string board1 = "WRRBBW";
    string hand1 = "RB";
    string board2 = "G";
    string hand2 = "GGGGG";
    string board3 = "RRWWRRBBRR";
    string hand3 = "WB";
    Solution mysolu;
    int res = mysolu.findMinStep(board3, hand3);
    return 0;
}

