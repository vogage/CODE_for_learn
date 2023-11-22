#include <vector>

using namespace std;
//[minimum, maximum, mean, median, mode]
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        double mean = 0;

        pair<int,int> mode(0,0);
        pair<int, double> mediP(0,0);
        double median = 0;
        int sum_count = 0;

        for (int i = 0; i < count.size(); i++) sum_count += count[i];
        bool odd = (sum_count % 2 == 1);
        int medicnt = sum_count / 2;
        for (int i = 0; i < count.size(); i++) {
            if (count[i]) {
                if (count[i] > mode.first) {
                    mode.first = count[i];
                    mode.second = i;
                }
                mean += (double)(i) * (double)count[i] / (double)sum_count;
                minimum = min(minimum, i);
                maximum = max(maximum, i);
                if (odd) {
                    if (mediP.first <= medicnt && mediP.first + count[i] > medicnt) median = i;
                }
                else {
                    if (mediP.first <= medicnt && mediP.first + count[i] > medicnt) {
                        if (mediP.first  == medicnt) median = ((mediP.second) + (double)i) / 2;
                        else median = i;
                    }
                }
                mediP.first+= count[i];
                mediP.second = i;
            }
        }
        vector<double> res;
        res.push_back((double)minimum);
        res.push_back((double)maximum);
        res.push_back(mean);
        res.push_back(median);
        res.push_back((double)mode.second);
        return res;

    }
};

//count.length == 256
//0 <= count[i] <= 109
//1 <= sum(count) <= 109

int main() {
    Solution mysolu;
    vector<int> count = { 0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
        ,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    vector<int> count1 = { 264, 912, 1416, 1903, 2515, 3080, 3598, 4099, 4757, 5270, 5748, 6451, 7074,
        7367, 7847, 8653, 9318, 9601, 10481, 10787, 11563, 11869, 12278, 12939, 13737,
        13909, 14621, 15264, 15833, 16562, 17135, 17491, 17982, 18731, 19127, 19579,
        20524, 20941, 21347, 21800, 22342, 21567, 21063, 20683, 20204, 19818, 19351,
        18971, 18496, 17974, 17677, 17034, 16701, 16223, 15671, 15167, 14718, 14552,
        14061, 13448, 13199, 12539, 12265, 11912, 10931, 10947, 10516, 10177, 9582,
        9102, 8699, 8091, 7864, 7330, 6915, 6492, 6013, 5513, 5140, 4701, 4111, 3725,
        3321, 2947, 2357, 1988, 1535, 1124, 664, 206, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    vector<int> count2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
        0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    vector<double> res = mysolu.sampleStats(count);
    return 0;
}