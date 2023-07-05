//
//  725_Split Linked List in Parts.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/29.
//

#include <stdio.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k,nullptr);
        int len=0;
        for(ListNode *temp=head;temp;temp=temp->next) len++;
        int n=len/k;
        int r=len%k;
        ListNode* pre=nullptr;
        ListNode *temp=head;
        for(int i=0;i<k&&temp;i++,r--){
            res[i]=temp;
            for(int j=0;j<n+(r>0);j++){
                pre=temp;
                temp=temp->next;
            }
            pre->next=nullptr;
        }
      

        
        return res;
        
    }
};

int main(){
    Solution mysolu;
    ListNode *root=new ListNode(1);
    ListNode *temp=root;
    for(int i=2;i<=10;i++){
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    
    ListNode *root2=new ListNode(1);
    temp=root2;
    for(int i=2;i<=3;i++){
        temp->next=new ListNode(i);
        temp=temp->next;
    }
    vector<ListNode*> res=mysolu.splitListToParts(root2, 5);
    return 0;
    
}
