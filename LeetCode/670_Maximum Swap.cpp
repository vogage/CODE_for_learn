//
//  670_Maximum Swap.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/21.
//

#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;


//template <typename T>
//class cmp
//{
//public:
//    //重载 () 运算符
//    bool operator()(T a, T b)
//    {
//        return a > b;
//    }
//};

//class Compare {
//public:
//    bool operator()(PII below, PII above)
//    {
//        if (below.first > above.first) {
//            return true;
//        }
//        else if (below.first == above.first
//                 && below.second < above.second) {
//            return true;
//        }
//
//        return false;
//    }
//};

//
////priority_queue<PII, vector<PII>, Compare> ds;
//class cmp{
//public:
//    bool operator()(pair<int,int> p1,pair<int,int> p2){
//        if(p1.first>p2.first) return false;
//        else if(p1.first==p2.first) return p1.second<p2.second;
//        return true;
//    }
//};

class Solution {
public:
    
    
    int maximumSwap(int num) {
        //priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        string str=to_string(num);
        string str2=str;
        sort(str2.begin(),str2.end(),greater<char>());
        unordered_map<char, vector<int>> IndexMap;
        for(int i=str.size()-1;i>=0;i--) IndexMap[str[i]].push_back(i);
        for(int i=0;i<str.size();i++){
            if(str[i]==str2[i]) continue;
            int index=IndexMap[str2[i]][0];
            char temp=str[i];
            str[i]=str2[i];
            str[index]=temp;
            return stoi(str);
        }
        return stoi(str);
    }
};

int main(){
    Solution mysolu;
    int num=9836828;
    int res=mysolu.maximumSwap(num);
    return 0;
}
