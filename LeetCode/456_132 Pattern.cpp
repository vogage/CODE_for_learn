//
//  456_132 Pattern.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/12/2.
//

#include <stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }
        int k = nums.size();
        for (size_t j = nums.size() - 1; j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            auto it = lower_bound(nums.begin() + k, nums.end(), min_array[j] + 1);
            k = it - nums.begin();
            if (k < nums.size() and nums[k] < nums[j]) {
                return true;
            }
            nums[--k] = nums[j];
        }
        return false;
    }
};


struct MyListNode{
    MyListNode* next;
    int left;
    int right;
    MyListNode(int n1,int n2):left(n1),right(n2){};
};

class Solution2 {
public:
    bool find132pattern(vector<int>& nums) {
        MyListNode *root=new MyListNode(INT_MIN,INT_MIN);
        root->next=new MyListNode(INT_MAX,INT_MAX);
        root->next->next=NULL;// if not put the end of a list pointer to nullptr
        //may produce the bug: member access within misaligned address
        
        if(nums.size()<3)return false;
        int first_element=nums[0];
        int second_element=INT_MIN;
        
        for(int i=1;i<nums.size();i++){
            if(is_in_list(root, nums[i])) return true;
            if(nums[i]<first_element){
                first_element=nums[i];
                second_element=INT_MIN;
            }else{
                if(nums[i]>second_element){
                    second_element=nums[i];
                    MyListNode* tmp_node=new MyListNode(first_element,second_element);
                    insert_list(root, tmp_node);
                }
            }
        }
        
        return false;
    }
    
    bool is_in_list(MyListNode* root,int tmp){
        while(root->next){
            if(root->left>=tmp) break;
            if(root->right<=tmp) {
                root=root->next;
                continue;
            }
            if(root->left<tmp&&root->right>tmp)return true;
            root=root->next;
        }
        return false;
    }
    
    void insert_list(MyListNode* root,MyListNode* tmp){
        MyListNode* leftnode=root;
        MyListNode* rightnode=root->next;
        
        while(leftnode->next&&leftnode->next->left<tmp->left){
            leftnode=leftnode->next;
            rightnode=rightnode->next;
        }
        
        while(rightnode->next&&rightnode->next->right<tmp->right){
            rightnode=rightnode->next;
        }
        
        
        // the temp interval is bigger than leftnode interval + rightnode interval
        if(tmp->left<=leftnode->left&&tmp->right>=rightnode->right){
            leftnode->left=tmp->left;
            leftnode->right=tmp->right;
            leftnode->next=rightnode->next;
        }
        
        // the temp interval is in the middle of leftnode interval and rightnode interval
        // the temp interval is in part in the leftnode interval but not overlap in the rightnode
        // the temp interval is in part in the rightnode interval but not overlap in the leftnode
        if(tmp->left>=leftnode->right&&tmp->right<=rightnode->left){
            tmp->next=rightnode;
            leftnode->next=tmp;
        }
        
        // the temp interval is bigger than leftnode interval
        if(leftnode->left>=tmp->left&&tmp->right>=leftnode->right){
            leftnode->left=tmp->left;
            leftnode->right=tmp->right;
        }
        
        // the temp interval is bigger than rightnode interval
        if(rightnode->left>=tmp->left&&rightnode->right<=tmp->right){
            rightnode->left=tmp->left;
            rightnode->right=tmp->right;
        }
        
        
    }
 
};


int main(){
    Solution mysolu;
    vector<int> nums={-1,3,2,0};
    vector<int> nums1={1,2,3,4};
    vector<int> nums2={1,0,1,-4,-3};
    vector<int> nums3={3,1,4,2};
    vector<int> nums4={3,5,0,3,4};
    vector<int> nums5={-2,1,2,-2,1,2};
    bool res=mysolu.find132pattern(nums2);
    return 0;
}
