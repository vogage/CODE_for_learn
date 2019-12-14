#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution2 {
public:
	vector<int> ans;
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses,vector<int>());
		vector<bool> todo(numCourses,false);
		vector<bool> done(numCourses,false);
		vector<int> order;
		
		build_graph(graph, numCourses, prerequisites);
		
		for (int i = 0; i < numCourses; i++) {
			if (!done[i]) {
				if (!DFS(graph, order, i, todo, done))return vector<int>();
			}
		}
		return ans;
		
	}
	void build_graph(vector<vector<int>> &graph, int numCourses, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

		}
	}
	 bool DFS(vector<vector<int>>&graph,vector<int>&order ,int choose,vector<bool>& todo,vector<bool> &done) {
		if (todo[choose])return false;
		if (done[choose])return true;
		
		todo[choose] = done[choose] = true;
		order.push_back(choose);
		for (auto i : graph[choose]) {
			if (!DFS(graph, order, i, todo, done)) return false;
		}
		if (order.size() > ans.size())ans = order;
		order.pop_back();
		todo[choose] = false;

			
		
		//order.pop_back();
		return true;
	}
};

class Solution {
public:

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<vector<int>> graph(numCourses, vector<int>());
		vector<int> order;
		queue<int> candidate;
		for (int i = 0; i < numCourses; i++) {
			candidate.push(i);
		}

		vector<bool> done(numCourses, false);
		vector<bool> done_candidate(numCourses, false);
		build_graph(graph, numCourses, prerequisites);
		DFS(graph, order, candidate, done, done_candidate);
		int flag = true;
		for (auto f : done_candidate) {
			flag = flag && f;
		}
		return flag || candidate.size() != 0 ? vector<int>() : order;

	}
	void build_graph(vector<vector<int>> &graph, int numCourses, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

		}
	}
	void DFS(vector<vector<int>>&graph, vector<int>& order, queue<int>& candidate, vector<bool>& done, vector<bool>& done_candidate) {

		if (candidate.size() == 0)return;

		int choose = candidate.front();
		if (done_candidate[choose])return;
		candidate.pop();

		if (graph[choose].size() == 0) {

			order.push_back(choose);
			done[choose] = true;

		}
		else {
			for (int i = 0; i < graph[choose].size(); i++) {
				if (done[graph[choose][i]] == false) {

					candidate.push(choose);
					done_candidate[choose] = true;
					DFS(graph, order, candidate, done, done_candidate);

					if (candidate.size() == 0)return;
				}
			}

			done[choose] = true;
			order.push_back(choose);

		}

		DFS(graph, order, candidate, done, done_candidate);

		return;
	}
};

bool cmp(pair<int,int>& a, pair<int,int>& b) {
	return a.second < b.second;
}
class Solution3 {
public:

	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses,vector<int>());
		build_graph(graph, numCourses, prerequisites);
		vector<int> res;
		vector<pair<int,int>> m; //map about floor
		vector<bool> todo(numCourses, false);
		vector<bool> done(numCourses, false);
		for (int i = 0; i <numCourses; i++) {
			if (!done[i]&&graph[i].size()) {
				if (!iscircle(graph, m, todo, done,i,0))return vector<int>();
			}
		}
		sort(m.begin(), m.end(), cmp);
		for (int i = 0; i < m.size(); i++) {
			res.push_back(m[i].first);
		}
		for (int i = 0; i < numCourses; i++) {
			if (!done[i])res.push_back(i);
		}
		return res;
	}
	void build_graph(vector<vector<int>>& graph, int numCourses,vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		 }
		return;
	}

	bool iscircle(vector<vector<int>>& graph, vector<pair<int, int>>& m, vector<bool> & todo, vector<bool>& done, int choose,int floor) {
		if (todo[choose])return false;
		if (done[choose])return true;
		pair<int, int> p(choose, floor);
		m.push_back(p);
		todo[choose] = done[choose] = true;
		for (int i = 0; i < graph[choose].size(); i++) {
			if (!iscircle(graph, m, todo, done, graph[choose][i], floor + 1)) return false;
		}
		todo[choose] = false;
		return true;
	}
};

class Solution4{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> res(numCourses);
		unordered_map<int, int> m;
		
		for (int i = 0; i < numCourses; i++) {
			m[i] = i;
		}
		for (int i = 0; i < prerequisites.size(); i++) {
			if (m[prerequisites[i][0]] < m[prerequisites[i][1]])
			{
				

				
					change(m,prerequisites[i][0], prerequisites[i][1]);
				
			}
		}
		
		for (auto c : m) {
			res[c.second] = c.first;
		}
		for (int i = 0; i < prerequisites.size(); i++) {
			if (m[prerequisites[i][0]] < m[prerequisites[i][1]])return vector<int>();
		}
		return res;

	}
	void change(unordered_map<int, int>&m, int i, int j) {
		int temp = m[i];
		m[i] = m[j];
		m[j] = temp;
		return;
	}
};

class Solution5 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>());
		vector<vector<int>> graph_enter(numCourses, vector<int>());
		vector<bool> todo(numCourses, false);
		vector<bool> done(numCourses, false);
		vector<int> res;
		queue<int> q;
		build_graph(graph, prerequisites);
		build_graph_enter(graph_enter, prerequisites);
		for (int i = 0; i < numCourses; i++) {
			if (graph_enter[i].size() == 0) {
				q.push(i);
			}
		}
		for (int i = 0; i < numCourses; i++) {
			if(!done[i]&&!DFS(graph, todo, done, i))return vector<int>();
		}
		for (auto i : done) i = false;
		BFS(graph,graph_enter,q,res,done);
		return res;
	}

