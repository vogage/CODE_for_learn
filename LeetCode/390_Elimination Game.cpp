//
//  390_Elimination Game.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/19.
//

#include <stdio.h>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        bool isfront=true;
        return help(n,isfront);
    }
    int help(int n,bool isfront){
        if(n==1)return 1;
        //judge the remaining num is odd?
        if(n%2==1){
            //judge the direction is from front or reversed back?
            if(isfront){
                return 2*help((n-1)/2,false);
            }else{
                return 2*help((n-1)/2,true);
            }
        }else{
            //I think it maynot influence the odd situation ,but may influence the even case
            if(isfront){
                return 2*help(n/2,false);
            }else{
                return 2*help(n/2,true)-1;
            }
        }
    }
};


class Solution2 {
public:
    int lastRemaining(int n) {
        stack<int> num_st1;
        
        for(int end=n;end>=1;end--) num_st1.push(end);
        while(num_st1.size()>1){
            stack<int> num_st2;
            int cout=0;
            while(!num_st1.empty()){
                cout++;
                if(cout%2==0)num_st2.push(num_st1.top());
                num_st1.pop();
            }
            num_st1=num_st2;
            
            
        }
        return num_st1.top();
    }
};

int main(){
    Solution mysolu;
    int n=9;
    int res=mysolu.lastRemaining(16);
    return 0;
}
