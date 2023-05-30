#include<stdio.h>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		queue<int> v1;
		queue<int> v2;
		int temp = 0;
		for (int i = 0; i < version1.size(); i++) {
			if (version1[i] != '.') {
				temp = temp * 10 + version1[i] - '0';
			}
			else {
				v1.push(temp);
				temp = 0;
			}
		}
		v1.push(temp);
		temp = 0;
		for (int i = 0; i < version2.size(); i++) {
			if (version2[i] != '.') {
				temp = temp * 10 + version2[i] - '0';
				
			}
			else {
				v2.push(temp);
				temp = 0;
			}
		}
		v2.push(temp);
		int p1 = 0;
		int p2 = 0;
		while (!v1.empty() ||!v2.empty()) {
			if (!v1.empty()) {
				p1 = v1.front();
				v1.pop();
			}
			if (!v2.empty()) {
				p2 = v2.front();
				v2.pop();
			}
			if (p1 > p2)return 1;
			if (p1 < p2)return -1;
			p1 = 0;
			p2 = 0;
		}
		return 0;
	}
};

int main() {
	Solution mysolu;
	string version1 = "0.1";
	string version2 = "1.0";
	int res = mysolu.compareVersion(version1, version2);
	return 0;
}