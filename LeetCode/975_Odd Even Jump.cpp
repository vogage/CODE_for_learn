//
//  975_Odd Even Jump.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/6/2.
//

#include <stdio.h>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;



class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n=arr.size();
        vector<vector<bool>> reaches(n,vector<bool>(2,false));
        map<int,int> sort_vec;
        map<int,int,greater<int>> sort_vec_greater;
        reaches[n-1][0]=true;
        reaches[n-1][1]=true;
        sort_vec[arr[n-1]]=n-1;
        sort_vec_greater[arr[n-1]]=n-1;
        //sort_vec[INT_MAX]=n;
        //sort_vec[INT_MIN]=-1;
        
        int res=1;
        for(int i=n-2;i>=0;i--){
            //odd jump arr[j]>=arr[i] smallest possible value
           
            //upper_bound:greater than k
            //lower_bound:not less than k
            auto it1=sort_vec.lower_bound(arr[i]);
            if(it1!=sort_vec.end()) reaches[i][0]=reaches[it1->second][1];
            
            //even jump arr[j]<=arr[i] largest possible value
            auto it2=sort_vec_greater.lower_bound(arr[i]);
            if(it2!=sort_vec.end())reaches[i][1]=reaches[it2->second][0];
            
            sort_vec[arr[i]]=i;
            sort_vec_greater[arr[i]]=i;
            if(reaches[i][0]) res++;
        }
        return res;
    }
    
private:

};


int main(){
    Solution mysolu;
    vector<int> arr = {10,13,12,14,15};
    vector<int> arr1 = {2,3,1,1,4};
    vector<int> arr2={5,1,3,4,2};
    
    int res=mysolu.oddEvenJumps(arr1);
    return 0;
}
