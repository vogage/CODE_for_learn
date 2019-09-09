#include<stdio.h>
#include<vector>


using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res = { 0,1 };
		int nums = 1;
		for (int i = 0; i < n-1; i++) {
			mirror(res);
			nums = nums * 2;
			add_final_bit(res, nums);
		}
		return res;
	}
	void mirror( vector<int>& res){
		for (int i = res.size() - 1; i >= 0; i--) {
			res.push_back(res[i]);
		}
		return;
    }

	void add_final_bit(vector<int> &res, int num) {
		for (int i = 0; i < num; i++) {
			res[i] = res[i] << 1;
		}
		for (int i = num; i < num * 2; i++) {
			res[i] = res[i] << 1;
			res[i]++;
		}
		return;
	}
};

int main() {
	int n = 2;
	Solution mysolu;
	vector<int> ans = mysolu.grayCode(n);
	return 0;
}