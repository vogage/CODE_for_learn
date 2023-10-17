//
//  955_Delete Columns to Make Sorted II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/11.
//

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int NotINorder=0;
        int n=strs.size();
        vector<bool> preIsSame(n-1,true);
        for(int k=0;k<strs[0].size();k++){
           bool IsAready=true;
            vector<bool> temppre=preIsSame;
            int i=0;
            for(;i<strs.size()-1;i++){
                if(strs[i][k]==strs[i+1][k]&&preIsSame[i]){
                    temppre[i]=true;
                    IsAready=false;
                }else if(strs[i][k]>strs[i+1][k]&&preIsSame[i]){
                    NotINorder++;
                    IsAready=false;
                    break;
                }else{
                    temppre[i]=false;
                }
                
            }
            if(IsAready) return NotINorder;
            else if(i==strs.size()-1) preIsSame=temppre;
        }
        return NotINorder;
    }
};

int main(){
    Solution mysolu;
    vector<string> strs = {"ca","bb","ac"};
    vector<string> strs1= {"xga","xfb","yfa"};
    vector<string> strs2={"abx","agz","bgc","bfc"};
    int res=mysolu.minDeletionSize(strs1);
    return 0;
    
}
