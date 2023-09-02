//
//  893_Groups of Special-Equivalent Strings.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/21.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>
//893. Groups of Special-Equivalent Strings

using namespace std;

struct MyWord{
    unordered_map<char, int> OddPart;
    unordered_map<char, int> EvenPart;
    MyWord(string str){
        for(int i=0;i<str.size();i++){
            if(i%2==1){
                OddPart[str[i]]++;
            }else{
                EvenPart[str[i]]++;
            }
        }
    }
};

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        vector<MyWord> res;
        res.push_back(MyWord(words[0]));
        for(auto str:words){
            MywordInsert(res,str);
        }
        return res.size();
    }
private:
    void MywordInsert(vector<MyWord>& res,string& str){
        MyWord temp(str);
        bool ExistFlag=false;
        for(int i=0;i<res.size();i++){
            bool isSameWord=true;
            for(auto m:temp.OddPart){
                if(res[i].OddPart.find(m.first)==res[i].OddPart.end()||res[i].OddPart[m.first]!=m.second){
                    isSameWord=false;break;
                }
            }
            for(auto m:temp.EvenPart){
                if(res[i].EvenPart.find(m.first)==res[i].EvenPart.end()||res[i].EvenPart[m.first]!=m.second){
                    isSameWord=false;break;
                }
            }
            if(isSameWord)return;
        }
        res.push_back(temp);
    }
};

int main(){
    Solution mysolu;
    vector<string> words={"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    int res=mysolu.numSpecialEquivGroups(words);
    return 0;
}
