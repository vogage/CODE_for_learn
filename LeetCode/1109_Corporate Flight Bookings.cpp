#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int, pair<int, int>> flightMaP;
      
        for (int i = 0; i < bookings.size(); i++) {
            flightMaP[bookings[i][0]].first += bookings[i][2];
            flightMaP[bookings[i][1]].second += bookings[i][2];
        }
        int cur = 0;
        int label = 1;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (flightMaP.find(i + 1) != flightMaP.end()) {
                cur += flightMaP[i+1].first;
                res[i] = cur;
                cur -= flightMaP[i+1].second;
            }
            else {
                res[i] = cur;
            }
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<vector<int>> bookings = { {1,2,10} ,{2,3,20},{2,5,25} };
    int n = 5;
    vector<int> res = mysolu.corpFlightBookings(bookings, n);
    return 0;
}