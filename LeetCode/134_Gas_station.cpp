#include<stdio.h>
#include<vector>

using namespace std;
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int> &cost) {
		vector<int> gas2;
		vector<int> cost2;
		int n = gas.size();
		for (int i = 0; i < gas.size(); i++) {
			gas2.push_back(gas[i]);
			cost2.push_back(cost[i]);
		}
		for (int i = 0; i < gas.size(); i++) {
			gas2.push_back(gas[i]);
			cost2.push_back(cost[i]);
		}
		for (int i = 0; i < n; i++) {
			int begin = gas2[i];
			int j = i;
			for (; j < i + n; j++) {
				if (begin < cost2[j]) break;
				begin=begin- cost2[j] + gas2[j + 1];
			}
			if (j == i + n)return i;
		}
		return -1;
	}
};

class Solution2 {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		vector<int> info;
		for (int i = 0; i < gas.size(); i++) {
			info.push_back(gas[i] - cost[i]);
		}
		int n = gas.size();
		for (int i = 0; i < n; i++) {
			int begin = info[i];
			int j = i+1;
			for (; j < i+n; j++) {
				if (begin < 0)break;
				begin += info[j%n];
				
			}
			if (j == i + n&&begin>=0)return i;
		}
		return -1;
	}
};

int main() {
	vector<int> gas = { 3,3,4 };
	vector<int>cost = { 3,4,4 };
	Solution2 mysolu;
	int res = mysolu.canCompleteCircuit(gas, cost);
	return res;
}