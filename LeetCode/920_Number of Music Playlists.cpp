#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(goal + 1, vector<int>(n + 1,0));
        int temp = 1;
        int mod = 1e9 + 7;
        for (int i =0; i <= k; i++) temp = temp *(n-i);
        dp[k+1][k+1] = temp;
        for (int i = k + 2; i <= goal; i++) {
            //the number of used song
            for (int j = k +1; j <= n&&j<=i; j++) {
                //use the new song + don't use the new song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1) + dp[i - 1][j] * (j-k);
                dp[i][j] = dp[i][j] % mod;
            }
        }
        return dp[goal][n];
    }
};

class Solution2 {
public:
    int numMusicPlaylists(int n, int goal, int k) {
       //top-down dynamic
        int new_music = n;
        int old_music = 0;

        res = 0;
        songs = n;
        mod = 1e9 + 7;
        playlist = vector<int>(goal+1, -1);
        playlist[0] = 1;
        dfs(new_music, old_music,1, 1, goal, k);
        return (int) res;
    }
private:
    vector<int> playlist;
    int songs;
    int mod;
    long res;
    void dfs(int new_music, int old_music,int temp, int index, int goal, int k) {
        if (index > goal) {
            if (old_music == songs) {
                res += temp;
                res = res % mod;
            }
               return;
        }
  
        //choice new_music
        if (new_music >= 0) {
            int num_new_music = temp * new_music;
            dfs(new_music - 1, old_music + 1, num_new_music, index + 1, goal, k);
        }
        //choice old_music
        if (new_music > goal - index) return;
        int num_old_music = old_music - k>=0? temp * (old_music - k):0;
        dfs(new_music, old_music, num_old_music, index + 1, goal, k);
    }

    
};

int main() {
    int n = 3;
    int goal = 3;
    int k = 1;
    int n1 = 2;
    int goal1 = 3;
    int k1 = 0;
    int n2 = 2;
    int goal2 = 3;
    int k2 = 1;
    Solution mysolu;
    int res = mysolu.numMusicPlaylists(n, goal, k);
    return 0;
}