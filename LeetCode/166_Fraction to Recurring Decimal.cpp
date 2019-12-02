#include<stdio.h>
#include<string>

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

int main() {
	int numerator = 4;
	int denominator = 333;
	
	Solution mysolu;
	string ans = mysolu.fractionToDecimal(numerator, denominator);
	return 0;
}