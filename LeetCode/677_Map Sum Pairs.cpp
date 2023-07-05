//
//  677_Map Sum Pairs.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/25.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Tire{
    int val;
    vector<Tire*> sons;
    Tire():val(0),sons(vector<Tire*>(26,nullptr)),isend(false),strval(0){}
    bool isend;
    int strval;
};

class MapSum {
public:
    MapSum() {
        root=new Tire();
    }
    
    void insert(string key, int val) {
        stack<Tire*> st;
        Tire *temp=root;
        for(int i=0;i<key.size();i++){
            int index=key[i]-'a';
            if(!temp->sons[index]){
                temp->sons[index]=new Tire();
            }
            st.push(temp);
            temp=temp->sons[index];
        }
        st.push(temp);
        int val2=0;
        if(temp->isend){
            val2=val-temp->strval;
        }else{
            val2=val;
        }
        temp->isend=true;
        temp->strval=val;
        while(!st.empty()){
            Tire* temp2=st.top();
            st.pop();
            temp2->val+=val2;
        }
    }
    
    int sum(string prefix) {
        Tire *temp=root;
        for(int i=0;i<prefix.size();i++){
            temp=temp->sons[prefix[i]-'a'];
            if(!temp)return 0;
        }
        return temp->val;
    }
private:
    Tire* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(){
//    MapSum mapSum = new MapSum();
//    mapSum.insert("apple", 3);
//    mapSum.sum("ap");           // return 3 (apple = 3)
//    mapSum.insert("app", 2);
//    mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
    MapSum *mapSum= new MapSum();
    mapSum->insert("apple",3);
    mapSum->sum("ap");
    mapSum->insert("app",2);
    mapSum->insert("apple",5);
    mapSum->insert("apple",1);
    int res=mapSum->sum("apple");
    return 0;
    
    
//    ["MapSum","insert","sum","insert","insert","sum"]
//    [[],["apple",3],["ap"],["app",2],["apple",2],["ap"]]
    
//    [[],["apple",3],["ap"],["app",2],["ap"],["apple",5],["apple",1],["apple"]]
}
