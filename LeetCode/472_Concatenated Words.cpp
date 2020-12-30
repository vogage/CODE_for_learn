#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;
bool cmp(const string& str1,const string& str2) {
    return str1.length() < str2.length();
}
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        unordered_set<string> dicts;
        sort(words.begin(), words.end(), cmp);
        for (int i = 0; i < words.size(); i++) {
            if (canform(words[i], dicts))
                res.push_back(words[i]);
            dicts.insert(words[i]);
        }
        return res;
    }

    bool canform(const string& str, const unordered_set<string>& dicts) {
        if (dicts.empty())return false;
        int n = str.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= str.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (!dp[j])continue;
                string temp = str.substr(j, i - j);
                if (dicts.find(temp) != dicts.end()) {
                    dp[i] = true; break;
                }
            }
        }
        return dp[n];
    }
};

class TrieNode {
public:
    vector<TrieNode*> sons;
    bool isEnd;

    TrieNode() {
        sons = vector<TrieNode*>(26,NULL);
        isEnd = false;
    }
};

class Solution2 {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        if (words.size() == 0)return res;
        TrieNode* root = new TrieNode();
        for (auto str : words) {
            addword(root,str);
        }
        for (auto str : words) {
            if (testword(str, 0, root, 0)) res.push_back(str);
        }
        return res;

    }
    bool testword(string& word, int index, TrieNode* root, int count) {
        TrieNode* cur = root;
        for (int i = index; i < word.size(); i++) {
            int temp = word[i] - 'a';
            if (cur->sons[temp] == NULL)return false;
            if (cur->sons[temp]->isEnd) {
                if (i == word.size() - 1) return count >= 1; 
                if (testword(word, i + 1, root, count + 1)) return true;
            }
            cur = cur->sons[temp];
        }
        return false;
    }








    void addword(TrieNode* root, const string& word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.size(); i++) {
            int temp = word[i]-'a';
            if (!cur->sons[temp]) {
      
                cur->sons[temp] = new TrieNode();
            }
            cur = cur->sons[temp];
        }
        cur->isEnd = true;
        return;
    }
};



int main() {
    vector<string> input = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
    Solution2 mysolu;
    vector<string> ans = mysolu.findAllConcatenatedWordsInADict(input);
    return 0;

}