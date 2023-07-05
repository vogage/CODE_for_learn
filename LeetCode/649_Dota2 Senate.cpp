//
//  649_Dota2 Senate.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> Rque;
        queue<int> Dque;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') Rque.push(i);
            else Dque.push(i);
        }
        while(!Rque.empty()&&!Dque.empty()){
            if(Rque.front()<Dque.front()){
                int temp=Rque.front();
                Rque.push(temp+senate.size());
            }else{
                int temp=Dque.front();
                Dque.push(temp+senate.size());
            }
            Rque.pop();
            Dque.pop();
        }
        if(Rque.empty())return "Dire";
        else return "Radiant";
    }
};


int main(){
    Solution mysolu;
    string senate="RDD";
    string res=mysolu.predictPartyVictory(senate);
    return 0;
}
