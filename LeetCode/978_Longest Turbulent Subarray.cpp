//
//  978_Longest Turbulent Subarray.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/6/3.
//

#include <stdio.h>
#include<vector>


using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        vector<vector<bool>> turbulent(n,vector<bool>(2,false));
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]) turbulent[i][0]=true;
            if(arr[i]<arr[i+1]) turbulent[i][1]=true;
        }
        int res=0;
        int temp=0;
        int index=-1;
        int i=0;
        while(i<n-1){
            if(index>=0&&turbulent[i][index%2]){
                index++;
                temp++;
            }else{
                index=-1;
                res=max(res,temp);
                temp=0;
            }
            if(index==-1){
                if(turbulent[i][0]){
                    index=1;
                    temp++;
                }else if(turbulent[i][1]){
                    index=0;
                    temp++;
                }
            }
            i++;
        }
        res=max(res,temp);
        return res+1;
    }
};

int main(){
    Solution mysolu;
    
    vector<int> arr={9,4,2,10,7,8,8,1,9};
    vector<int> arr1={4,8,12,16};
    vector<int> arr2={100};
    int res=mysolu.maxTurbulenceSize(arr2);
    
    return 0;
}
