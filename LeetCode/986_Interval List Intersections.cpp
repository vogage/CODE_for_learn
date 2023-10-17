//
//  986_Interval List Intersections.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int k=0;
        vector<vector<int>> res;
        int m=max(firstList.size(),secondList.size());
       // unordered_set<int> visited;
        for(int i=0;i<firstList.size();i++){
            while(secondList[k][1]<firstList[i][0]) k++;
            for(int j=k;j<secondList.size()&&secondList[j][0]<=firstList[i][1];j++){
                int left=max(firstList[i][0],secondList[j][0]);
                int right=min(firstList[i][1],secondList[j][1]);
               // if(left<=right&&visited.find(left*m+right)==visited.end()){
                if(left<=right){
                    res.push_back(vector<int>({left,right}));
                    //visited.insert(left*m+right);
                }
            }
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    vector<vector<int>> res=mysolu.intervalIntersection(firstList, secondList);
    return 0;
}
