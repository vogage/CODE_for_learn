#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<int>> DistMaP;
        for (int i = 0; i < points.size(); i++) {
            DistMaP[points[i][0] * points[i][0] + points[i][1] * points[i][1]].push_back(i);
        }
        int cnt = 0;
        vector<vector<int>> res;
        auto m = DistMaP.begin();
        for (; m != DistMaP.end(); m++) {
            cnt +=m->second.size();
            for (int i = 0; i < m->second.size(); i++) {
                res.push_back(points[m->second[i]]);
            }
            if (cnt >= k) break;
        }
      
      
        return res;
    }
};

int main() {
    Solution mysolu;
    vector<vector<int>>points = { {3, 3},{5, -1},{-2, 4} };
    int k = 2;
    vector<vector<int>> res = mysolu.kClosest(points, k);
	return 0;
}