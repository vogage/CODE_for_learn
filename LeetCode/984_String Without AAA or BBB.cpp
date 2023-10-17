//
//  984_String Without AAA or BBB.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <string>

using namespace std;

struct Node{
    char c;
    Node* next;
    Node(char c):c(c),next(nullptr){}
    Node(char c,Node* p):c(c),next(p){}
};

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        pair<char,int> p1;
        pair<char,int> p2;
        if(a>b) {
            p1.first='a';
            p1.second=a;
            p2.first='b';
            p2.second=b;
        }else{
            p1.first='b';
            p1.second=b;
            p2.first='a';
            p2.second=a;
        }
        //construct the list
        Node *root=new Node('r');
        Node *temp=root;
        for(int i=0;i<p1.second;i++){
            temp->next=new Node(p1.first);
            temp=temp->next;
        }
        //insert the second char
        temp=root->next;
        for(int i=1;i<p1.second;i++){
            if(i%2==0){
                temp->next=new Node(p2.first,temp->next);
                p2.second--;
                temp=temp->next;
            }
            temp=temp->next;
        }
        //insert the remain char
        temp=root;
        while(temp->next&&p2.second){
            if(temp->c==p1.first&&temp->next->c==p1.first){
                temp->next=new Node(p2.first,temp->next);
                temp=temp->next;
                p2.second--;
            }
            temp=temp->next;
        }
        if(p2.second) root->next=new Node(p2.first,root->next);
        string res="";
        temp=root;
        while(temp->next){
            temp=temp->next;
            res+=temp->c;
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    int a = 1;
    int b = 1;
    string res=mysolu.strWithout3a3b(a, b);
    return 0;
}
