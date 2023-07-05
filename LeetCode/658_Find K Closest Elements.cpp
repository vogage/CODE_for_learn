//
//  658_Find K Closest Elements.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/19.
//

#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct DNode{
    long long val;
    DNode* pre;
    DNode* next;
    DNode(long long x):val(x),pre(nullptr),next(nullptr){}
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        DNode *root=new DNode(INT_MIN);
        DNode *temp=root;
        DNode *xp=root;
        for(int i=0;i<arr.size();i++){
            temp->next=new DNode(arr[i]);
            temp->next->pre=temp;
            temp=temp->next;
            if(x>temp->val) xp=temp;
        }
        temp->next= new DNode(INT_MAX);
        DNode *begin=xp;
        DNode *end=xp->next;
        while(k>0){
            if((long long)x-begin->val<=end->val-(long long)x){
                begin=begin->pre;
            }else{
                end=end->next;
            }
            k--;
        }
        vector<int> res;
        xp=begin->next;
        while(xp!=end){
            res.push_back(xp->val);
            xp=xp->next;
        }
        return res;
    }
};

int main(){
    Solution mysolu;
//Input: arr = [1,2,3,4,5], k = 4, x = 3
//Output: [1,2,3,4]
    vector<int> nums={1,2,3,4,5};
    int k=4;
    int x=3;
    vector<int> res=mysolu.findClosestElements(nums, k, x);
    
    return 0;
}
