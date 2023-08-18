//
//  855_Exam Room.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/9.
//

#include <stdio.h>
#include <map>
#include <set>

using namespace std;

struct Node{
    int val;
    Node *next;
    Node():val(-1),next(nullptr){}
    Node(int v,Node* n):val(v),next(n){}
};

class ExamRoom {
public:
    ExamRoom(int n) {
        root=new Node();
        sz=n-1;
    }
    
    int seat() {
        if(!root->next){
            root->next=new Node(0,nullptr);
            return 0;
        }
        Node *temp=root->next;
        pair<int,pair<int,Node*>> candi(0,pair<int,Node*>(temp->val,root)); //seat index and the distance to the first seat
        while(temp->next){
            int dist=(temp->next->val-temp->val)/2;
            if(dist>candi.second.first){
                candi.first=temp->val+dist;
                candi.second.first=dist;
                candi.second.second=temp;
            }
            temp=temp->next;
        }
        //compare with the end index seat
        int dist=sz-temp->val;
        if(candi.second.first<dist){
            candi.first=sz;
            candi.second.first=dist;
            candi.second.second=temp;
        }
        candi.second.second->next=new Node(candi.first,candi.second.second->next);
        return candi.first;
       
    }
    
    void leave(int p) {
        Node* temp=root;
        while(temp->next&&temp->next->val!=p) temp=temp->next;
        if(temp->next) temp->next=temp->next->next;
    }
private:
    Node* root;
    int sz;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */


int main(){
//    ["ExamRoom","seat","seat","seat","leave","leave","seat","seat","seat","seat","seat","seat","seat","seat","seat","leave"]
//    [[10],[],[],[],[0],[4],[],[],[],[],[],[],[],[],[],[0]]
    ExamRoom *obj=new ExamRoom(10);
    obj->seat();
    obj->seat();
    obj->seat();
    obj->leave(0);
    obj->leave(4);
    obj->seat();
    obj->seat();
    
    return 0;
}
