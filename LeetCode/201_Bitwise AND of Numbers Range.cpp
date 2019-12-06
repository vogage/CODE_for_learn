#include<stdio.h>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	
		int rangeBitwiseAnd(int m, int n) {
			int i = 0;
			while (m != n) {
				m >>= 1;
				n >>= 1;
				++i;
			}
			return (m << i);
		}
	
};


int main() {
	Solution mysolu;
	int m = 5;
	int n = 7;
	int res = mysolu.rangeBitwiseAnd(m, n);

	
	return 0;

}

