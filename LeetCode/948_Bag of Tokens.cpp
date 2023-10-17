//
//  948_Bag of Tokens.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/7.
//

#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int begin=0,end=tokens.size()-1;
        int score=0;
        while(begin<=end){
            if(tokens[begin]<=power){
                score++;
                power-=tokens[begin];
                begin++;
            }else if(score>0){
                score--;
                power+=tokens[end];
                end--;
            }
        }
        return score;
        
        
    }
};


int main(){
    Solution mysolu;
//Input: tokens = [100,200,300,400], power = 200
    vector<int> tokens={100,200,300,400};
    int power=200;
    vector<int> tokens1={100,200};
    int power1=150;
    int res=mysolu.bagOfTokensScore(tokens1, power1);
    return  0;
}
