#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        stack<pair<int, int>> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (st.empty()) st.push(pair<int, int>(arr[i], i));
            else if (st.top().first > arr[i]) st.push(pair<int, int>(arr[i], i));
            else if (st.top().first == arr[i]) st.top().second = i;
            else if (st.top().first < arr[i]) {
                int index = -1;
                while (!st.empty() && st.top().first < arr[i]) {
                    index= st.top().second;
                    st.pop();
                }
                int temp = arr[index];
                arr[index] = arr[i];
                arr[i] = temp;
                break;
            }
           
        }
        return arr;
    }
};

int main() {
    Solution mysolu;
    vector<int> arr = { 1,9,4,6,7 };
    vector<int> arr1 = { 3,1,1,3 };
    vector<int> res = mysolu.prevPermOpt1(arr);
	return 0;
}