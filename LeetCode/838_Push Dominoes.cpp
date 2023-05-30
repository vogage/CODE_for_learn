//
//  838_Push Dominoes.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/22.
//

#include <stdio.h>
#include<string>
#include<unordered_set>
#include<queue>

using namespace std;
class Solution2 {
public:
    string pushDominoes(string dominoes) {
        string d="L"+dominoes+"R";
        
    }
    
};

class Solution2 {
public:
    string pushDominoes(string dominoes) {
        queue<int> left_index;
        queue<int> right_index;
        unordered_set<int> visited;
        for(int i=0;i<dominoes.size();i++){
            if(dominoes[i]=='L') {left_index.push(i); visited.insert(i);}
            if(dominoes[i]=='R'){right_index.push(i); visited.insert(i);}
           
            
        }
        while(!(left_index.empty()&&right_index.empty())){
            string next_dominoes=dominoes;
            int n_left=left_index.size();
            int n_right=right_index.size();
            for(int i=0;i<n_left;i++){
                int index=left_index.front();
                left_index.pop();
                if(index-1>=0&&dominoes[index-1]=='.'){
                    if(index-2<0||dominoes[index-2]!='R'){
                        next_dominoes[index-1]='L';
                        if(visited.find(index-1)==visited.end())left_index.push(index-1);
                    }
                }
            }
            for(int i=0;i<n_right;i++){
                int index=right_index.front();
                right_index.pop();
                if(index+1<dominoes.size()&&dominoes[index+1]=='.'){
                    if(index+2>=dominoes.size()||dominoes[index+2]!='L'){
                        next_dominoes[index+1]='R';
                        if(visited.find(index+1)==visited.end())right_index.push(index+1);
                    }
                }
            }
            dominoes=next_dominoes;
        }
        return dominoes;
    }


};


int main(){
    string dominoes = ".L.R...LR..L..";
    string dominoes1="RL";
    string dominoes2="..R..";
    Solution mysolu;
    string res=mysolu.pushDominoes(dominoes2);
    return 0;
}
