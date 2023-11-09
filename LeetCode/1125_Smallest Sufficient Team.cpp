#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;


class cmp {
public:
    bool operator ()(pair<int, vector<int>>& p1, pair<int, vector<int>>& p2) {
        return p1.second.size() > p2.second.size();
    }
};
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> skillsmap;
        for (int i = 0; i < req_skills.size(); i++) skillsmap[req_skills[i]] = i;
        unordered_map<int, vector<int>> peopleskillmap;
        unordered_map<int, vector<int>> skillpeoplemap;
        for (int i = 0; i < people.size(); i++) {
            for (int j = 0; j < people[i].size(); j++) {
                int skillindex = skillsmap[people[i][j]];
                peopleskillmap[i].push_back(skillindex);
                skillpeoplemap[skillindex].push_back(i);
            }
        }
        priority_queue < pair<int, vector<int>>, vector<pair<int, vector<int>>>, cmp> pq;
        pq.push(pair<int, vector<int>>(0, vector<int>()));
        while (!pq.empty()) {
            pair<int, vector<int>> temp = pq.top();
            pq.pop();
            int skillindex = 0;
            while ((1<<skillindex) & temp.first) skillindex++;
            if (skillindex == req_skills.size()) return temp.second;
            for (int i = 0; i < skillpeoplemap[skillindex].size(); i++) {
                int peopleindex = skillpeoplemap[skillindex][i];
                pair<int, vector<int>> temp2 = temp;
                temp2.second.push_back(peopleindex);
                for (int j : peopleskillmap[peopleindex]) {
                    temp2.first = temp2.first | (1 << j);
                }
                pq.push(temp2);
            }
            
        }
        return vector<int>();
    }
};


int main() {
    Solution mysolu;
    vector<string> req_skills = { "java","nodejs","reactjs" };
    vector<vector<string>> people = { {"java"},{"nodejs" }, {"nodejs", "reactjs"} };

    vector<string> req_skills1 = { "algorithms","math","java","reactjs","csharp","aws" };
    vector<vector<string>> people1 = { {"algorithms","math","java"},{"algorithms","math","reactjs"},
        {"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"} };
    vector<int> res = mysolu.smallestSufficientTeam(req_skills1, people1);
    return 0;
}