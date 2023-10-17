//
//  1019_Next Greater Node In Linked List.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/28.
//

#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
    int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> NodeVec;
        while(head){
            NodeVec.push_back(head->val);
            head=head->next;
        }
        stack<int> st;
        vector<int> res(NodeVec.size(),0);
        for(int i=NodeVec.size()-1;i>=0;i--){
            while(!st.empty()&&NodeVec[i]>st.top())st.pop();
            if(st.empty()) res[i]=NodeVec[i];
            else res[i]=st.top();
            st.push(NodeVec[i]);
        }
        return res;
    }
};

