#include <vector>

using namespace std;

struct Node {
    int val;
    int ksum;
    Node* pre;
    Node* next;
    Node(int v) :val(v), pre(nullptr), next(nullptr) {}
    Node(int v, Node* p, Node* n) :val(v), pre(p), next(n) {}

};
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        Node* dumy = new Node(-1);
        for (int i = 0; i < stones.size(); i++) {

        }
    }
};

int main() {

}