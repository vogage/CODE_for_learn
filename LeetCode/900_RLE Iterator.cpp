//
//  900_RLE Iterator.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

struct Node{
    int val;
    int num;
    Node *next;
    Node(int n,int v):val(v),num(n){}
};

class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) {
        root=new Node(-1,-1);
        Node *temp=root;
        for(int i=0;i<encoding.size();i=i+2){
            temp->next=new Node(encoding[i],encoding[i+1]);
            temp=temp->next;
        }
        temp->next=nullptr;
    }
    
    int next(int n) {
        Node *temp=root;
        while(temp->next&&temp->next->num<n){
            n=n-temp->next->num;
            temp->next->num=0;
            temp=temp->next;
        }
        if(temp->next){
            temp->next->num-=n;
            return  temp->next->val;
        }else{
            return -1;
        }
    }
private:
    Node *root;
};
/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

int main(){
    
//    Input
//    ["RLEIterator", "next", "next", "next", "next"]
//    [[[3, 8, 0, 9, 2, 5]], [2], [1], [1], [2]]
//    Output
//    [null, 8, 8, 5, -1]
    vector<int> input={3, 8, 0, 9, 2, 5};
    RLEIterator *obj=new RLEIterator(input);
    int res1=obj->next(2);
    int res2=obj->next(1);
    int res3=obj->next(1);
    int res4=obj->next(2);
    
    
    //[[[784,303,477,583,909,505]],[130],[333],[238],[87],[301],[276]]
    vector<int> input1={784,303,477,583,909,505};
    RLEIterator *obj1=new RLEIterator(input1);
    int res11=obj1->next(130);
    int res12=obj1->next(333);
    int res13=obj1->next(238);
    int res14=obj1->next(87);
    int res15=obj1->next(301);
    int res16=obj1->next(276);
    return 0;
    
}
