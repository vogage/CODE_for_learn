//
//  835_Image Overlap.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/2.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int res=0;
       
        for(int i=-img1.size()+1;i<(int)img1.size();i++){
            for(int j=-img1[0].size()+1;j<(int)img1[0].size();j++){
                res=max(res,cout_overlap(i,j,img1,img2));
            }
        }
        return res;
    }
    int cout_overlap(int BeginI,int BeginJ,vector<vector<int>> &img1,vector<vector<int>>& img2){
        int res=0;
        for(int i=max(0,BeginI);i<min(img1.size(),BeginI+img1.size());i++){
            for(int j=max(0,BeginJ);j<min(img1[i].size(),BeginJ+img1[i].size());j++){
                if(img2[i][j]&&img1[i-BeginI][j-BeginJ])res++;
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> img1={{1,1,0},{0,1,0},{0,1,0}};
    vector<vector<int>> img2={{0,0,0},{0,1,1},{0,0,1}};
    int res=mysolu.largestOverlap(img1, img2);
}
