#include <string>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Node {
    char flag;
    unordered_set<string> candis;
    Node* pre;
    Node* next;
    Node(char f, unordered_set<string> v,Node* p,Node* n) :flag(f), candis(v),pre(p),next(n) {}

};

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        Node* root = new Node('*',unordered_set<string>(),nullptr,nullptr);
        Node* temp = root;
        for (char c : expression) {
            if (c == '{') {
                temp->next = new Node(c, unordered_set<string>(), temp, nullptr);
                temp = temp->next;
            }
            else if (c == '}') {
                int cf = true;
                while (1){
                    if (temp->pre->flag == '#') Nodemerge(temp);
                    else if (temp->pre->flag == ','&&cf) Nodeselect(temp);
                    else {
                        if (cf) { cf = false; Nodepop(temp); continue; }
                        else break;
                    }
                }
            }
            else if (c == ',') {
                temp->next = new Node(c, unordered_set<string>(), temp, nullptr);
                temp = temp->next;
            }
            else {
                temp->next = new Node('#', unordered_set<string>(), temp, nullptr);
                temp = temp->next;
                temp->candis.insert(string(1, c));
                if (temp->pre->flag == '#') Nodemerge(temp);
               
            }
        }
        vector<string> res;
        for (auto str : root->next->candis) {
            res.push_back(str);
        }
        sort(res.begin(), res.end());
        return res;
    }
private:
    void Nodemerge(Node* &p) {
        unordered_set<string> candiset;
        for (auto str1 : p->pre->candis) {
            for (auto str2 : p->candis) {
                candiset.insert(str1 + str2);
            }
        }
        p->pre->candis = candiset;
        p = p->pre;
        p->next = nullptr;
    }

    void Nodeselect(Node* &p) {
        for (auto str : p->candis) {
            p->pre->pre->candis.insert(str);
        }
        p = p->pre->pre;
        p->next = nullptr;
    }

    void Nodepop(Node*& p) {
        Node* n = p->pre->pre;
        n->next = p;
        p->pre = n;
   
    }

};

int main() {
    Solution mysolu;
    string  expression = "{a,b}{c,{d,e}}";
    string  expression1 = "{a{b,c},{ab,z}}";
    string expression2 = "{a,{a,{x,ia,o},w}er{n,{g,{u,o}},{a,{x,ia,o},w}},er}";
    vector<string> res = mysolu.braceExpansionII(expression2);
	return 0;
}