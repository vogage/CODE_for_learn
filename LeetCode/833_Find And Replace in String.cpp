//
//  833_Find And Replace in String.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/1.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct Node{
    int i;
    string source;
    string target;
    Node(int i,string s,string t):i(i),source(s),target(t){}
};

bool cmp(Node &n1,Node& n2){
    return n1.i<n2.i;
}

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        vector<Node> NodeVec;
        for(int i=0;i<indices.size()&&i<sources.size()&&i<targets.size();i++){
            NodeVec.push_back(Node(indices[i],sources[i],targets[i]));
        }
        sort(NodeVec.begin(),NodeVec.end(),cmp);
        vector<string> strvec;
        strvec.push_back(s.substr(0,NodeVec[0].i));
        for(int i=0;i<indices.size()-1;i++){
            int index=NodeVec[i].i;
            int n=NodeVec[i].source.size();
            if(s.substr(index,n)==NodeVec[i].source&&n<=NodeVec[i+1].i-index){
                strvec.push_back(NodeVec[i].target);
                int interval=NodeVec[i+1].i-index-n;
                if(interval>0) strvec.push_back(s.substr(index+n,interval));
            }else{
                strvec.push_back(s.substr(index,NodeVec[i+1].i-index));
            }
        }
        int interval=s.size()-NodeVec.back().i-NodeVec.back().source.size();
        if(interval>=0&&s.substr(NodeVec.back().i,NodeVec.back().source.size())==NodeVec.back().source){
                strvec.push_back(NodeVec.back().target);
                strvec.push_back(s.substr(NodeVec.back().i+NodeVec.back().source.size(),interval));
                
        }else{
            strvec.push_back(s.substr(NodeVec.back().i,s.size()-NodeVec.back().i));
        }
        string res="";
        for(int i=0;i<strvec.size();i++) res+=strvec[i];
        return res;
    }
};

int main(){
    Solution mysolu;
    //Input: s = "abcd", indices = [0, 2], sources = ["a", "cd"], targets = ["eee", "ffff"]
    string s = "abcd";
    vector<int> indices = {0, 2};
    vector<string> sources={"a","cd"};
    vector<string> targets={"eee", "ffff"};
    
    string s1="vmokgggqzp";
    vector<int>indices1 ={3,5,1};
    vector<string>sources1 ={"kg","ggq","mo"};
    vector<string>targets1 ={"s","so","bfr"};
    
    string s2 ="jjievdtjfb";
    vector<int> indices2 ={4,6,1};
    vector<string> sources2 ={"md","tjgb","jf"};
    vector<string> targets2 ={"foe","oov","e"};
    
    string res=mysolu.findReplaceString(s2, indices2, sources2, targets2);
    return 0;
}
