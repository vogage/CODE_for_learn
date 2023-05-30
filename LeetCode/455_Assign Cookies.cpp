//
//  455_Assign Cookies.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/12/2.
//

#include <stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end(),less<int>());
        sort(s.begin(),s.end(),less<int>());
        int cnt=0;
        int cookie_index=0;
        int child_index=0;
        while(child_index<g.size()&&cookie_index<s.size()){
            if(g[child_index]<=s[cookie_index]){
                cookie_index++;
                child_index++;
                cnt++;
            }else{
                cookie_index++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution mysolu;
    vector<int> g={1,2,3};
    vector<int> s={1,1};
    
    int res=mysolu.findContentChildren(g, s);
    return 0;
}
