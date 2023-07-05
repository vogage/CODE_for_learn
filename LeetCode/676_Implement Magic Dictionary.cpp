//
//  676_Implement Magic Dictionary.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/24.
//

#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(int i=0;i<dictionary.size();i++){
            for(int j=0;j<dictionary[i].size();j++){
                string str=dictionary[i].substr(0,j)+dictionary[i].substr(j+1,dictionary[i].size()-j-1);
                WordMap[str].insert(dictionary[i]);
            }
        }
    }
    
    bool search(string searchWord) {
        for(int j=0;j<searchWord.size();j++){
            string str=searchWord.substr(0,j)+searchWord.substr(j+1,searchWord.size()-j-1);
            if(WordMap.find(str)!=WordMap.end()){
                if(WordMap[str].size()>1) return true;
                //compare the difference
              
                for(auto dicword:WordMap[str]){
                    int difcnt=0;
                    for(int k=0;k<searchWord.size();k++){
                        if(searchWord[k]!=dicword[k]) difcnt++;
                    }
                    if(difcnt==1) return true;
                }
            }
        }
        return false;
    }
    
    unordered_map<string, unordered_set<string>> WordMap;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main(){
    MagicDictionary *magicDictionary = new MagicDictionary();
    magicDictionary->buildDict({"hello", "leetcode"});
    bool res1=magicDictionary->search("hello"); // return False
    bool res2=magicDictionary->search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
    bool res3=magicDictionary->search("hell"); // return False
    bool res4=magicDictionary->search("leetcoded"); // return False
    return 0;
}
