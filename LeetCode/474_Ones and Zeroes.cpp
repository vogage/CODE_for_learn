//
//  474_Ones and Zeroes.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/27.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;



//Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
//Output: 4
//Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
//Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
//{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> nums=cntchar(strs);
        unordered_map<int, int> subsets_map;
        subsets_map[0]=0;
        int res=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int, int> temp_subsets_map=subsets_map;
            for(auto candi:subsets_map){
                //judge the new index is satisfied the m and n constrictions
                int index_i=candi.first/(n+1)+nums[i].first;
                int index_j=candi.first%(n+1)+nums[i].second;
                if(index_i>m||index_j>n) continue;
                int index=index_i*(n+1)+index_j;
                if(temp_subsets_map.find(index)!=temp_subsets_map.end()){
                    temp_subsets_map[index]=max(temp_subsets_map[index],candi.second+1);
                  
                }else{
                    temp_subsets_map[index]=candi.second+1;
                }
                res=max(res,temp_subsets_map[index]);
            }
           
            subsets_map=temp_subsets_map;
        }
        return res;
    }
private:
    vector<pair<int,int>> cntchar(const vector<string>& strs){
        int n=strs.size();
        vector<pair<int,int>> res(n,pair<int,int>(0,0));
        for(int i=0;i<n;i++){
            int cnt0=0;
            int cnt1=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0') cnt0++;
                if(strs[i][j]=='1') cnt1++;
            }
            res[i].first=cnt0;
            res[i].second=cnt1;
        }
        return  res;
    }
};


int main(){
    Solution mysolu;
    vector<string> strs={"1","0","10","0001","111001"};
    vector<string> strs2={"00","000"};
    int m=5,n=3;
    int res=mysolu.findMaxForm(strs,m,n);
    return 0;
}
