#include<queue>
#include<string>
#include <vector>
#include <algorithm>
#include<map> 

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size();
        vector<vector<int>> leftvec=leftcmp(stamp,target);
        vector<vector<int>> rightvec=rightcmp(stamp,target);
        map<int, int> leftindexmap=cntIndex(leftvec);
        map<int, int> rightindexmap=cntIndex(rightvec);
        vector<int> resleft,resright;
        
        for (int i = 0; i < target.size(); i++) {
            if (leftvec[i].size() == 0 && rightvec[i].size() == 0)return vector<int>();
            if (leftvec[i].size() != 0) {
                int index = leftvec[i][0];
                for (int j = 1; j < leftvec[i].size(); j++) {
                    if (leftindexmap[index] < leftindexmap[leftvec[i][j]]) index = leftvec[i][j];
                }
                if (resleft.empty() || index > resleft.back())resleft.push_back(index);
            }
            else {
                int index = rightvec[i][0];
                for (int j = 1; j < rightvec[i].size(); j++) {
                    if (rightindexmap[index] < rightindexmap[rightvec[i][j]]) index = rightvec[i][j];
                }
                if (resright.empty() || (index > resright.back()&&(resleft.empty()||index>resleft.back()))) resright.push_back(index);
            }
        }
        if (leftindexmap[resleft.back()] != stamp.size())return vector<int>();
        reverse(resright.begin(), resright.end());
        resright.insert(resright.end(), resleft.begin(), resleft.end());
        return resright;
    }
private:
    vector<vector<int>> leftcmp(string& stamp, string& target) {
        vector<vector<int>> res(target.size(), vector<int>());
        for (int i = 0; i <= target.size() - stamp.size(); i++) {
            for (int k = 0; k < stamp.size(); k++) {
                if (stamp[k] == target[i + k]) res[i + k].push_back(i);
                else break;
            }
        
        }
        return res;
    }
    vector<vector<int>> rightcmp(string& stamp, string& target) {
        vector<vector<int>> res(target.size(), vector<int>());
        for (int i = target.size() - stamp.size(); i >= 0; i--) {
            for (int k = 0; k < stamp.size(); k++) {
                int end = stamp.size() - 1 - k;
                if (stamp[end] == target[i + end]) res[i + end].push_back(i);
                else break;
            }

        }
        return res;
    }

    map<int, int> cntIndex(vector<vector<int>>& nums) {
        map<int, int> res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                res[nums[i][j]]++;
            }
        }
        return res;
    }
};


int main() {
    Solution mysolu;
    string stamp = "abca";
    string target = "aabcaca";
    string stamp1 = "abc";
    string target1 = "ababc";
    string stamp2 = "h";
    string target2 = "hhhhh";
    string stamp3 = "oz";
    string target3 = "ooozz";
    string stamp4 = "cab";
    string target4 = "cabbb";
    string stamp5 = "de";
    string target5 = "ddeddeddee";
    string stamp6 = "aye";
    string target6 = "eyeye";
    string stamp7 = "lemk";
    string target7 = "lleme";
    string stamp8 = "cbcf";
    string target8 = "ccbbf";
    string stamp9 = "mda";
    string target9 = "mdadddaaaa";
    string stamp10 = "ffebb";
    string target10 = "fffeffebbb";
    string stamp11 = "afc";
    string target11 = "aafcaafacc";
    string stamp12 = "aq";
    string    target12 = "aqaaqaqqqaqqaaq";
    vector<int> res = mysolu.movesToStamp(stamp12, target12);
	return 0;
}
