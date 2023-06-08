//
//  519_Random Flip Matrix.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/7.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;
 
//There is an m x n binary grid matrix with all the values set 0 initially.
//Design an algorithm to randomly pick an index (i, j) where matrix[i][j] == 0 and flips it to 1.
//All the indices (i, j) where matrix[i][j] == 0 should be equally likely to be returned.
//
//Optimize your algorithm to minimize the number of calls made to the built-in random function of your language and optimize the time and space complexity.
//
//Implement the Solution class:
//
//Solution(int m, int n) Initializes the object with the size of the binary matrix m and n.
//int[] flip() Returns a random index [i, j] of the matrix where matrix[i][j] == 0 and flips it to 1.
//void reset() Resets all the values of the matrix to be 0.



class Solution {
public:
    Solution(int m, int n) {
        M=m;
        N=n;
        IndexVec=vector<int>(m*n,0);
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                IndexVec[i*N+j]=i*N+j;
            }
        }
        reset();
    }
    
    vector<int> flip() {
        vector<int> res;
        int id=rand()%cnt;
        res.push_back(IndexVec[id]/M);
        res.push_back(IndexVec[id]%M);
        IndexVec[id]=IndexVec[cnt-1];
        cnt--;
        return res;
    }
    
    void reset() {
        cnt=M*N;
       
    }
private:
    vector<int> IndexVec;
    int M;
    int N;
    int cnt;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */

int main(){
//    Input
//    ["Solution", "flip", "flip", "flip", "reset", "flip"]
//    [[3, 1], [], [], [], [], []]
//    Output
//    [null, [1, 0], [2, 0], [0, 0], null, [2, 0]]
    
    int m=3;
    int n=1;
    Solution *obj=new Solution(m,n);
    vector<int> param_1=obj->flip();
    vector<int> param_2=obj->flip();
    vector<int> param_3=obj->flip();
    obj->reset();
    vector<int> param_4=obj->flip();
}
