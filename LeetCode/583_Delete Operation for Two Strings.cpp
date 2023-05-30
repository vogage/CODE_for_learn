#include<string>
#include<vector>
using namespace std;


//583. Delete Operation for Two Strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        if (n1 == 0)return n2;
        if (n2 == 0)return n1;
        vector<vector<int>> word1toword2(n1, vector<int>(n2, 0));
        vector<vector<int>> word2toword1(n2, vector<int>(n1, 0));
        int res = 0;
        for (int j = 0; j < n2; j++) {
            if(word1[0]==word2[j]) word1toword2[0][j] = 1;
            res = max(res, word1toword2[0][j]);
        }
        for (int i = 1; i < n1; i++) {
            if (word1[i] == word2[0]) word1toword2[i][0] = 1;
            res = max(res, word1toword2[i][0]);
            for (int j = 1; j<n2; j++) {
                if (word1[i] != word2[j]) {
                    word1toword2[i][j] = word1toword2[i][j - 1];
                }
                else {
                    word1toword2[i][j] = max(word1toword2[i][j-1], 1 + word1toword2[i-1][j-1]);
                }
                res = max(res, word1toword2[i][j]);
            }
        }
   

        return n1 + n2 - res*2;

    }
};
int main() {
    string word1= "sea", word2 ="eat" ;
    string w1 = "leetcode", w2 = "etco";
    string ww1 = "mart";
    string ww2 = "karma";
    string w3 = "a";
    string w4 = "ab";
    Solution mysolu;
    int res = mysolu.minDistance(w3, w4);
	return 0;
}