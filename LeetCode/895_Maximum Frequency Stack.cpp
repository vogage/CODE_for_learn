//
//  895_Maximum Frequency Stack.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/25.
//

#include <stdio.h>
#include <unordered_map>
#include <map>

using namespace std;
//Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.
//
//Implement the FreqStack class:
//
//FreqStack() constructs an empty frequency stack.
//void push(int val) pushes an integer val onto the top of the stack.
//int pop() removes and returns the most frequent element in the stack.
//If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.

struct Node{
    int val;
    int cnt;
    Node *pre;
    Node *next;
    Node(int v,int c):val(v),cnt(c),pre(nullptr),next(nullptr){}
};



class FreqStack {
public:
    FreqStack() {
        LevelMap[1]=new Node(-1,-1);
    }
    
    void push(int val) {
        int rep=++NodeCntMap[val];
        Node *temp=new Node(val,rep);
        if(LevelMap.find(rep)==LevelMap.end()) LevelMap[rep]=new Node(-1,-1);
        insert(temp);
    }
    
    int pop() {
        auto it=LevelMap.end();
        if(it!=LevelMap.begin()) it--;
        Node* temp=it->second->next;
        remove(temp);
        NodeCntMap[temp->val]--;
        if(!LevelMap[temp->cnt]->next){
            LevelMap.erase(temp->cnt);
        }
        return temp->val;
    }
private:
    void insert(Node *temp){
        temp->next=LevelMap[temp->cnt]->next;
        if(temp->next) temp->next->pre=temp;
        LevelMap[temp->cnt]->next=temp;
        temp->pre=LevelMap[temp->cnt];
    }
    void remove(Node *temp){
        temp->pre->next=temp->next;
        if(temp->next) temp->next->pre=temp->pre;
    }
private:
    unordered_map<int,int> NodeCntMap;
    map<int,Node*> LevelMap;
    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

//["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
//[[], [5], [7], [5], [7], [4], [5], [], [], [], []]

int main(){
    FreqStack *obj=new FreqStack();
    obj->push(5);
    obj->push(7);
    obj->push(5);
    obj->push(7);
    obj->push(4);
    obj->push(5);
    int res1=obj->pop();
    int res2=obj->pop();
    int res3=obj->pop();
    int res4=obj->pop();
    
    
//    ["FreqStack","push","push","push","push","pop", "pop", "push", "push", "push", "pop", "pop", "pop"]
//    [[],[1], [1], [1], [2], [], [], [2], [2], [1], [], [], []]
    FreqStack *obj1=new FreqStack();
    obj1->push(1);
    obj1->push(1);
    obj1->push(1);
    obj1->push(2);
    int res11=obj->pop();
    int res12=obj->pop();
    obj1->push(2);
    obj1->push(2);
    obj1->push(1);
    int res13=obj->pop();
    int res14=obj->pop();
    int res15=obj->pop();
    return 0;
}
