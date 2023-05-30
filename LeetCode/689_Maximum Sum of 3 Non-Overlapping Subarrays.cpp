//
//  689_Maximum Sum of 3 Non-Overlapping Subarrays.cpp
//  leetcode
//
//  Created by qiandehou on 2022/3/15.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        //construct sums of k nums
        if(3*k>nums.size())return vector<int>();
        vector<int> sums;
        int temp_sum=0;
        for(int i=0;i<k;i++){temp_sum+=nums[i];}
        sums.push_back(temp_sum);
        for(int i=k;i<nums.size();i++){
            temp_sum=temp_sum-nums[i-k]+nums[i];
            sums.push_back(temp_sum);
        }
        
        vector<pair<int,int>> left_max;
        vector<pair<int,int>> right_max;
        pair<int,int> tmp({INT_MIN,0});
        for(int i=0;i<sums.size();i++){
            if(tmp.first<sums[i]){tmp.first=sums[i];tmp.second=i;}
            left_max.push_back(tmp);
        }
        tmp=pair<int,int>({INT_MIN,0});
        for(int i=sums.size()-1;i>=0;i--){
            if(tmp.first<=sums[i]){tmp.first=sums[i];tmp.second=i;}
            right_max.push_back(tmp);
        }
        reverse(right_max.begin(), right_max.end());
        //three index i,j,k
        //fix the j
        //the left: [0,j-k]   the mid: [j]   the right:[j+k,len]
        pair<int,int> left({sums[0],0});
        pair<int,int> mid({sums[k],k});
        pair<int,int> right({sums[2*k],2*k});
        int global_sum=left.first+mid.first+right.first;
        
        for(int j=k;j<sums.size()-k;j++){
            
            //1.mid
            pair<int,int> temp_mid({sums[j],j});
            
            //2.left
            pair<int,int> temp_left=left_max[j-k];
          
            //3.right
            //get the max value in the right part
            pair<int,int> temp_right=right_max[j+k];
           
            
            int temp_sum=temp_left.first+temp_mid.first+temp_right.first;
            if(temp_sum>global_sum){
                global_sum=temp_sum;
                left=temp_left;
                mid=temp_mid;
                right=temp_right;
            }
            
            
            
        }
        vector<int> res;
        res.push_back(left.second);
        res.push_back(mid.second);
        res.push_back(right.second);
        return res;
        
    }

};

int main(){
    Solution mysolu;
    
    //[4,5,10,6,11,17,4,11,1,3]
    //1
    
    vector<int> input={4,5,10,6,11,17,4,11,1,3};
    
    //[1,2,1,2,6,7,5,1]
    //2
    vector<int> input2={1,2,1,2,6,7,5,1};
    
    vector<int> input3={1,2,1,2,2,2,2,2};
    //[1,2,1,2,2,2,2,2]
    //2
    
    //[17,9,3,2,7,10,20,1,13,4,5,16,4,1,17,6,4,19,8,3]
    //4
    vector<int> input4={17,9,3,2,7,10,20,1,13,4,5,16,4,1,17,6,4,19,8,3};
    vector<int> res=mysolu.maxSumOfThreeSubarrays(input4, 4);
    
    return 0;
}
