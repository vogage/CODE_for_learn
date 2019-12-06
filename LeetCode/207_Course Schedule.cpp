#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, int> m;
		for (int i = 0; i < numCourses; i++) {
			m[prerequisites[i][0]] = prerequisites[i][0];
		}
		unordered_map<int, unordered_set<int>> m2;
		for (int i = 0; i < numCourses; i++) {
			int choose = prerequisites[i][0];
			while (m.find(choose) != m.end()) {
				
				if (m2[choose].find(m[choose]) == m2[choose].end()) {
					m2[prerequisites[i][0]].insert(m[choose]);
					choose = m[choose];
				}
			}

		}

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
	Solution mysolu;
	bool res = mysolu.canFinish(k, prerequisites);
	return 0;

}