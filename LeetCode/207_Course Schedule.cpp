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


class Solution2 {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph g = buildGraph(numCourses, prerequisites);
		vector<bool> todo(numCourses, false), done(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			if (!done[i] && !acyclic(g, todo, done, i)) {
				return false;
			}
		}
		return true;
	}
private:
	typedef vector<vector<int>> graph;

	graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
		graph g(numCourses);
		for (auto p : prerequisites) {
			g[p.second].push_back(p.first);
		}
		return g;
	}

	bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
		if (todo[node]) {
			return false;
		}
		if (done[node]) {
			return true;
		}
		todo[node] = done[node] = true;
		for (int v : g[node]) {
			if (!acyclic(g, todo, done, v)) {
				return false;
			}
		}
		todo[node] = false;
		return true;
	}
};


class	Solution3 {
public:

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> graph;
		build_graph(graph, numCourses, prerequisites);
		vector<bool> done(numCourses, false);
		for (int i = 0; i < numCourses; i++) {
			if (iscircle(graph, done, i))return false;
		}
		return true;
	}

	void build_graph(unordered_map<int, vector<int>>& graph, int numCourses, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		return;
	}

	bool iscircle(unordered_map<int, vector<int>>& graph, vector<bool> &done, int i) {
		if (done[i])return true;
		done[i] = true;
		for (auto p : graph[i]) {
			if (iscircle(graph, done, p)) return false;
		}
		done[i] = false;
		return false;
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

	vector<pair<int, int>> prerequisites3;
	vector<vector<int>> prerequisites4;
	input = { 0,1 };
	prerequisites4.push_back(input);



	Solution3 mysolu;
	bool res = mysolu.canFinish(3, prerequisites2);
	return 0;

}