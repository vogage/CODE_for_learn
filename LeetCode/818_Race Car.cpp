//
//  818_Race Car.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/13.
//

#include <stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>

using namespace std;
class Solution {
public:
    int racecar(int target) {
        if(target==0)return -1;
        vector<int> dp(target+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=target;i++){
            dp[i]=INT_MAX;
            int m=1;
            int j=1;
            for(;j<i;j=(1<<++m)-1){
                int p=0;
                for(int q=0;q<j;q=(1<<++p)-1){
                    dp[i]=min(dp[i],m+1+p+1+dp[i-(j-q)]);
                }
            }
            dp[i]=min(dp[i],j==i?m:m+1+dp[j-i]);
        }
        return dp[target];
        
    }
    
};

class Solution2 {
public:
    int racecar(int target) {
        //dp[i] 表示从速度1，位置0开始到位置i到步数
        dp=vector<int>(target*2,-1);
        dp[0]=0;
        dp[1]=1;
        helper(target);
        return dp[target];
        
    }
private:
    int helper(int target){
        if(dp[target]>0)return dp[target];
        int m=1;
        int j=1;
        dp[target]=INT_MAX;
        
        for(;j<target;j=(1<<++m)-1){
            for(int q=0,p=0;p<j;p=(1<<++q)-1){
                dp[target]=min(dp[target],m+1+q+1+helper(target-(j-p)));
            }
        }
        if(j==target) dp[target]=m;
        else dp[target]=min(dp[target],m+1+helper(j-target));
        return dp[target];
    }
    vector<int> dp;
    
};


class Solution1 {
public:
    int racecar(int target) {
        pair<int,int> p({0,1});
        queue<pair<int,int>> state_que;
        unordered_set<string> visited;
        visited.insert(to_string(p.first)+" "+to_string(p.second));
        state_que.push(p);
        int level=0;
        while(!state_que.empty()){
            //这种方式真的可以么？？
            //测试之后发现并不可以，还是要提前进行赋值
            int cout=state_que.size();
            for(int i=0;i<cout;i++){
                pair<int,int> temp_state=state_que.front();
                state_que.pop();
                int pos=temp_state.first;
                int speed=temp_state.second;
                if(pos==target)return level;
                
                //1. move on
                pair<int,int> new_state1;
                new_state1.first=pos+speed;
                new_state1.second=speed*2;
                
            //AddressSanitizer: global-buffer-overflow on address
            //LeetCode 里面在int型上不加to_string()函数，会出现内存非法访问报错，这个在数组访问越界上也会出现
                string state_key1=to_string(new_state1.first)+" "+to_string(new_state1.second);
                
                if(visited.find(state_key1)==visited.end()){
                    if(new_state1.first<(target<<1)&&new_state1.first>0){
                        state_que.push(new_state1);
                        visited.insert(state_key1);
                    }
                }
                
                // Reverse
                pair<int,int> new_state2;
                new_state2.first=pos;
                new_state2.second=speed>0?-1:1;
                
                string state_key2=to_string(new_state2.first)+" "+to_string(new_state2.second);
                if(visited.find(state_key2)==visited.end()){
                    if(new_state2.first<(target<<1)&&new_state2.first>0){
                        state_que.push(new_state2);
                        visited.insert(state_key2);
                    }
                }
                
                
            }
            level++;
            
        }
        return -1;
    }

};

int main(){
    Solution mysolu;
    int target=5;
    int res=mysolu.racecar(target);
    return 0;
}
