#include<stdio.h>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> num;
		vector<vector<int>> res;
		vector<int> temp;
		DSP(res,temp,num, k, n);
		return res;
	}
	void DSP(vector<vector<int>>& res,vector<int> &temp,vector<int>& num, int k, int n) {
		if (k ==temp.size())return;
		int i = 0;
		if (temp.size() == 0)i = 1;
		else i = temp.back() + 1;
		for (; i < 10; i++) {
			if (i == n) {
				if (k == temp.size()+1&&find(num.begin(),num.end(),i)==num.end()) {
					temp.push_back(i);
					res.push_back(temp);
					temp.pop_back();
					return;
				}
			}
			else {
				if (i < n) {
					
					
						if (find(num.begin(), num.end(), i) == num.end()&&k>temp.size()+1) {
							num.push_back(i);
							temp.push_back(i);
							DSP(res, temp, num, k , n - i);
							temp.pop_back();
							num.pop_back();
						}
					
				}
			}
		}
		return;
	}
};


int main() {
	int n = 9;
	int k = 3;
	vector<vector<int>> res;
	Solution mysolu;
	res = mysolu.combinationSum3(k, n);
	return 0;
}