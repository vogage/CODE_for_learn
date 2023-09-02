//
//  911_Online Election.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/24.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

struct Node{
    int person;
    int cnt;
    Node *pre;
    Node *next;
    Node(int p):person(p),cnt(1),pre(nullptr),next(nullptr){}
};


class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        NodeListMap[1]=new Node(-1);
        for(int i=0;i<persons.size()&&i<times.size();i++){
            if(NodeMap.find(persons[i])==NodeMap.end()){
                Node *temp=new Node(persons[i]);
                NodeMap[temp->person]=temp;
                temp->next=NodeListMap[1]->next;
                NodeListMap[1]->next=temp;
                temp->pre=NodeListMap[1];
            }else{
                Node *temp=NodeMap[persons[i]];
                temp->pre->next=temp->next;
                if(temp->next) temp->next->pre=temp->pre;
                temp->cnt++;
                if(NodeListMap.find(temp->cnt)==NodeListMap.end()) NodeListMap[temp->cnt]=new Node(-1);
                temp->next=NodeListMap[temp->cnt]->next;
                NodeListMap[temp->cnt]->next=temp;
                if(temp->next) temp->next->pre=temp;
                temp->pre=NodeListMap[temp->cnt];
            }
            auto it=NodeListMap.end();
            if(it!=NodeListMap.begin()) it--;
            TopSet[times[i]]=it->second->next->person;
        }
        
    }
    
    int q(int t) {
        auto it=TopSet.upper_bound(t);
        if(it!=TopSet.begin())it--;
        return it->second;
    }
private:
        

    unordered_map<int, Node*> NodeMap; //left:person right:person Node
    map<int,Node*> NodeListMap; //left:person right:person Node list
    map<int,int> TopSet;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
int main(){
//
//    ["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
//    [[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
    vector<int> persons={0, 1, 1, 0, 0, 1, 0};
    vector<int> times={0, 5, 10, 15, 20, 25, 30};
    TopVotedCandidate *obj=new TopVotedCandidate(persons, times);
    int res1=obj->q(3);
    int res2=obj->q(12);
    int res3=obj->q(25);
    int res4=obj->q(15);
    int res5=obj->q(24);
    int res6=obj->q(8);
    
    return 0;
    
}

