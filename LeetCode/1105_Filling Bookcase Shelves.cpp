#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 0; i < books.size(); i++) {
            dp[i + 1] = dp[i] + books[i][1];
            int width = books[i][0];
            for (int j = i - 1; j >= 0 ; j--) {
                width += books[j][0];
                if (width > shelfWidth) break;
                int maxheight = max(books[i][1], books[j][1]);
                dp[i + 1] =min(dp[i+1], dp[j] + maxheight);
            }
        }
       
        return dp[n];
    }
};

struct BookShelf {
    int curIndex;
    int curWidth;
    int curHeight;
    int TotalHeight;
    BookShelf() :curIndex(0), curWidth(0), curHeight(0), TotalHeight(0) {}
    BookShelf(int index, int width, int height, int totalheight) :curIndex(index), curWidth(width), curHeight(height), TotalHeight(totalheight){}
};

class Solution2 {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        //dfs
        BookShelf curshelf;
        int res = INT_MAX;
        dfs(books, shelfWidth,curshelf, res);
        return res;
    }
private:
    void dfs(vector<vector<int>>& books, int shelfWidth, BookShelf curshelf, int& res) {
        if (curshelf.curIndex == books.size()) {
            res = min(res, curshelf.TotalHeight);
            return;
        }
        if (curshelf.TotalHeight >= res) return;
        vector<int> nextbook = books[curshelf.curIndex];
        if (curshelf.curWidth + nextbook[0] > shelfWidth) {
            dfs(books, shelfWidth, BookShelf(curshelf.curIndex + 1, nextbook[0], nextbook[1], curshelf.TotalHeight + nextbook[1]),res);
        }
        else {
            if (curshelf.curHeight < nextbook[1]&&curshelf.curHeight) {
                dfs(books, shelfWidth, BookShelf(curshelf.curIndex + 1,  nextbook[0], nextbook[1], curshelf.TotalHeight + nextbook[1]), res);
            }
            dfs(books, shelfWidth, BookShelf(curshelf.curIndex + 1, curshelf.curWidth + nextbook[0], max(curshelf.curHeight,nextbook[1]), max(curshelf.TotalHeight, curshelf.TotalHeight-curshelf.curHeight+nextbook[1])), res);
        }
    }
};


int main() {
    Solution mysolu;
    vector<vector<int>> books = { {1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2} };
    int shelfwidth = 4;
    int res = mysolu.minHeightShelves(books, shelfwidth);
    return 0;
}