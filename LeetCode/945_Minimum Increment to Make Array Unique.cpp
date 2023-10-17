//
//  945_Minimum Increment to Make Array Unique.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/4.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    Node* next;
    int val;
    Node(int x):val(x),next(nullptr){}
    Node(int x,Node* p):val(x),next(p){}
};


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)return 0;
        Node* root=new Node(-1);
        Node* temp=root;
        for(int i=0;i<nums.size();i++){
            temp->next=new Node(nums[i]);
            temp=temp->next;
        }
        Node* cur=root;
        temp=root->next;
        while(temp->next&&(temp->next->val==temp->val||temp->val+1==temp->next->val))temp=temp->next;
        int res=0;
        while(cur->next){
            
           
           
            if(cur->next&&cur->val==cur->next->val){
                temp->next=new Node(temp->val+1,temp->next);
                res+=temp->next->val-cur->val;
                cur->next=cur->next->next;
                while(temp->next&&(temp->next->val==temp->val||temp->val+1==temp->next->val))temp=temp->next;
            }else{
                cur=cur->next;
                if(temp->next==cur) temp=temp->next;
                while(temp->next&&(temp->next->val==temp->val||temp->val+1==temp->next->val))temp=temp->next;
            }
           
        }
        return res;
    }
};
        
class Solution1 {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.size()<=0)return 0;
       
        int res=0;
        sort(nums.begin(),nums.end());
        int curmax=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=curmax){
                curmax=curmax+1;
                res+=curmax-nums[i];
            }else{
                curmax=nums[i];
            }
        }
        return res;
    }
};
        
class Solution2 {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,less<int>> pque;
        int res=0;
        if(nums.size()==1)return 0;
        pque.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=pque.top()){
                pque.push(pque.top()+1);
                res+=pque.top()-nums[i];
            }else{
                pque.push(nums[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> nums={3,2,1,2,1,7};
    vector<int> nums1={0,2,2,2};
    int res=mysolu.minIncrementForUnique(nums1);
    return 0;
}
