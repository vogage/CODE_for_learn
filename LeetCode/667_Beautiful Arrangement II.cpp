//
//  667_Beautiful Arrangement II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/21.
//

#include <stdio.h>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> constructArray(int n, int k) {
        //1 <= k < n <= 104
        vector<int> res;
        int left=1;
        int right=left+k;
        while(right-left>1){
            res.push_back(left);
            left++;
            res.push_back(right);
            right--;
        }
        
        if(left==right) res.push_back(left);
        else{
            res.push_back(left);
            res.push_back(right);
        }
        for(int i=res.size()+1;i<=n;i++){
            res.push_back(i);
        }
        return res;
    }
};


int main(){
    Solution mysolu;
    
    vector<int> res=mysolu.constructArray(10, 3);
    
    return 0;
}
