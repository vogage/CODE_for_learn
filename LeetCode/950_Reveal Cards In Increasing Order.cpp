#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    Node* pre;
    Node* next;
    int val;
    Node(int val) :val(val), pre(nullptr), next(nullptr) {}
    Node(int val, Node* p, Node* n) :val(val), pre(p), next(n) {}
};
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        Node* root = new Node(-1);
        root->next = new Node(deck[0], root, root);
        root->pre = root->next;
        for (int i = 1; i < deck.size(); i++) {
            //1.drop the last one
            Node* last = root->pre;
            root->pre = root->pre->pre;
            root->pre->next = root;
            //2.put it into the first positon
            last->next = root->next;
            last->pre = root;
            root->next = last;
            last->next->pre = last;
            //3.insert the new node in the first position
            root->next = new Node(deck[i], root, root->next);
            root->next->next->pre = root->next;
            
        }
        vector<int> res;
        Node* temp = root;
        while (temp->next!=root) {
            res.push_back(temp->next->val);
            temp = temp->next;
        }
        return res;
    }
};

int main() {
    Solution mysolu;
//Input: deck = [17, 13, 11, 2, 3, 5, 7]
//Output : [2, 13, 3, 11, 5, 17, 7]
    vector<int> deck = { 17, 13, 11, 2, 3, 5, 7 };
    vector<int> res = mysolu.deckRevealedIncreasing(deck);
    return 0;
}