#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isAdditiveNumber(string num) {
		//Input: "112358"
		//The digits can form an additive sequence : 1, 1, 2, 3, 5, 8.
		//	1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

		//Input: "199100199"
		//The additive sequence is : 1, 99, 100, 199.
		//	1 + 99 = 100, 99 + 100 = 199
		for (int i = 0; i <= num.size()/2; i++) {
			for (int j = i + 1; j < num.size()-i; j++) {
				string x2 = num.substr(0, i + 1);
				if (x2[0] == '0'&&x2.size() != 1) continue;
				long x = stol(num.substr(0,i+1));
				string y2 = num.substr(i + 1, j - i);
				if (y2[0] == '0'&&y2.size()!=1) continue;
				std::string::size_type sz;
				long y = stol(y2,&sz);
				string z = to_string(x + y);
				if (num.substr(j + 1, z.size()) == z) {
					if (isvalid(x,y,z,num.substr(j+1))) return true;
				}
			}
		}
		return false;
	}
	bool isvalid(long x,long y, string z, string num) {
		if (num== z)return true;
			long zz = stol(z);
			string z2 =to_string( zz + y);
			string cmp = num.substr(z.size(), z2.size());
			string next_num = num.substr(z.size());
			if (z2 == cmp) return isvalid(y, zz, z2, next_num);
			return false;
		
	}
};



//The idea is quite straight forward.Generate the first and second of the sequence, check if the rest of the string match the sum recursively.i and j are length of the first and second number.i should in the range of[0, n / 2].The length of their sum should >= max(i, j)
//
//Java Recursive
//
//import java.math.BigInteger;
//
//public class Solution {
//	public boolean isAdditiveNumber(String num) {
//		int n = num.length();
//		for (int i = 1; i <= n / 2; ++i) {
//			if (num.charAt(0) == '0' && i > 1) return false;
//			BigInteger x1 = new BigInteger(num.substring(0, i));
//			for (int j = 1; Math.max(j, i) <= n - i - j; ++j) {
//				if (num.charAt(i) == '0' && j > 1) break;
//				BigInteger x2 = new BigInteger(num.substring(i, i + j));
//				if (isValid(x1, x2, j + i, num)) return true;
//			}
//		}
//		return false;
//	}
//	private boolean isValid(BigInteger x1, BigInteger x2, int start, String num) {
//		if (start == num.length()) return true;
//		x2 = x2.add(x1);
//		x1 = x2.subtract(x1);
//		String sum = x2.toString();
//		return num.startsWith(sum, start) && isValid(x1, x2, start + sum.length(), num);
//	}
//}
//// Runtime: 8ms

class Solution2 {
public:
	bool isAdditiveNumber(string num) {
		int n = num.size();
		for (int i = 1; i <= n / 2; i++) {
			if (num[0] == '0'&&i > 1)break;
			long long x = stoll(num.substr(0, i));
			for (int j = 1; max(i, j) <= n - i - j; j++) {
				if (num[i] == '0'&&j > 1)break;
				long long y = stoll(num.substr(i, j));
				if (isvalid(x, y, i+j,num)) return true;
			}
		}
		return false;
	}
	bool isvalid(long long x, long long y,int start, string num) {
		if (start == num.size())return true;
		y = x + y;
		x = y - x;
		string cmp = to_string(y);
		string start_substr = num.substr(start, cmp.size());
		return num.substr(start, cmp.size()) == cmp && isvalid(x, y, start+cmp.size(), num);
	}


};


int main() {
	Solution2 mysolu;
	string input = "112358";
	string input2 = "199100199";
	string input3 = "1023";
	string input4 = "0235813";
	string input5 = "19910011992";
	//the range of long 
	//-2147483648~2147483647
	long long enenen = stoll(input5);
	bool res = mysolu.isAdditiveNumber(input);
	return 0;

}