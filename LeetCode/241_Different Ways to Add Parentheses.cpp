#include<vector>
#include<stack>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		string str = "";
		vector<int> res;
		vector<string> v;
		vector<vector<string>> v_str_set;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] <= '9'&&input[i] >= '0') {
				str += input[i];
			}
			else {
				if (str.size() != 0) {
					v.push_back(str);
					str = "";
					char c = input[i];
					if (c == '+') v.push_back("+");
					if (c == '-') v.push_back("-");
					if (c == '*') v.push_back("*");
				}
			}
		}
		if (str.size() != 0) v.push_back(str);
		cal_part(res, v,v_str_set);
		return res;
	}
	void cal_part(vector<int>& res, vector<string>& v,vector<vector<string>>& v_str_set) {
		if (v.size() == 1) {
			res.push_back(stoi(v[0].c_str()));
			return;
		}
		vector<vector<string>>::iterator it = find(v_str_set.begin(), v_str_set.end(), v);
		if (it != v_str_set.end()) v_str_set.erase(it);
		for (int i = 0; i < v.size() - 2; i+=2) {
			vector<string> new_v;
			for (int j = 0; j < i; j++) {
				new_v.push_back(v[j]);
			}
			int left = stoi(v[i]);
			int right = stoi(v[i + 2]);
			if (v[i + 1] == "+") {
				left = left + right;
			}
			else if (v[i + 1] == "-") {
				left = left - right;
			}
			else if (v[i + 1] == "*") {
				left = left * right;
			}
			new_v.push_back(to_string(left));
			for (int j = i + 3; j < v.size(); j++) {
				new_v.push_back(v[j]);
			}
			v_str_set.push_back(new_v);
			cal_part(res, new_v,v_str_set);
		}
		return;


	}
	
};

int main() {
	Solution mysolu;
	string input = "2-1-1";
	string input1 = "2*3-4*5";
	vector<int> res = mysolu.diffWaysToCompute(input1);
	return 0;
}