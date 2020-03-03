#include<stdio.h>
#include<stack>
#include<queue>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		long number = 0;
		int res = 0;
		int sign = 1;
		char c = '0';
		stack<int> st;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				number = number * 10 + s[i] - '0';
			}
			else if (s[i] == '+') {
				if (!st.empty()) {
					if (c == '*') {
						int temp = st.top(); st.pop();
						sign = st.top(); st.pop();
						 res = st.top(); st.pop();
						res += sign * (temp*number);
						number = 0;
					}
					else if(c=='/'){
						int temp = st.top(); st.pop();
						sign = st.top(); st.pop();
						 res = st.top(); st.pop();
						res += sign * (temp/number);
						number = 0;
					}
				}
				else {
					res += sign * number;
					
				}
				number = 0;
				sign = 1;
			}
			else if (s[i] == '-') {
				if (!st.empty()) {
					if (c == '*') {
						int temp = st.top(); st.pop();
						sign = st.top(); st.pop();
					 res = st.top(); st.pop();
						res += sign * (temp*number);
						number = 0;
					}
					else if (c == '/') {
						int temp = st.top(); st.pop();
						sign = st.top(); st.pop();
						 res = st.top(); st.pop();
						res += sign * (temp / number);
						number = 0;
					}
				}
				else {
					res += sign * number;
					
				}
				number = 0;
				sign = -1;
			}
			else if (s[i] == '*') {
				st.push(res);
				st.push(sign);
				st.push(number);
				c = '*';
				sign = 1;
				number = 0;
			}
			else if (s[i] == '/') {
				st.push(res);
				st.push(sign);
				st.push(number);
				c = '/';
				sign = 1;
				number = 0;
			}
		}
		if (number) {
			if (!st.empty()) {
				if (c == '*') {
					int temp = st.top(); st.pop();
					sign = st.top(); st.pop();
					res = st.top(); st.pop();
					res+= sign * (temp*number);
					
				}
				else if (c == '/') {
					int temp = st.top(); st.pop();
					sign = st.top(); st.pop();
				    res = st.top(); st.pop();
					res =res+ sign * (temp / number);
				}
			}
			else {
				res += sign * number;
			}
		}
		return res;
	}
};


class Solution2 {
public:
	int calculate(string s) {
		stack<int> st;
		queue<int> que;
		int res = 0;
		int num = 0;
		int sign = 1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				num = num * 10 + s[i] - '0';
			}
			else if (s[i] == '+') {
				if (que.empty()) {
					res += sign * num;		
				}
				else {
					int temp = cal(que,num);
					res +=sign*temp;
				}	
				num = 0;
				sign = 1;
			}
			else if (s[i] == '-') {
				if (que.empty()) {
					res += sign * num;
				
				}else{
					int temp = cal(que,num);
					res += sign * temp;
				}
				num = 0;
				sign = -1;
			}
			else if (s[i] == '*') {
				que.push(num);
				que.push(3);
				num = 0;
			}
			else if (s[i] == '/') {
				que.push(num);
				que.push(4);
				num = 0;
			}
		}
		if (num != 0) {
			if (que.empty()) {
				res += sign * num;
			}
			else {
				int temp = cal(que, num);
				res += sign * temp;
			}
		}
		return res;
	}



	int cal(queue<int>&que,int num) {
			que.push(num);
			int res = que.front();
			que.pop();
			while (que.size()) {
				int sign = que.front();
				que.pop();
				int temp = que.front();
				que.pop();
				if (sign == 3) {
					res = res * temp;
				}
				else if (sign == 4) {
					res = res / temp;
				}
			}
			return res;
	}
};


class Solution3 {
public:
	int calculate(string s) {
		long num = 0;
		int res = 0;
		stack<int> st;
		char sign = '+';
		for (int i = 0; i < s.size(); i++) {
			
			if (s[i]>= '0'&&s[i]<= '9') {
				num = num * 10 + s[i] - '0';
			}
			if (!(s[i] >= '0'&&s[i] <= '9') && s[i] != ' ' || i == s.size() - 1) {
				if (sign == '+') {
					st.push(num);

				}
				else if (sign == '-') {
					st.push(-num);

				}
				else if (sign == '*') {
					int temp = st.top();
					st.pop();
					st.push(temp*num);
				}
				else if (sign == '/') {
					int temp = st.top();
					st.pop();
					st.push(temp/num);
				}
				sign = s[i];
				num = 0;
			}
		}



		while (!st.empty()) {
			res += st.top();
			st.pop();
		}
		return res;



	}
};


int main() {
	Solution3 mysolu;
	string str1 = "3+2*2";
	string str3 = " 3/2 ";
	string str4 = "1-1";
	string str5 = "2*3+4";
	string str6 = "5-2*3*6";
	int res = mysolu.calculate(str3);
	return 0;

}