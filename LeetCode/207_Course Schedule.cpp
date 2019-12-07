#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> m;
		
		for (int i = 0; i < prerequisites.size(); i++) {
			m[prerequisites[i][1]].push_back(prerequisites[i][0]);
			
		}
		
		for (auto choose : m){
			unordered_set<int> set;
			if (!judge(m, choose.first,set))return false;
		}
		return true;
	}
	bool judge(unordered_map<int, vector<int>> &m, int choose,unordered_set<int>& set) {
		bool ans=true;
		for (auto p : m[choose]) {
			if (set.find(p) != set.end())return false;
			else { set.insert(p); }
			if (m.find(p) != m.end()) {
				ans = ans && judge(m, p, set);
			}
		}
		return ans;
	}
};

int main() {
	//[[1, 0], [0, 1]]
	int k = 2;
	
	vector<vector<int>> prerequisites;
	vector<int> input = { 1,0 };
	prerequisites.push_back(input);
	input = { 0,1 };
	prerequisites.push_back(input);
	vector<vector<int>> prerequisites2;
	//[[0,2],[1,2],[2,0]]
	input = { 0,2 };
	prerequisites2.push_back(input);
	input = { 1,2 };
	prerequisites2.push_back(input);
	input = { 2,0 };
	prerequisites2.push_back(input);

	Solution mysolu;
	bool res = mysolu.canFinish(k, prerequisites2);
	return 0;

}