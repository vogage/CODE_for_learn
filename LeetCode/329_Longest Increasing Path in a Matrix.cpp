#include<stdio.h>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;


class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int res=0;
       
       

       // unordered_map<int,bool> index_map;
        unordered_map<int, pair<int,int>> index_length;
        //pair<int, int> pp = { 0,1 };

        //index_set.insert(pp);
        //unordered_set<pair<int, int>, pair_hash>::iterator it = index_set.find(pp);
        //index_set.erase(it);
        //pair<int, int>pp2 = { 0,2 };  
        //index_set.insert(pp2);


        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int global_temp2 = 1;
                int global_temp_tail = matrix[i][j];
                HELP(matrix, i, j, index_length, global_temp_tail, global_temp2);
              
                
                res = max(res, global_temp2);
                int p = get_index(i, j);
                index_length[p].first = global_temp2;
                index_length[p].second = global_temp_tail;
            }
        }
        return res;
    }
    
    void HELP(vector<vector<int>>& matrix, int i, int j, unordered_map<int,pair<int,int>>&index_length,
        int& global_temp_tail,int& global_temp2) {
        unordered_map<int, bool> index_map;
        int p = get_index(i, j);
        index_map[p] = true;
        int temp2 = 1;
        int temp_tail = matrix[i][j];

        //left
       
      
        DFS(matrix, i, j - 1, index_map, index_length,temp2,temp_tail, global_temp2, global_temp_tail);
        //right
      
      
        DFS(matrix, i, j + 1, index_map, index_length,temp2, temp_tail, global_temp2, global_temp_tail);
        //up
       
      
        DFS(matrix, i - 1, j, index_map, index_length,  temp2, temp_tail,global_temp2, global_temp_tail);
        //down

        DFS(matrix, i + 1, j, index_map, index_length,temp2, temp_tail,global_temp2, global_temp_tail);
 
        

    }
    void DFS(vector<vector<int>>& matrix, int i, int j,
        unordered_map<int, bool> index_map,
    unordered_map<int, pair<int, int>>& index_length,
       int temp2,int temp_tail, int& global_temp2, int& global_temp_tail) {
        if (i < 0 || i >= matrix.size())return;
        if (j < 0 || j >= matrix[0].size())return;
        int p = get_index(i, j);

        if (index_map[p]) return;
       

        if (temp_tail < matrix[i][j]) {
            if (index_length[p].first) {
                //temp_tail = index_length[p].second;
                temp2 = temp2 + index_length[p].first;
            }
            else {
                temp_tail = matrix[i][j];
                //temp2++;
                index_map[p] = true;
                //left
 
                temp2++;
                DFS(matrix, i, j - 1, index_map, index_length, temp2, temp_tail, global_temp2, global_temp_tail);
                //right
                DFS(matrix, i, j + 1, index_map, index_length, temp2, temp_tail, global_temp2, global_temp_tail);
                //up
                DFS(matrix, i - 1, j, index_map, index_length, temp2, temp_tail, global_temp2, global_temp_tail);
                //down
                DFS(matrix, i + 1, j, index_map, index_length, temp2, temp_tail, global_temp2, global_temp_tail);


            }
            if (temp2 > global_temp2) {
                global_temp2 = temp2;
                global_temp_tail = temp_tail;
            }
        }
   
        //else if (temp2 == global_temp2) {
        //    global_temp_tail = min(global_temp_tail, temp_tail);
        //}
        //else {
        //}
    }
     
        
    

    int get_index(int i, int j) {
        return i * 10 + j;
    }
};


class Solution2 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, i, j, m, n, cache);
                res = max(res, len);
            }
        }
        return res;
    }



private:
    int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& cache) {
        if (cache[i][j] != 0)return cache[i][j];
        int temp = 1;
        for (auto dir : dirs) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j])continue;
            int len = 1 + dfs(matrix, x, y, m, n, cache);
            temp = max(temp, len);
        }
        cache[i][j] = temp;
        return temp;
    }

    vector<vector<int>> dirs = { {1,0},{-1,0},{0,1},{0,-1} };

};


int main() {
    vector<vector<int>> input;
    vector<int> temp= { 9,9,4 };
    input.push_back(temp);
    temp = { 6,6,8 };
    input.push_back(temp);
    temp = { 2,1,1 };
    input.push_back(temp);

    vector<vector<int>> input2;
    temp = { 3,4,5 };
    input2.push_back(temp);
    temp = { 3,2,6 };
    input2.push_back(temp);
    temp = { 2,2,1 };
    input2.push_back(temp);
    temp = { 1,2 };
    vector<vector<int>> input3;
    input3.push_back(temp);

    vector<vector<int>> input4 = { {7,7,5},{2,4,6},{8,2,0} };
    vector<vector<int>>input5 = { {1,4,7,9},{0,3,8,5},{3,6,0,6},{1,4,5,6} };

    Solution mysolu;
    int res = mysolu.longestIncreasingPath(input5);
    return 0;
}