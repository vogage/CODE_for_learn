//
//  729_My Calendar I.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/30.
//

#include <stdio.h>
#include "limits.h"

struct Node{
    int begin;
    int end;
    Node *next;
    Node(int begin,int end,Node *next):begin(begin),end(end),next(next){}
};


class MyCalendar {
public:
    MyCalendar() {
        root=new Node(-1,-1,nullptr);
        root->next=new Node(INT_MAX,INT_MAX,nullptr);
    }
    
    bool book(int start, int end) {
        Node *temp=root;
        Node *pre=nullptr;
        
        while(temp&&temp->begin<end){
            pre=temp;
            temp=temp->next;
        }
        if(pre->end<=start){
            pre->next=new Node(start,end,pre->next);
            return  true;
        }else{
            return false;
        }
    }
private:
    Node * root;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

//MyCalendar myCalendar = new MyCalendar();
//myCalendar.book(10, 20); // return True
//myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
//myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.

int main(){
    MyCalendar *object=new MyCalendar();
    bool res1=object->book(10, 20);
    bool res2=object->book(15, 25);
    bool res3=object->book(20, 30);
    
    return 0;
}
