#include<stdio.h>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>


using namespace std;

//class Solution {
//public:
//	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//		if (edges.size() < 1)return vector<int>();
//		unordered_set<int> node_set;
//		unordered_map<int, vector<int>> node_map;
//		for (int i = 0; i < edges.size(); i++) {
//			node_map[edges[i][0]].push_back(edges[i][1]);
//			node_map[edges[i][1]].push_back(edges[i][0]);
//			if (node_set.find(edges[i][0]) == node_set.end()) node_set.insert(edges[i][0]);
//			if (node_set.find(edges[i][1]) == node_set.end()) node_set.insert(edges[i][1]);
//		}
//		int floor =INT_MAX;
//		vector<int> res;
//
//		for (auto node : node_set) {
//			unordered_set<int> used;
//			int max_floor = INT_MIN;
//			DFS(n, node_map,used, floor, res,node,0,max_floor,node);
//		}
//		return res;
//	}
//	void DFS(int n, unordered_map<int, vector<int>>& node_map, unordered_set<int>& used,
//		int& floor, vector<int>&res, int node,int temp_floor,int& max_floor,int root_node) {
//		used.insert(node);
//		max_floor = max(temp_floor, max_floor);
//		if (n == used.size()) {
//			if ( max_floor<floor) {
//				res.clear();
//				res.push_back(root_node);
//				floor = temp_floor;
//			}
//			else if (floor ==max_floor) {
//				res.push_back(root_node);
//			}
//			return;
//		}
//	
//		for (auto node2 : node_map[node]) {
//			if (used.find(node2) == used.end()) {
//			
//				DFS(n, node_map, used, floor, res, node2, temp_floor + 1, max_floor,root_node);
//			}
//		}
//	/*	auto iter = used.find(node);
//		used.erase(iter);*/
//	}
//};

//Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (edges.size() < 1) {
			vector<int> ans;
			ans.push_back(0);
			return ans;
		};
		unordered_set<int> node_set;
		unordered_map<int, vector<int>> node_map;
		for (int i = 0; i < edges.size(); i++) {
			node_map[edges[i][0]].push_back(edges[i][1]);
			node_map[edges[i][1]].push_back(edges[i][0]);
			if (node_set.find(edges[i][0]) == node_set.end()) node_set.insert(edges[i][0]);
			if (node_set.find(edges[i][1]) == node_set.end()) node_set.insert(edges[i][1]);
		}
		int floor = INT_MAX;
		vector<int> res;

		for (auto node : node_set) {
			unordered_set<int> used;
			int max_floor = INT_MIN;
			DFS(n, node_map, used, floor, res, node, 0, max_floor, node);
		}
		return res;
	}
	void DFS(int n, unordered_map<int, vector<int>>& node_map, unordered_set<int>& used,
		int& floor, vector<int>&res, int node, int temp_floor, int& max_floor, int root_node) {
		used.insert(node);
		max_floor = max(temp_floor, max_floor);
		if (n == used.size()) {
			if (max_floor < floor) {
				res.clear();
				res.push_back(root_node);
				floor = temp_floor;
			}
			else if (floor == max_floor) {
				res.push_back(root_node);
			}
			return;
		}

		for (auto node2 : node_map[node]) {
			if (used.find(node2) == used.end()) {

				DFS(n, node_map, used, floor, res, node2, temp_floor + 1, max_floor, root_node);
			}
		}
		/*	auto iter = used.find(node);
			used.erase(iter);*/
	}
};

class Solution2 {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		unordered_map<int, vector<int>> node_map;
		for (int i = 0; i < edges.size(); i++) {
			node_map[edges[i][0]].push_back(edges[i][1]);
			node_map[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int> leaves;
		for (auto p : node_map) {
			if (p.second.size() == 1) leaves.push_back(p.first);
		}
		while (n > 2) {
			n -= leaves.size();
			vector<int> new_leaves;
			for (int i = 0; i < leaves.size(); i++) {
				vector<int> leaf_root =node_map[ node_map[leaves[i]][0]];
				auto iter = find(leaf_root.begin(), leaf_root.end(), leaves[i]);
				leaf_root.erase(iter);
				node_map[node_map[leaves[i]][0]] = leaf_root;
				if (leaf_root.size() == 1) new_leaves.push_back(node_map[leaves[i]][0]);

			}
			leaves = new_leaves;
		}
		return leaves;
	}
};

class Solution3 {
	struct Node {
		unordered_set<int> node_set;
		int val;
		bool isLeaf() {
			return node_set.size() == 1;
		}
	};
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (edges.size()==0)return vector<int>(1, 0);
		if (edges.size() == 1) {
			vector<int> res;
			res.push_back(0);
			res.push_back(1);
			return res;
		}
		unordered_map<int, Node> node_map;
		for (int i = 0; i < edges.size(); i++) {
			node_map[edges[i][0]].node_set.insert(edges[i][1]);
			node_map[edges[i][0]].val = edges[i][0];
			node_map[edges[i][1]].node_set.insert(edges[i][0]);
			node_map[edges[i][1]].val = edges[i][1];
		}
		vector<Node> leaves;
		for (auto p : node_map) {
			if (p.second.isLeaf()) {
				leaves.push_back(p.second);
			}
		}
		while (n > 2) {
			n = n - leaves.size();
			vector<Node> new_leaves;
			for (auto leaf : leaves) {
				auto it = leaf.node_set.begin();
				node_map[*it].node_set.erase(leaf.val);
				if (node_map[*it].node_set.size() == 1) {
					Node en;
					en.node_set=node_map[*it].node_set;
					en.val = *it;
					new_leaves.push_back(en);
				}

			}
			leaves = new_leaves;
		}
		vector<int> res;
		for (int i = 0; i < leaves.size(); i++) {
			res.push_back(leaves[i].val);
		}
		return res;
	}
};




int main() {
	Solution3 mysolu;
	int n = 4;
	vector<vector<int>> input;
	vector<int> temp = { 1,0 };
	input.push_back(temp);
	temp = { 1,2 };
	input.push_back(temp);
	temp = { 1,3 };
	input.push_back(temp);
	n = 6;
	temp = { 3,0 };
	vector<vector<int>> input2;
	input2.push_back(temp);
	temp = { 3,1 };
	input2.push_back(temp);
	temp = { 3,2 };
	input2.push_back(temp);
	temp = { 3,4 };
	input2.push_back(temp);
	temp = { 5,4 };
	input2.push_back(temp);

	n = 5;
	vector<vector<int>> input3;
	temp = { 0,1 };
	input3.push_back(temp);
	temp = { 0,2 };
	input3.push_back(temp);
	temp = { 0,3 };
	input3.push_back(temp);
	temp = { 3,4 };
	input3.push_back(temp);

	vector<int> res = mysolu.findMinHeightTrees(n, input3);
	return 0;
}