#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        chs=vector<pair<long long, int>>({ {1,1} });
        target_map[1] = 1;
       
        long long temp = x, cout = 0;
        while (temp < target) {
            chs.push_back({ temp,cout });
            target_map[temp] = cout;
            temp = temp * x;
            cout++;
        }
        chs.push_back({ temp,cout });
        target_map[temp] = cout;
        cout = 0;
        int res = INT_MAX;
        dfs((long long)target, cout, res);
        return res;
    }
private:
    void dfs(long long target, int cout, int& res) {
       
        if (target == 0) {
            res = min(res, cout - 1);
            return;
        }
        if (cout >= res)return;
        //if (target == 12618) {
        //    int step1 = 1;
        //}
        //if (target == 504) {
        //    int step2 = 2;
        //}
        if (target_map.find(target) != target_map.end()) {
            res = min(res, cout + target_map[target]);
            return;
        }

        int i = 0;
        for (; i < chs.size(); i++) {
            if (chs[i].first > target) break;
        }
        // target-small
        int n = target / chs[i - 1].first;


        dfs(target - n*chs[i - 1].first, cout + n*(chs[i - 1].second+1), res);
        dfs(chs[i].first - target, cout + chs[i].second + 1, res);

        return ;
    }
       

   
      

    unordered_map<long long, int> target_map;
    vector<pair<long long, int>> chs;
};

class Solution1 {
public:
    int leastOpsExpressTarget(int x, int target,vector<int>& path) {
        // At this time, you can get target either by add target times x/x or subtract (x - target) times x/x to x
        // For example, x = 3, target = 2. Then, 3/3 + 3/3 or 3 - 3/3 is possible result
        if (x > target) {
           
            return min(target * 2 - 1, (x - target) * 2);

        }
        if (x == target) {  // just push x at the end
           
            return 0;
        }

        long long sums = x;
        int times = 0;
        while (sums < target) {  // this is gready, put as much as possible 'x'
            times++;
            sums *= x;
        }

        if (sums == target) {  // one more 'x' you put, one more operator
            return times;
        }

        // when you have remainder, you have two choices, one is add, the other is subtract
        // for example, x = 3, target = 5. Then, 5 = 3 + 2 or 5 = 9 - 4
        int l = INT_MAX, r = INT_MAX;
        vector<int> path1=path;
        vector<int> path2=path;
        path1.push_back(sums - target);
        path2.push_back(target - (sums / x));

        if (sums - target < target) {
            l = leastOpsExpressTarget(x, sums - target,path1) + times;  // using subtract
        }
        r = leastOpsExpressTarget(x, target - (sums / x),path2) + times - 1;  // using add
        
        if (l < r) {
            path = path1;
        }
        else {
            path = path2;
        }
        return min(l, r) + 1;  // No matter +/- used, one more operator is add
    }
    
};


int main() {
    Solution mysolu;
    int x =3, target = 19;
    int x1 = 100, target1 = 100000000;
    int x2 = 5, target2 = 501;
    int x3 = 79, target3 = 155800339;
    int x4 = 97, target4 = 178890910;
    int x5 = 3, target5 = 55125018;
    vector<int> global_path;
    int res = mysolu.leastOpsExpressTarget(x5, target5);

	return 0;
}