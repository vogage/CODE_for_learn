#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(),greater<int>());
		int i = 0;
		for (; i < citations.size(); i++) {
			if (i+1 > citations[i]) break;
		}
		return i;
	}
};

class Solution2 {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		vector<int> bucket(n+1);
		for (int i = 0; i < n; i++) {
			if (citations[i] > n)  bucket[n]++;
			else bucket[citations[i]]++;
		}

		int count = 0;
		for (int i = n; i >0; i--) {
			count += bucket[i];
			if (count >= i)return i;
		}
		return 0;
	}
};



int main() {
	Solution2 mysolu;
	vector<int> citations = { 3, 0, 6, 1, 5 };
	int res = mysolu.hIndex(citations);
	return 0;
}