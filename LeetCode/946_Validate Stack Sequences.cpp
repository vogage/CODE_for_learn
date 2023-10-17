//
//  946_Validate Stack Sequences.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/5.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      
        stack<int> PushedSt;
        int TopIndex=0;
        for(int i=0;i<popped.size();i++){
            while((PushedSt.empty()||popped[i]!=PushedSt.top())&&TopIndex<pushed.size()){
                PushedSt.push(pushed[TopIndex]);
                TopIndex++;
            }
            if(!PushedSt.empty()&&popped[i]==PushedSt.top())PushedSt.pop();
            else return false;
        
        }
        return true;
    }

};

int main(){
    Solution mysolu;
//Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    vector<int> pushed={1,2,3,4,5};
    vector<int> popped={4,5,3,2,1};
    vector<int> pushed1={2,1,0};
    vector<int> popped1={0,1,2};
    bool res=mysolu.validateStackSequences(pushed1, popped1);
    return 0;
}