private:
	bool DFS(vector<vector<int>>& graph, vector<bool> todo, vector<bool>done, int choose) {
		if (todo[choose]) return false;
		if (done[choose])return true;
		done[choose] = todo[choose] = true;
		for (auto i : graph[choose]) {
			if (!DFS(graph, todo, done, i))return false;
		}
		todo[choose] = false;
		return true;
	}

	void BFS(vector<vector<int>>&graph,vector<vector<int>>& graph_enter,queue<int>& q,vector<int>& res,vector<bool>& done) {
		if (q.size() == 0)return;
		int choose = q.front();
		q.pop();


		if (!done[choose]) {
			bool flag = true;
			for (auto j : graph_enter[choose]) {
				flag = flag && done[j];
			}
			if (flag) {
				res.push_back(choose);
			}
			else {
				q.push(choose);
				BFS(graph,graph_enter,q,res,done);
			}
		}
		done[choose] = true;
		for (auto i : graph[choose]) {
			q.push(i);
			
		}
		BFS(graph,graph_enter,q, res,done);
		
		return;
	}


	void build_graph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		return;
	}

	void build_graph_enter(vector<vector<int>>& graph_enter, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph_enter[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		return;
	}
};


class Solution6{
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> indegree(numCourses,0);
		vector<int> res;
		for (int i = 0; i < prerequisites.size(); i++) {
			indegree[prerequisites[i][0]]++;
		}
		queue<int> q;
		for (int i = 0; i <numCourses; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				res.push_back(i);
			}
		}
		while (!q.empty()) {
			int choose = q.front(); q.pop();
			for (int i = 0; i < prerequisites.size(); i++) {
				if (prerequisites[i][1] == choose) {
					indegree[prerequisites[i][0]]--;
					if (indegree[prerequisites[i][0]] == 0) {
						res.push_back(prerequisites[i][0]);
						q.push(prerequisites[i][0]);
					}
				}
			}
		}
		return res.size() == numCourses ? res : vector<int>();
	}
private:

};


class Solution7 {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses,vector<int>());
		vector<bool> onstack(numCourses, false);
		vector<bool> done(numCourses, false);
		vector<int> order;
		build_graph(graph, prerequisites);
		for (int i = 0; i < numCourses; i++) {
			if (!done[i]) {
				if (!iscircle(graph,i,done,onstack,order))return vector<int>();
			}
		}
		return order;
		
	}
private:
	bool iscircle(vector<vector<int>>& graph,int choose, vector<bool>& done, vector<bool> &onstack, vector<int>&order) {
		if (onstack[choose]) return false;
		if (done[choose])return true;
		onstack[choose] = true;
		for (auto i : graph[choose]) {
			if(!iscircle(graph,i,done,onstack,order)) return false;
		}
		onstack[choose] = false;
		order.push_back(choose);
		done[choose] = true;
		return true;

	}
	void build_graph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites) {
		for (int i = 0; i < prerequisites.size(); i++) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		return;
	}
};

int main() {
	//4, [[1, 0], [2, 0], [3, 1], [3, 2]]
	int numCourses = 4;
	vector<vector<int>> prerequisites;
	vector<int> input;
	input = { 1,0 };
	prerequisites.push_back(input);
	input = { 2,0 };
	prerequisites.push_back(input);
	input = { 3,1 };
	prerequisites.push_back(input);
	input = { 3,2 };
	prerequisites.push_back(input);

	vector<vector<int>> prerequisites2;
	input = { 0,1 };
	prerequisites2.push_back(input);

	vector<vector<int>> prerequisites3;
	input = { 0,1 };
	prerequisites3.push_back(input);
	input = { 1,0 };
	prerequisites3.push_back(input);


	vector<vector<int>> prerequisites4;
	input = { 1,0 };
	prerequisites4.push_back(input);
	input = { 1,2 };
	prerequisites4.push_back(input);
	input = { 0,1 };
	prerequisites4.push_back(input);


	vector<vector<int>> prerequisites5;
	input = { 2,0 };
	prerequisites5.push_back(input);
	input = { 2,1 };
	prerequisites5.push_back(input);


	vector<vector<int>> prerequisites6;
	input = { 0,1 };
	prerequisites6.push_back(input);
	input = { 0,2 };
	prerequisites6.push_back(input);
	input = { 1,2 };
	prerequisites6.push_back(input);

	vector<vector<int>> prerequisites7;
	//[[1, 0], [0, 3], [0, 2], [3, 2], [2, 5], [4, 5], [5, 6], [2, 4]]
	input = { 1,0 };
	prerequisites7.push_back(input);
	input = { 0,3 };
	prerequisites7.push_back(input);
	input = { 0,2 };
	prerequisites7.push_back(input);
	input = { 3,2 };
	prerequisites7.push_back(input);
	input = { 2,5 };
	prerequisites7.push_back(input);
	input = { 4,5 };
	prerequisites7.push_back(input);
	input = { 5,6 };
	prerequisites7.push_back(input);
	input = { 2,4 };
	prerequisites7.push_back(input);

	Solution7 mysolu;
	vector<int> res = mysolu.findOrder(7, prerequisites7);
	

	return 0;

}