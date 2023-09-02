//
//  904_Fruit Into Baskets.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int temp=0;
        int total=0;
        int res;
        int backet1=-1,backet2=-1;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i]==backet1){
                temp++;
                total++;
            }else if(fruits[i]==backet2){
                int emptybacket=backet2;
                backet2=backet1;
                backet1=emptybacket;
                temp=1;
                total++;
            }else{
                res=max(res,total);
                backet2=backet1;
                backet1=fruits[i];
                total=temp;
                temp=1;
                total++;
            }
        }
        return max(res,total);
    }
};


int main(){
    Solution mysolu;
    vector<int> nums={1,2,3,2,2};
    int res=mysolu.totalFruit(nums);
    return 0;
}
