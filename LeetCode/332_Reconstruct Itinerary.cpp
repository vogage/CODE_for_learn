#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>

using namespace std;


class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        vector<bool> visited(n,false);
        //unordered_map<string,string>
        vector<string> res;
        vector<string> total;
        res.push_back("JFK");
       // total.push_back(res);
        dfs(tickets, visited, res,total);
        return res;
    }
    void dfs(vector<vector<string>>& tickets, vector<bool>& visited,
       vector<string>& temp,vector<string>& total) {
       
        
        int m = tickets.size();
        if (m + 1 == temp.size()) {
            judge(total, temp);
            return;
        }
       
         string root = temp.back();
            for (int i = 0; i < tickets.size(); i++) {
                if (!visited[i]) {
                    if (tickets[i][0] == root) {
                        temp.push_back(tickets[i][1]);   
                        
                        visited[i] = true;   
                        dfs(tickets, visited,temp,total);
                        temp.pop_back();
                        visited[i] = false;
                    }
                }
            }
         
     }
      
    void judge(vector<string>& total, vector<string>& temp) {
        if (total.size() == 0) { total = temp; return; }
        for (int i = 0; i < total.size(); i++) {
            for (int j = 0; j < total[i].size(); j++) {
                if (total[i][j] > temp[i][j]) {
                    total = temp; return;
                }
                if (total[i][j] < temp[i][j])return;
            }
        }
     }

    

};


class Solution2 {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> flights;
        vector<string> res;
        for (int i = 0; i < tickets.size(); i++) {
            flights[tickets[i][0]].insert(tickets[i][1]);

        }
        dfs(flights, res, "JFK");
        return vector<string>(res.rbegin(), res.rend());
    }

    void dfs(unordered_map<string, multiset<string>>& flights, vector<string>& res, string departure) {
        while (flights[departure].size()) {
            string next = *flights[departure].begin();
            flights[departure].erase(flights[departure].begin());
            dfs(flights, res, next);
        }
        res.push_back(departure);
    }
};

int main() {
    Solution2 mysolu;
    vector < vector < string >>input= { {"JFK", "SFO"}, { "JFK","ATL" },
        { "SFO","ATL" }, { "ATL","JFK" }, { "ATL","SFO" }};
    vector<vector<string>> input2 = { {"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"} };
    vector<vector<string>> input3 = { {"MUC", "LHR"},{"JFK", "MUC"},{"SFO", "SJC"},{"LHR", "SFO"} };
    vector<string> res = mysolu.findItinerary(input3);
    return 0;
}