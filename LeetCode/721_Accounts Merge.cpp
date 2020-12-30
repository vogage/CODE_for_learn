#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<stack>
#include<map>
#include<set>


using namespace std;




bool cmp(const string& str1, const string& str2) {
    return str1 < str2;
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<unordered_set<string>>> m;
        vector<vector<string>> res;
        for (int i = 0; i < accounts.size(); i++) {
            unordered_set<string> str_set;
            for (int j = 1; j < accounts[i].size(); j++) {
                str_set.insert(accounts[i][j]);
            }
            m[accounts[i][0]].push_back(str_set);
            
        }
        stack<unordered_set<string>> st;
        for (auto v_v : m) {
            vector<unordered_set<string>> v = v_v.second;

            int n = v.size();
            vector<bool> visited(n, false); 
           

            for (int i = 0; i < v.size(); i++) {
                 unordered_set<string> temp_res;

                if (!visited[i]) {
                    st.push(v[i]);
                    visited[i] = true;


                    while (!st.empty()) {
                        unordered_set<string> temp = st.top();
                        st.pop();
                        for (string temp_str : temp) {
                            if (temp_res.find(temp_str) == temp_res.end()) {
                                temp_res.insert(temp_str);
                            }
                        }
                        for (string str_set:temp_res) {
                            for (int j = 1; j < v.size(); j++) {
                                if (visited[j]) continue;
                          
                                    if (v[j].find(str_set)!=v[j].end()) {
                                        st.push(v[j]);
                                        visited[j] = true;
                                        break;
                                    }
                                
                            }
                        }
           

                    }
                   
                    vector<string> res_v;
                    res_v.push_back(v_v.first);
                    for (string str_temp_res : temp_res) res_v.push_back(str_temp_res);
                    sort(res_v.begin(),res_v.end(), cmp);
                    res.push_back(res_v);
                    temp_res.clear();
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        map<string, string> owner;
        map<string, string> parents;
        map<string, set<string>> unions;
        for (int i = 0; i < acts.size(); i++) {
            for (int j = 1; j < acts[i].size(); j++) {
                parents[acts[i][j]] = acts[i][j];
                owner[acts[i][j]] = acts[i][0];
            }
        }
        for (int i = 0; i < acts.size(); i++) {
            string p = find(acts[i][1], parents);
            for (int j = 2; j < acts[i].size(); j++)
                parents[find(acts[i][j], parents)] = p;
        }
        for (int i = 0; i < acts.size(); i++)
            for (int j = 1; j < acts[i].size(); j++)
                unions[find(acts[i][j], parents)].insert(acts[i][j]);

        vector<vector<string>> res;
        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
private:
    string find(string s, map<string, string>& p) {
        return p[s] == s ? s : find(p[s], p);
    }
};



class Solution3 {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
        unordered_map<string, string> owners;
        unordered_map<string, unordered_set<string>> m;
        //build the map
        for (int i = 0; i < acts.size(); i++) {
            owners[acts[i][1]] = acts[i][0];
            for (int j = 2; j < acts[0].size(); j++) {
                owners[acts[i][j]] = acts[i][0];
                m[acts[i][j]].insert(acts[i][j - 1]);
                m[acts[i][j - 1]].insert(acts[i][j]);
            }
        }

        unordered_set<string> s;
        vector<vector<string>> res;

        for (auto mail : owners) {
            if (s.find(mail.first )== s.end()) {
                     vector<string> temp;
                    temp.push_back(mail.second);
                    dfs(m, s, temp, mail.first);
                    sort(temp.begin(), temp.end(), cmp);
                    res.push_back(temp);
            }
        }
        
        return res;

    }

    void dfs(unordered_map<string, unordered_set<string>>& m, unordered_set<string>& s,
        vector<string>& temp, string str) {
        if (s.find(str) != s.end()) return;
        s.insert(str);
        temp.push_back(str);
        for (auto m_set : m[str]) {
            dfs(m, s, temp, m_set);
        }
        return;
    }
};

int main() {
    vector<string> temp1 = { "John", "johnsmith@mail.com", "john00@mail.com" };
    vector<string> temp2 = { "John", "johnnybravo@mail.com" };
    vector<string> temp3 = { "John", "johnsmith@mail.com", "john_newyork@mail.com" };
    vector<string> temp4 = { "Mary", "mary@mail.com" };
    vector<vector<string>> accounts;
    accounts.push_back(temp1);
    accounts.push_back(temp2);
    accounts.push_back(temp3);
    accounts.push_back(temp4);
    vector<vector<string>> input2 = { {"David","David0@m.co","David1@m.co"}
        ,{"David","David3@m.co","David4@m.co"},
        {"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"}
        ,{"David","David1@m.co","David2@m.co"} };
    Solution3 mysolu;
    vector<vector<string>> res = mysolu.accountsMerge(input2);
    return 0;

}