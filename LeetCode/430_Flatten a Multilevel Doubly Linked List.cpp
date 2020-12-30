#include<stdio.h>
#include<stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head)return head;
        stack<Node*> st;
        Node* temp1 = head;
        while (temp1->next||temp1->child) {
            if (temp1->child) {
                if (temp1->next) st.push(temp1->next);
                temp1->next = temp1->child;
                temp1->next->prev = temp1;
                temp1->child = NULL;
            }
            temp1 = temp1->next;

        }
        while (!st.empty()) {

            temp1->next = st.top();
            temp1->next->prev = temp1;
            st.pop();
            while (temp1->next) temp1 = temp1->next;
        }
        return head;
    }
};



int main() {

}