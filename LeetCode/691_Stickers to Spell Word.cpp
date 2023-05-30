//We are given n different types of stickers. Each sticker has a lowercase English word on it.
//
//You would like to spell out the given string target by cutting individual letters from your collection of stickersand rearranging them.
//You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
//
//Return the minimum number of stickers that you need to spell out target.If the task is impossible, return -1.
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        unordered_set<string> visited;
        for (int i = 0; i < stickers.size(); i++) {             
            for (int j = 0; j < stickers[i].size(); j++) {
                char_sticker_map[stickers[i][j]][stickers[i]]++;
            }
        }
        unordered_map<char, int> target_map;
        for (int i = 0; i < target.size(); i++) {
            target_map[target[i]]++;
        }

        int res = INT_MAX;
        dfs(char_sticker_map, target_map,visited, 0, res);
        return res==INT_MAX?-1:res;
    }

private:
    typedef unordered_map<char, unordered_map<string, int>> bag_map;
    bag_map char_sticker_map;
    
    
private:
    void dfs(bag_map& char_sticker_map, unordered_map<char, int>& target_map, 
        unordered_set<string>& visited,int temp, int& res) {
        if (temp >= res)return;
        if (empty_target_map(target_map)) {
            res = min(res, temp);
            return;
        }
        for (auto c : target_map) {
            if (c.second == 0) continue;
            for (auto sticker : char_sticker_map[c.first]) {      
                if (visited.find(sticker.first) != visited.end())continue;
                unordered_map<char, int> temp_target_map = target_map;
                unordered_set<string> temp_visited;
               if (put_sticker(sticker, temp_target_map)) {
                   temp_visited.insert(sticker.first);
                    dfs(char_sticker_map, temp_target_map,temp_visited, temp + 1, res);
                    
                }            
            }
        }       
    }
    
    bool put_sticker(const pair<string, int>& sticker, unordered_map<char, int>& target_map) {
        bool changed = false;
        for (int i = 0; i < sticker.first.size(); i++) {
            if (target_map.find(sticker.first[i]) != target_map.end()) {
             
                if (target_map[sticker.first[i]] > 0) {
                    changed = true;
                    target_map[sticker.first[i]]--;
                }
            }
        }
        return changed;
    }
    bool empty_target_map(unordered_map<char, int>& target_map) {
        for (auto c : target_map) {
            if (c.second != 0)return false;
        }
        return true;
    }



};

class Solution2 {
public:
    int minStickers(vector<string>& stickers, string target) {
        for (int i = 0; i < stickers.size(); i++) {
            vector<int> sticker_chars(26,0);
            for (int j = 0; j < stickers[i].size(); j++) {
                sticker_chars[stickers[i][j] - 'a']++;
            }
            st_map[stickers[i]] = sticker_chars;
        }

        unordered_map<string, int> dp;
        dp[""] = 0;
        return dfs(target, st_map,dp)==INT_MAX?0:dp[target];
        
    }
private:
    typedef unordered_map<string, vector<int>> stickers_map;
    stickers_map st_map;

private:
    int dfs(string& target, stickers_map& st_map,unordered_map<string,int>& dp) {
        if (dp.find(target)!=dp.end())return dp[target];
        vector<int> target_num(26, 0);
        for (int i = 0; i < target.size(); i++) {
            target_num[target[i]-'a']++;
        }
        dp[target] = INT_MAX;
        for (auto sticker_chars : st_map) {
            int tar = target[0];
            if (sticker_chars.second[tar - 'a'] > 0) {
                string sub_target = "";
                for (int i = 0; i < sticker_chars.second.size(); i++) {
                    if (target_num[i] - sticker_chars.second[i] > 0) {
                        for (int j = 0; j < target_num[i] - sticker_chars.second[i]; j++) sub_target += (i+ 'a');
                        
                    }
                }
                int temp = dfs(sub_target, st_map, dp);
                dp[target] = min(dp[target], temp==INT_MAX?INT_MAX:temp+ 1);
            }
           
        }
        return dp[target];
    }

};

int main() {
    vector<string> stickers = { "with", "example", "science" };
    string target = "thehat";

    vector<string> stickers1 = { "bring", "plane", "should", "against", "chick" };
    string target1 = "greatscore";

    vector<string> stickers2 = { "notice", "possible" };
    string target2 = "basicbasic";
     
    Solution2 mysolu;
    int res = mysolu.minStickers(stickers2, target2);

    return 0;
}
