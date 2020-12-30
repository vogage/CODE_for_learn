#include<stdio.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head)return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* b1 = head;
        ListNode* b2 = head->next;
        while (p1->next && p1->next->next) {
            
            p1->next = p1->next->next;
            p1 = p1->next;
            if(p2->next->next) {
             
                p2->next = p2->next->next; 
                p2 = p2->next;
            }
        }
        if (p2->next) p2->next = nullptr;
        if (p1->next) p1->next= nullptr;
        p1->next = b2;
        return b1;

    }
};

int main() {
    ListNode* head =new  ListNode(1);
    ListNode* p = head;
    p->next = new ListNode(2);
    p = p->next;
    p->next = new ListNode(3);
    p = p->next;
    p->next = new ListNode(4);
    p = p->next;
    p->next = new ListNode(5);
    Solution mysolu;
 //   ListNode* res = mysolu.oddEvenList(head);

//Input: 2->1->3->5->6->4->7->NULL
//Output : 2->3->6->7->1->5->4->NULL
ListNode * head2 = new ListNode(2);
p = head2;
p->next = new ListNode(1);
p = p->next;
p->next = new ListNode(3);
p = p->next;
p->next = new ListNode(5);
p = p->next;
p->next = new ListNode(6);
p = p->next;
p->next = new ListNode(4);
p = p->next;
p->next = new ListNode(7);
//ListNode* res2 = mysolu.oddEvenList(head2);


ListNode * head4 = new ListNode(2);
p = head2;
p->next = new ListNode(1);
p = p->next;
p->next = new ListNode(3);
p = p->next;
p->next = new ListNode(5);
p = p->next;
p->next = new ListNode(6);
p = p->next;
p->next = new ListNode(4);
p = p->next;
p->next = new ListNode(7);
//ListNode* res2 = mysolu.oddEvenList(head2);

//[1, 2, 3, 4, 5, 6, 7, 8]
ListNode* head3 = new ListNode(1);
p = head3;
p->next = new ListNode(2);
p = p->next;
p->next = new ListNode(3);
p = p->next;
p->next = new ListNode(4);
p = p->next;
p->next = new ListNode(5);
p = p->next;
p->next = new ListNode(6);
p = p->next;
p->next = new ListNode(7);
p = p->next;
p->next = new ListNode(8);
ListNode* res2 = mysolu.oddEvenList(head3);
 return 0;
}