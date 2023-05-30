//
//  375_Guess Number Higher or Lower II.cpp
//  leetcode
//
//  Created by qiandehou on 2021/5/4.
//

#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;




//We are playing the Guessing Game. The game will work as follows:
//
//I pick a number between 1 and n.
//You guess a number.
//If you guess the right number, you win the game.
//If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
//Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.
//Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


//class Solution {
//public:
//    int getMoneyAmount(int n) {
//        int res=0;
//        subget(1,n,0,res);
//        return res;
//
//    }
//    void subget(int begin,int end,int temp,int & res){
//        int mid=(begin+end)/2;
//        int dif=end-begin+1;
//        if(dif==3||dif==2){
//            temp=mid+temp;
//            res=max(res,temp);
//            return;
//        }
//
//        if(dif==1)return;
//        int left=1;
//        int right=1;
//        int sum=1;
//        while(sum<dif){
//            sum=sum+left+right;
//            left=left*2;
//            right=right*2;
//        }
//        int div=0;
//        if(dif-left<right/2){
//            div=end-right/2+1;
//        }else{
//            div=end-right+1;
//        }
//
//        subget(begin, div-1,temp+div,res);
//        subget(div+1, end,temp+div,res);
//
//
//
//    }
//};

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> t(n+1,vector<int>(n+1,0));
       
        return DP(t, 1, n);
    }
    
    int DP(vector<vector<int>>& t, int s, int e){
        if(s >= e) return 0;
        if(t[s][e] != 0) return t[s][e];
        int res = INT_MAX;
        for(int x=s; x<=e; x++){
            int tmp = x + max(DP(t, s, x-1), DP(t, x+1, e));
            res=min(res,tmp);
        }
        t[s][e] = res;
        return res;
    }
};


//class Solution2 {
//public:
//    int getMoneyAmount(int n) {
//       
//    }
//    
//    
//};

int main(){
    
    
    Solution mysolu;
    int res=mysolu.getMoneyAmount(10);
    return 0;
}
