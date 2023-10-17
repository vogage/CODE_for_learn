//
//  1024_Video Stitching.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/10/7.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

//clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], time = 10

bool cmp(vector<int>& v1,vector<int>& v2){
    return v1[0]<v2[0];
}

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),cmp);
        int res=0;
        vector<int> pre_temp={0,0};
        vector<int> next_temp;
        for(int i=0;i<clips.size();i++){
            if(clips[i][0]>pre_temp[1]&&clips[i][0]<=next_temp[1]){
                pre_temp=next_temp;
                res++;
            }
            if(clips[i][)
            
        }
        return -1;
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>> clips={{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
    int time=10;
    vector<vector<int>> clips1={{0,2},{4,8}};
    int time1=5;
    int res=mysolu.videoStitching(clips1, time1);
    return 0;
}
