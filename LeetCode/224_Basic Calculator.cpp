#include<stdio.h>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		int left = 0;
		string temp = "";
		vector<string> vec;
		//stack<string> st;
		for (int i = 0; i < s.size(); i++) {
			
			if (s[i] == ' '&&i!=s.size()-1) continue;
			if (s[i] <= '9'&&s[i] >= '0') {
				temp += s[i];
				if (i == s.size() - 1) vec.push_back(temp);
			}
			else {
				if (temp.size()) {
					vec.push_back(temp);
					temp = "";
				}
				//char c = s[i];
				//string oo1 = "+";
				////string oo = "" + s[i];
				//string oo = to_string(s[i]);
				////vec.push_back(""+s[i]);
				//vec.push_back(oo);
				//这里我就搞不明白了
				//再研究研究吧
				if (s[i] == '+') vec.push_back("+");
				if (s[i] == '-')vec.push_back("-");
				if (s[i] == ')')vec.push_back(")");
				if (s[i] == '(')vec.push_back("(");
				
			}
			
		}
		vector<string> vec_cal;
		cal(left, vec);






		return left;
	}
	void cal(int &left, vector<string>&vec) {
	
		int flag = 0;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == "+") {
				flag = 0;
			}
			else if (vec[i] == "-") {
				flag = 1;
			}
			else if (vec[i] == "(") {
				int count = 1;
				vector<string> vec_temp;i++;
				while (count) {
					
					vec_temp.push_back(vec[i]);
					if (vec[i] == ")") {
						count--;
					}
					if (vec[i] == "(") {
						count++;
					}
					i++;
				}
				int res = 0;
				vec_temp.pop_back();
				i--;
				cal(res, vec_temp);
				if (flag == 0) left += res;
				if (flag == 1) left -= res;

			}
			else if (vec[i] == ")") {

			}
			else {
				if (flag == 0) {
					left += stoi(vec[i]);
				}
				if (flag == 1) {
					left -= stoi(vec[i]);
				}
			}
		}

	}
};
	
class Solution2 {
public:
	int calculate(string s) {
		int result = 0;
		int number = 0;
		int sign = 1;
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				number = number * 10 + s[i] - '0';
			}
			else if (s[i] == '+') {
				result += sign*number;
				sign = 1;
				number = 0;
			}
			else if (s[i] == '-') {
				result +=sign*number;
				sign = -1;
				number = 0;
			}
			else if (s[i] == '(') {
				st.push(result);
				st.push(sign);
				sign = 1;
				result = 0;
			}
			else if (s[i] == ')') {
				result += sign * number;
				number = 0;
				result *= st.top();
				st.pop();
				result += st.top();
				st.pop();

			}
		}
		if (number != 0)result += sign * number;
		return result;
	}
};

int main() {
	Solution2 mysolu;
	string str = "(1+(4+5+2)-3)+(6+8)";
	string str2 = " 2-1+2 ";
	string str3 = "1 + 1";
	string str4 = "2147483647";
	int res = mysolu.calculate(str4);
	return 0;
}