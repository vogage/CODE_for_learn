#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		//假设都是从小数点之后开始循环
		//two two once a time see
		int head = numerator / denominator;
		int tail = numerator % denominator;
		if (tail == 0)return to_string(head);
		int length = 1;		
	
		string temp1 =to_string(tail*10/denominator);
		int tail_first = (tail * 10) % denominator;
		if (!tail_first) return to_string(head) + "." + temp1;
		while (true) {
			
			
			string temp2 = "";
			tail = tail_first;
			for (int i = 0; i < length; i++) {
				
				tail = tail * 10;
				temp2 += to_string(tail / denominator);
				tail = tail % denominator;
				if (i == 0) tail_first = tail;
				if (tail == 0) {					
					return to_string(head) + "." + temp1 + temp2;
				}
			}
			if (temp1 == temp2) break;
			else {
				temp1 += temp2[0];
			}
			length=length+1;
		}
		return to_string(head) + "." + "(" + temp1 + ")";
	}
};

class Solution2 {
public:
	string fractionToDecimal(int numerator, int denominator) {
		int head = numerator / denominator;
		int tail = numerator % denominator;
		if (tail == 0)return to_string(head);
		string str = "";
		bool flag = false;
		int size = 0;
		while (!flag) {
			cal_next_string(tail, denominator, str);
			if (tail == 0) return to_string(head) + "." + str;
			judge_circular(tail, str, flag, size);
		}
	
			return to_string(head) + "." + str.substr(0, str.size() - size * 2) + "(" + str.substr(str.size() - size, size) + ")";
	

	}

	void cal_next_string(int& tail, int& denominator, string& str) {
		tail = tail * 10;
		str += to_string(tail/denominator);
		tail = tail % denominator;
		return;
	}
	void judge_circular(int tail, string str,bool& flag,int& size) {
		int n =str.size();
		for (int i = 0; i < n / 2; i++) {
			string temp1 = str.substr(n - i - 1, i+1);
			string temp2 = str.substr(n - i * 2 - 2, i+1);
			if (temp1 == temp2 && !(temp1 == "0"&& temp2 == "0")) {
				flag = true;
				size = i + 1;
				return;
			}
		}
		return;

	}
};
class Solution3 {
public:
	string fractionToDecimal(int numerator, int denominator) {

		string str = "";
		if (numerator == 0)return "0";
		if ((numerator < 0 )^ (denominator < 0)) {
			str = "-";

		}
		long num = abs(numerator);
		long den = abs(denominator);
		long head = num / den;
		long tail = num % den;
		str += to_string(head);
		if (tail == 0)return str;
		str += ".";
		unordered_map<long, int> m;
		m[tail] = str.size();
		while (tail) {

			tail = tail * 10;
			str += to_string(tail / denominator);
			tail = tail % denominator;
			if (m.find(tail) == m.end()) {
				m[tail] = str.size();
			}
			else {
				int index = m[tail];
				string str1 = str.substr(0, index);
				string str2 = str.substr(index, str.size() - index);
				str = str1 + "(" + str2 + ")";
				break;
			}
		}
		return str;
	}
};

int main() {
	int numerator =-1;
	int denominator =-2147483648;
	
	Solution3 mysolu;
	string ans = mysolu.fractionToDecimal(numerator, denominator);
	return 0;
}