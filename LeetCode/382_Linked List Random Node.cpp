//
//  382_Linked List Random Node.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/13.
//

#include <stdio.h>

//Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//
//
//
//Example 1:
//
//
//Input
//["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
//[[[1, 2, 3]], [], [], [], [], []]
//Output
//[null, 1, 3, 2, 2, 3]
//
//Explanation
//Solution solution = new Solution([1, 2, 3]);
//solution.getRandom(); // return 1
//solution.getRandom(); // return 3
//solution.getRandom(); // return 2
//solution.getRandom(); // return 2
//solution.getRandom(); // return 3
//// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

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

#include<stdlib.h>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
    
    
class Solution2 {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution2(ListNode* head) {
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        return 0;
    }
};


class Solution {
public:

    ListNode* u;
    Solution(ListNode* head) {
        u = head;
    }
    
    int getRandom() {
        int res, len = 1;
        ListNode* v = u;
        while(v){
            int rand_num=rand();
            if(rand_num % len == 0){
                res = v->val;
            }
            len++;
            v = v->next;
        }
        return res;
    }
};



/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main(){
    ListNode* head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    Solution mysolu(head);
    int res=mysolu.getRandom();
    return 0;
}
