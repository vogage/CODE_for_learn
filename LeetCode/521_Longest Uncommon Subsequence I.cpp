//
//  521_Longest Uncommon Subsequence I.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/8.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size()!=b.size()) return max(a.size(),b.size());
        int i=0,j=0;
        while(i<a.size()){
            if(a[i]==b[j]) {
                i++;j++;
            }else{
                return -1;
            }
        }
        return a.size();
    }
};


int main(){
    Solution mysolu;
    string a="abc";
    string b="aebdc";
    string a1="aefawfawfawfaw";
    string b1="aefawfeawfwafwaef";
    string a2="horbxeemlgqpqbujbdagizcfairalg";
    string b2="iwvtgyojrfhyzgyzeikqagpfjoaeen";
    int res=mysolu.findLUSlength(a2, b2);
    
    return 0;
}
