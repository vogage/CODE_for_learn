#include<vector>

using namespace std;

	//There are buckets of liquid, where exactly one of the buckets is poisonous.
	//To figure out which one is poisonous, you feed some number of(poor) pigs the liquid to see whether they will die or not.
	//Unfortunately, you only have minutesToTest minutes to determine which bucket is poisonous.
	//
	//You can feed the pigs according to these steps :
	//
	//Choose some live pigs to feed.
	//For each pig, choose which buckets to feed it.The pig will consume all the chosen buckets simultaneously and will take no time.
	//Wait for minutesToDie minutes.You may not feed any other pigs during this time.
	//After minutesToDie minutes have passed, any pigs that have been fed the poisonous bucket will die, and all others will survive.
	//Repeat this process until you run out of time.
	//Given buckets, minutesToDie, and minutesToTest, 
	//return the minimum number of pigs needed to figure out which bucket is poisonous within the allotted time.

class Solution {
public:

	//Input : buckets = 1000, minutesToDie = 15, minutesToTest = 60
	//Output : 5
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int pigs = 1;

		while (pow(((minutesToTest / minutesToDie) + 1), pigs) < buckets) {
			//int total = pow(((minutesToTest / minutesToDie) + 1) ,pigs);
			pigs++;
		}
		return pigs;
	}
};


int main() {
	int buckets = 1000, minutesToDie = 15, minutesToTest = 60;
	Solution mysolu;
	int res = mysolu.poorPigs(buckets, minutesToDie, minutesToTest);
	return 0;
}