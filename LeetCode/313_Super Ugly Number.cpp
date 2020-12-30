#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct Node
{
public:
	int value;
	Node* prev;
	Node* next;
public:
	Node() { }
	Node(int t, Node* prev, Node* next) {
		this->value = t;
		this->prev = prev;
		this->next = next;
	}
};


class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
	/*	n = 12, primes = [2, 7, 13, 19]
		[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]*/
		if (n < 1)return 0;
		if (n <= primes.size()) return primes[n - 1];
		Node* p = new Node(1, NULL, NULL);
		p->next = new Node(primes[0], p, NULL);
		//p->next->next = new Node(primes[1] * primes[1], p->next, NULL);
	
		Node* pend = p->next;
		Node* pstart = p->next;

		int i = 2;
		int j = 1;
		while (i <= n) {
			//pstart and pend produce
			

		}

		
	
		
	}
};

class Solution2 {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res; res.push_back(1);
		for (auto i : primes)res.push_back(i);
		double x = 999;
		double begin = -1000;
		double xl = 500;
		int idx = static_cast<int>( (x - begin) / xl);
		for (int i = 0; i < primes.size(); i++) {
			for (int j = i; j < primes.size(); j++) {
				res.push_back(primes[i]*primes[j]);
			}
		}
		sort(res.begin(), res.end());
		
		return 0;

	}
	void addnew(int w,vector<int>&nums) {
		
	}
};

class Solution3 {

	public:
		int nthSuperUglyNumber(int n, vector<int>& primes) {
			/*	n = 12, primes = [2, 7, 13, 19]
				[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]*/
			vector<int> ugly(n, 0);
			vector<int> idx(primes.size(), 0);
			ugly[0] = 1;
			for (int i = 1; i < n; i++) {
				//find next
				ugly[i] = INT_MAX;
				for (int j = 0; j < primes.size(); j++) {
					ugly[i] = min(ugly[i], primes[j] * ugly[idx[j]]);
				}
				//slip duplicate
				for (int j = 0; j < primes.size(); j++) {
					while (primes[j] * ugly[idx[j]] <= ugly[i]) idx[j]++;
				}
			}
			return ugly.back();
		}

};


class Solution4 {

public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		/*	n = 12, primes = [2, 7, 13, 19]
			[1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]*/
		vector<int> ugly(n, 0);
		vector<int> idx(primes.size(), 0);
		vector<int> val(primes.size(), 1);
		int next = 1;
		for (int i = 0; i < n; i++) {
			ugly[i] = next;
			next = INT_MAX;
			for (int j = 0; j < primes.size(); j++) {
				if (val[j] == ugly[i]) val[j] = ugly[idx[j]++] * primes[j];
				next = min(next, val[j]);
			}
		}
		return ugly.back();
	}

};
int main() {
	Solution4 mysolu;
	vector<int> input = { 2,7,13,19};
	int ans = mysolu.nthSuperUglyNumber(12,input);
	return 0;

}