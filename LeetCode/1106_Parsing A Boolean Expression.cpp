#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<>
    }
};





struct Node {
    char flag;
    bool ans;
    Node* pre;
    Node* next;
    Node(char f, bool a, Node* p, Node* n) :flag(f), ans(a), pre(p), next(n) {}
    Node() :flag('#'), ans(false), pre(nullptr), next(nullptr) {}
};

class Solution2 {
public:
    bool parseBoolExpr(string expression) {
        Node* root = new Node();
        Node* temp = root;
        for (char c : expression) {
            if (c == ')') {
                
                while (temp->pre&&temp->pre->flag != '(') temp = temp->pre;
                if (temp->pre->pre&&temp->pre->pre->flag == '&') Nodeand(temp);
                else if (temp->pre->pre && temp->pre->pre->flag == '|')Nodeor(temp);
                else Nodenot(temp);
                NodeUpdate(temp);
            }
            else {
                if (c != ',') {
                    temp->next = new Node(c, c == 't' ? true : false, temp, nullptr);
                    temp = temp->next;
                }
            }
        }
        return root->next->ans;
    }
private:
    void Nodeand(Node*& p) {
        Node* temp = p;
        while (temp->next) {
            p->ans &= temp->next->ans;
            temp = temp->next;
        }
        p->next = nullptr;
    }
    void Nodeor(Node*& p) {
        Node* temp = p;
        while (temp->next) {
            p->ans |= temp->next->ans;
            temp = temp->next;
        }
        p->next = nullptr;
    }
    void Nodenot(Node*& p) {
        p->ans = !p->ans;
        p->next = nullptr;
    }
    void NodeUpdate(Node*& p) {
        Node* temp = p->pre->pre->pre;
        temp->next = p;
        p->pre = temp;
    }
};

int main() {
    Solution mysolu;
    string expression = "!(&(f,t))";
    string expression1 = "|(&(t,f,t),t)";
    bool res = mysolu.parseBoolExpr(expression1);
    return 0;
}