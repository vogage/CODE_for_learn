//
//  498_Diagonal Traverse.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/6.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        if(mat.size()==0) return res;
        if(mat.size()==1)return mat[0];
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> trajmat;
        //first part
        
        int cnt=0;
        for(int k=0;k<m&&k<n;k++){
            int i=k;
            int j=0;
            vector<int> tempres={};
            for(int h=0;h<=k;h++){
                int tempi=k-h;
                int tempj=j+h;
                tempres.push_back(mat[tempi][tempj]);
            }
            trajmat.push_back(tempres);
        }
        
        //second part
        for(int k=1;k+n<=m;k++){
            int i=n-1;
            int j=k;
            vector<int> tempres={};
            for(int h=0;h<n;h++){
                int tempi=i-h;
                int tempj=j+h;
                tempres.push_back(mat[tempi][tempj]);
            }
            trajmat.push_back(tempres);
        }
        
        //third part
        for(int k=0;k+m<n;k++){
            int i=k+m;
            int j=0;
            vector<int> tempres={};
            for(int h=0;h<m;h++){
                int tempi=i-h;
                int tempj=j+h;
                tempres.push_back(mat[tempi][tempj]);
            }
            trajmat.push_back(tempres);
        }
        
        //fourth part
        for(int k=min(m,n)-1;k>0;k--){
            int i=n-1;
            int j=m-k;
            vector<int> tempres={};
            for(int h=0;h<k;h++){
                int tempi=i-h;
                int tempj=j+h;
                tempres.push_back(mat[tempi][tempj]);
            }
            trajmat.push_back(tempres);
        }
        
        
        for(int i=0;i<trajmat.size();i++){
            if(cnt%2==0){
                for(int j=0;j<trajmat[i].size();j++){
                    res.push_back(trajmat[i][j]);
                }
            }else{
                for(int j=trajmat[i].size()-1;j>=0;j--){
                    res.push_back(trajmat[i][j]);
                }
            }
            cnt++;
        }
        return res;
    }
private:
    
};

int main(){
    Solution mysolu;
    vector<vector<int>> mat={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> mat2={{2,5,8},{4,0,-1}};
    vector<int> res=mysolu.findDiagonalOrder(mat);
    return 0;
}
