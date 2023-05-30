//
//  386_Lexicographical Numbers.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/13.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Trie{
private:
    // 定义节点
    bool flag;
    vector<Trie*> next;
public:
    Trie(){
        this->next =vector<Trie*>(10,nullptr);
        flag=false;
       
        
    }    // 构造函数

    void insert(int pre){   // 插入
        Trie* node = this;
        vector<int> input;
        while(pre){
            int tail=pre%10;
            pre=pre/10;
            input.push_back(tail);
        }
        for(int i=input.size()-1;i>=0;i--){
            
            if(node->next[input[i]]==nullptr){
                node->next[input[i]] = new Trie();
            }
            node = node->next[input[i]];
        }
        node->flag = true;  // 单词串的尾节点为true
    }
    
    vector<int> get_order(){
        this->next[0]=new Trie();
        
        vector<int> res=get_sub(this,0);
        
         

        return res;
    }
    
    vector<int> get_sub(Trie *t,int pre){
        vector<int> res;
        pre=pre*10;
        //if(t->next[pre]) res.push_back(pre);
        for(int i=0;i<t->next.size();i++){
            if(t->next[i]==nullptr)break;
            if(t->next[i]->flag){res.push_back(pre+i);}
            if(t->next[i]->next[0]!=nullptr){
                vector<int> res1=get_sub(t->next[i],pre+i);
                res.insert(res.end(), res1.begin(),res1.end());
            }
            
        }
        return res;
    }


    
};


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        Trie mytree;
        
        for(int i=1;i<=n;i++){
            mytree.insert(i);
        }
        return mytree.get_order();
    }
};

int main(){
    Solution mysolu;
    int n=2;
    vector<int> res=mysolu.lexicalOrder(n);
    return 0;
}
