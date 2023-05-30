#include<vector>
#include<stack>

using namespace std;

class Solution3 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> previous_less(n + 1, -1);
        vector<int> next_less(n + 1, -1);
        stack<int> in_stk_previous;
        stack<int> in_stk_next;
        for (int i = 0; i < arr.size(); i++) {
            while (!in_stk_previous.empty() && arr[in_stk_previous.top()] > arr[i]) {
                in_stk_previous.pop();
            }
            previous_less[i] = in_stk_previous.empty() ? -1 : in_stk_previous.top();
            in_stk_previous.push(i);

            while (!in_stk_next.empty() && arr[in_stk_next.top()] > arr[i]) {
                next_less[in_stk_next.top()] = i;
                in_stk_next.pop();
            }
            in_stk_next.push(i);
        }

        long res = 0;
        int mod = 1e9 + 7;

        for (int k = 0; k < arr.size(); k++) {
            long left = k - previous_less[k];
            long right = next_less[k]==-1?n-k: next_less[k]-k;
            res += (long)arr[k] * left * right;
            res = res % mod;
        }
        return (int)res;
    }
};


class Solution2 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long res = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++) {
            int left =1;
            int right = 1;
            int left_index = i-1;
            int right_index = i+1;
            while (left_index >= 0 && arr[left_index] > arr[i]) {
                left_index--;
                left++;
            }
            while (right_index<arr.size()  && arr[right_index]>=arr[i]) {
                right_index++;
                right++;
            }
            res += (left * right * arr[i]);
            res = res % mod;
        }
        return (int)res;
    }
};


class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long res = 0;
        int mod = 1e9 + 7;
        vector<int> pre = arr;
        for (int i : arr) { res += i; res = res % mod; };
        vector<int> cur(n + 1, 0);
        for (int len = 2; len <= n; len++) {
            for (int back_i = len - 1; back_i < n; back_i++) {
                cur[back_i] = min(pre[back_i - 1], arr[back_i]);
                res += cur[back_i];
                res = res % mod;
            }
            pre = cur;
        }
        return(int) res;
    }
};


int main() {
    Solution3 mysolu;

    vector<int> arr = { 3,1,2,4 };
    vector<int> arr2 = { 11,81,94,43,3 };
    vector<int> arr3 = { 71,55,82,55 };
    int res = mysolu.sumSubarrayMins(arr); 
	return 0;
}