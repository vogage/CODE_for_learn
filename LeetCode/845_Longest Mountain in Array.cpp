//
//  845_Longest Mountain in Array.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/4/23.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        int res=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]) right[i]=right[i+1]+1;
            
        }
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]) left[i]=left[i-1]+1;
            res=max(res,right[i]+left[i]+1);
        }
        return res;
    }
};





class Solution2 {
public:
    int longestMountain(vector<int>& arr) {
        int left=0;
        int right=1;
        bool up=false;
        bool down=false;
        int res=0;
        while(right<arr.size()){
            while(right<arr.size()&&arr[right]>arr[right-1]){
                right++;
                up=true;
            }
            while(right<arr.size()&&arr[right]<arr[right-1]){
                right++;
                down=true;
            }
            
            if(up&&down){
                res=max(res,right-left);
                left=right-1;
                up=false;
                down=false;
            }else if(down&&!up){
                left=right-1;
                down=false;
            }
            while(right<arr.size()&&arr[right]==arr[right-1]){
               
                left=right;
                right++;
                up=false;
                down=false;
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> arr = {2,1,4,7,3,2,5};
    vector<int> arr1={2,2,2};
    vector<int> arr2={2,3};
    vector<int> arr3={0,2,0,2,1,2,3,4,4,1};
    vector<int> arr4={1,1,0,0,1,0};
    vector<int> arr5={875,884,239,731,723,685};
    vector<int> arr6={7,4,8};
    int res=mysolu.longestMountain(arr5);
    
    return 0;
}
