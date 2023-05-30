#include<unordered_set>
#include<unordered_map>
#include<string>
#include<vector>
#include<stack>

using namespace std;



class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));
        vector<vector<int>> path(1<<n, vector<int>(n, -1));
        vector<vector<int>> graph(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = cal(words[i], words[j]);
            }
        }
        for (int i = 0; i <(1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    int prev = i - (1 << j);
                    if (prev == 0) {
                        dp[i][j] = words[j].size();
                    }
                    else {
                        for (int k = 0; k < n; k++) {
                            if (dp[prev][k] != INT_MAX) {
                                if (dp[prev][k] + graph[k][j] < dp[i][j]) {
                                    dp[i][j] = dp[prev][k] + graph[k][j];
                                    path[i][j] = k;
                                }
                            }
                        }
                    }
                }
            }
        }

        //get the shortest length
        int res_len = INT_MAX;
        int last = 0;
        for (int k = 0; k < n; k++) {
            if (res_len > dp[(1 << n) - 1][k]) {
                res_len = dp[(1 << n) - 1][k];
                last = k;
            }
        }

        // reconstruct the ans string
        stack<int> st_ans;
       
        int cur = (1 << n) - 1;
        while (cur) {   
            st_ans.push(last);
            int temp = cur;
            cur -= (1 << last);
            last = path[temp][last];  
        }
        int pre_index = st_ans.top();
        string res = words[pre_index];
        st_ans.pop();
        while (!st_ans.empty()) {
            int index = st_ans.top();
            st_ans.pop();
            int len_cascade = graph[pre_index][index];
            res += words[index].substr(words[index].size() - len_cascade, len_cascade);
            pre_index = index;
        }




        return res;
    }
private:
    int cal(const string& str1,const string& str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        int res =0;
        for (int i = 0; i < n1 && i <n2; i++) {
            int str1_index = n1 - 1 - i;
            int str2_index = 0;
            while (str2_index < i + 1&&str2[str2_index]==str1[str1_index]) {
                str2_index++;
                str1_index++;
            }
            if(str1_index==n1)res = max(res, str2_index);
        }
        return n2 - res;
    }
};


int main() {
    Solution mysolu;
    vector<string>  words = { "catg", "ctaagt", "gcta", "ttca", "atgcatc" };
    string res = mysolu.shortestSuperstring(words);
	return 0;
}
