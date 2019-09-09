#include<stdio.h>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}

class Solution {
public:
	int candy(vector<int>& ratings) {
		//find the miniest
		vector<pair<int, int>> rat;
		for (int i = 0; i < ratings.size(); i++) {
			rat.push_back(pair<int, int>(i, ratings[i]));
		}
		unordered_set<int> s;
		sort(rat.begin(), rat.end(), cmp);
		
		int temp=1;
		int total = 1;
		s.insert(rat[0].first);
		for (int i = 1; i < rat.size(); i++) {
			if (s.find(rat[i].first - 1) == s.end() && s.find(rat[i].first + 1) == s.end()) {
				temp=1;
				
			}
			else {
				unordered_set<int>::iterator it;
				it = s.find(rat[i].first - 1);
				if (it != s.end()) {
					if(ratings[rat[i].first-1]>rat[i].second)temp++;
				}
				it = s.find(rat[i].first + 1);
				if (it != s.end()) {
					if (ratings[rat[i].first + 1] > rat[i].second)temp++;
				}
				
			}
			s.insert(rat[i].first);
			total += temp;
		}
		return total;
		
	}
	
};

int main() {
	vector<int> input = { 1,3,2,2,1 };
	Solution mysolu;
	int res = mysolu.candy(input);
	return res;

}