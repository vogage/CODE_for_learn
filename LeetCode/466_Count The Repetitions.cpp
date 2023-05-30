#include<string>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

// OJ: https://leetcode.com/problems/count-the-repetitions/
// Author: github.com/lzl124631x
// Time: O(|s1| * n1) where |s1| is the length of s1
// Space: O(n1)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        unordered_map<int, int> n1_cnt;
        unordered_map<int, int> index_n1_cnt;
        n1_cnt[0] = 0;
        index_n1_cnt[0] = 0;
        int j = 0, cnt = 0;
        for (int i = 1; i <= n1; i++) {
            for (int ii = 0; ii < s1.size(); ii++) {
                if (s1[ii] == s2[j]) {
                    j++;
                }
                if (j == s2.size()) {
                    j = 0;
                    cnt++;
                }
            }
            n1_cnt[i] = cnt;
            index_n1_cnt[i] = j;
            for (int start = 0; start < i; start++) {
                if (index_n1_cnt[start] == j) {
                    int pre_count = index_n1_cnt[start];
                    int repeat_count =( (n1-start) / (i-start))*(cnt-n1_cnt[start]);
                    int sub_count =n1_cnt[start + (n1 - start) % (i- start)] - pre_count;
                    return (pre_count + sub_count + repeat_count)/n2;
                }
            }

        }
        return n1_cnt[n1] / n2;
    }
};

class Solution2 {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int nextIndex = 0;
        int s1_batch_n1 = 0;
        int s2_batch_n2 = 0;

    }
private:
    
    void string_add_to_stack(const string& s1,stack<char> &st) {
        for (char i : s1) st.push(i);        
    }
};


int main() {
    Solution mysolu;
    /*s1 = "acb", n1 = 4, s2 = "ab", n2 = 2*/
    // acbacbacbacb abab
    string s1 = "acb";
    int n1 = 4;
    string s2 = "ab";
    int n2 = 2;

    int res = mysolu.getMaxRepetitions(s1,n1,s2,n2);

	return 0;
}