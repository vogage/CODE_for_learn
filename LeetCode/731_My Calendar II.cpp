//
//  731_My Calendar II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/30.
//

#include <stdio.h>
#include "limits.h"
#include <vector>

using namespace std;
//731. My Calendar II
//A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

//0 <= start < end <= 109
//At most 1000 calls will be made to book.

struct Node{
    int begin;
    int end;
    int cnt;
    Node *next;
    //Node *pre;
    Node(int begin,int end,int clip,Node *next):begin(begin),end(end),cnt(clip),next(next){}
    
};


class MyCalendarTwo {
public:
    MyCalendarTwo() {
        root=new Node(-1,-1,1,nullptr);
        root->next=new Node(INT_MAX,INT_MAX,1,nullptr);
    }
    
    bool book(int start, int end) {
        Node *beginNode=root;
        
        while(beginNode->next&&beginNode->next->end<=start) beginNode=beginNode->next;
        Node *EndNode=beginNode;
        while(EndNode&&EndNode->begin<end) EndNode=EndNode->next;
        for(Node *temp=beginNode;temp!=EndNode;temp=temp->next){
            if(temp->end>start&&temp->begin<end&&temp->cnt) return false;
        }
        NodeInsert(beginNode,start,end);
        return true;
    }
private:
    void NodeInsert(Node* bn,int start,int end){
     
        Node *n=bn->next;
        if(start==n->begin){
            if(end==n->end){
                n->cnt=1;
            }else if(end<n->end){
                int NextEnd=n->end;
                n->end=end;
                n->cnt=1;
                n->next=new Node(end,NextEnd,0,n->next);
            }else{
                n->cnt=1;
                NodeInsert(n, n->end, end);
            }
        }else if(start<n->begin){
            if(end>n->begin){
                n->cnt=1;
                bn->next=new Node(start,n->begin,0,n);
                NodeInsert(bn->next, n->begin, end);
            }else{
                bn->next=new Node(start,end,0,bn->next);
            }
        }else{
            if(end>n->end){
                bn->next=new Node(n->begin,start,0,bn->next);
                n->begin=start;
                n->cnt=1;
                NodeInsert(n,n->end, end);
            }else{
                int NewEnd=n->end;
                n->end=start;
                n->next=new Node(start,end,1,n->next);
                n=n->next;
                n->next=new Node(end,NewEnd,0,n->next);
            }
        }
   
         
    }
//    for(Node* n=temp;n->begin<end;n=n->next){
//        int board1,board2,board3,board4;
//        if(start>n->begin){
//            board1=n->begin;
//            board2=start;
//        }else{
//            board1=start;
//            board2=n->begin;
//        }
//        if(end<n->end){
//            board3=end;
//            board4=n->end;
//        }else{
//            board3=n->end;
//            board4=end;
//        }
//        if(board1<board2){
//            n->next=new Node(board1,board2,0,n->next);
//            n=n->next;
//        }
//        if(board2<board3){
//            n->next=new Node(board2,board3,0,n->next);
//            n=n->next;
//        }
//        if(board3<board4){
//            n->next=new Node(board3,board4,0,n->next);
//            n=n->next;
//        }
//    }
    Node *root;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

int main(){
//    MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
//    myCalendarTwo.book(10, 20); // return True, The event can be booked.
//    myCalendarTwo.book(50, 60); // return True, The event can be booked.
//    myCalendarTwo.book(10, 40); // return True, The event can be double booked.
//    myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
//    myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
//    myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
    MyCalendarTwo *root=new MyCalendarTwo();
    bool res1=root->book(10, 20);
    bool res2=root->book(50, 60); // return True, The event can be booked.
    bool res3=root->book(10, 40); // return True, The event can be double booked.
    bool res4=root->book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
    bool res5=root->book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
    bool res6=root->book(25, 55);//true
    
    
//    ["MyCalendarTwo","book","book","book","book","book","book","book","book","book","book"]
//    [[],[24,40],[43,50],[27,43],[5,21],[30,40],[14,29],[3,19],[3,14],[25,39],[6,19]]
    //[null,true,true,true,true,false,false,true,false,false,false]
    
    MyCalendarTwo *root2=new MyCalendarTwo();
    bool res21=root2->book(24,40);
    bool res22=root2->book(43,50);
    bool res23=root2->book(27,43);
    bool res24=root2->book(5,21);
    bool res25=root2->book(30,40);
    bool res26=root2->book(14,29);
    
    
    //true,true,true,true,false, false,true,false,false,true
    //[22,29],[12,17],[20,27],[27,36],[24,31], [23,28],[47,50],[23,30],[24,29],[19,25],
    MyCalendarTwo *root3=new MyCalendarTwo();
    bool res31=root3->book(22,29);
    bool res32=root3->book(12,17);
    bool res33=root3->book(20,27);
    bool res34=root3->book(27,36);
    
    bool res35=root3->book(23,28);
    bool res36=root3->book(47,50);
    bool res37=root3->book(23,30);
    bool res38=root3->book(24,29);
    bool res39=root3->book(19,25);


    
    
    
    
    return 0;
}
