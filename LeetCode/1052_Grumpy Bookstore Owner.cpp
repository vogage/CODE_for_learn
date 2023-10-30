#include <vector>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        vector<int> pres(n+1,0);
        vector<int> tails(n+1,0);
        int pre = 0;
        for (int i = 0; i < customers.size() - minutes; i++) {
            if (grumpy[i] == 0) pre += customers[i];
            pres[i+1] = pre;
        }
        int tail = 0;
        for (int j = customers.size() - 1; j >= minutes; j--) {
            if (grumpy[j] == 0) tail += customers[j];
            tails[j] = tail;
        }
        int temp = 0;
        for (int i = 0; i < minutes; i++) temp += customers[i];
        int res = temp+tails[minutes];
        for (int begin = 1; begin <= customers.size() - minutes; begin++) {
            temp -= customers[begin - 1];
            temp += customers[begin+minutes-1];
            res = max(res, temp + pres[begin] + tails[begin + minutes]);
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<int> customers = { 1, 0, 1, 2, 1, 1, 7, 5 };
    vector<int> grumpy =     { 0, 1, 0, 1, 0, 1, 0, 1 };
    int minutes = 3;
    int res = mysolu.maxSatisfied(customers, grumpy, minutes);

    return 0;
}