//
//  949_Largest Time for Given Digits.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/7.
//

#include <stdio.h>
#include<string>
#include <vector>
#include <unordered_set>

using namespace std;
//void permutation(int list_[4], int start, int end)
//{
//    if(start>end)
//    {
//        for(int i=0;i<4;i++)cout<<list_[i];
//        cout<<endl;
//        N++;
//        return;
//    }
//    for(int i=start;i<=end;i++)
//    {
//        swap(list_[start],list_[i]);
//        permutation(list_, start+1,end);
//        swap(list_[start],list_[i]);
//    }
//}
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int res=-1;
        vector<int> resvec;
        permutate(arr, 0, arr.size()-1, res,resvec);
        if(res==-1)return "";
        else return ""+to_string(resvec[0])+to_string(resvec[1])+":"+to_string(resvec[2])+to_string(resvec[3]);
        
        
        
    }
private:
    void permutate(vector<int>& arr,int start,int end,int &res,vector<int>& resvec){
        if(start>end){
            if(arr[0]>2||(arr[0]==2&&arr[1]>4)||arr[2]>5) return;
            int temp=0;
            for(int i=0;i<arr.size();i++){
                temp=temp*10+arr[i];
            }
            if(temp>res) {res=temp;resvec=arr;}
            return;
        }
        for(int i=start;i<=end;i++){
            swap(start,i,arr);
            permutate(arr, start+1, end,res,resvec);
            swap(start,i,arr);
        }
    }
    
    void swap(int i,int j,vector<int>& arr){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    
    
};


int main(){
    Solution mysolu;
    vector<int> arr={0,0,0,0};
    vector<int> arr1={2,0,6,6};
    string res=mysolu.largestTimeFromDigits(arr1);
    
    return 0;
}
