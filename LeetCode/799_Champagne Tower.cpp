//
//  799_Champagne Tower.cpp
//  leetcode
//
//  Created by qiandehou on 2022/4/4.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>

using namespace std;

class glass{
public:
    glass():left(nullptr),right(nullptr),right_neighbor(nullptr),left_neighbor(nullptr),vol(0),IsFill(false){}
    glass *left;
    glass *right;
    glass *right_neighbor;
    glass *left_neighbor;
    double vol;
    bool IsFill;
};

int get_vol(glass &temp){//我觉得这里是传入了一个地址
    cout<<"&temp:   "<<&temp<<endl;
    
    glass *ptr=&temp;//因为仅传入了地址，并不知道该地址的对象结构，所以需要新建一个指针
    cout<<"&ptr:   "<<&ptr<<endl;
    return ptr->vol>1?(ptr->vol-1)/2:0;
}

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        glass *root=new glass();
        root->left=new glass();
        root->right=new glass();
        root->left->right_neighbor=root->right;
        root->right->left_neighbor=root->left;
        root->vol=poured;
        vector<glass*> pre;
        pre.push_back(root);
        pre.push_back(root->left);
        pre.push_back(root->right);
        
        int global_max_poured=poured;
        
        while(global_max_poured>1){
            global_max_poured=INT_MIN;
            vector<glass*> temp=pre;
            pre.clear();
            
            //cout<<"*temp[0]:   "<<*temp[0]<<endl;
            cout<<"temp[1]:    "<<temp[0]<<endl;
            cout<<"&temp[1]:   "<<&temp[0]<<endl;
            
            temp[0]->left=new glass();
            //这里我觉得是传入了一个指针所指的地址，该地址的结构与glass是对应的，所以无报错
            temp[0]->left->vol=get_vol(*temp[0]);
            temp[0]->right=new glass();
            temp[0]->right->vol=get_vol(*temp[0]);
            
            pre.push_back(temp[0]->left);
            pre.push_back(temp[0]->right);
            
            for(int i=1;i<temp.size();i++){
                temp[i]->left=temp[i-1]->right;
                temp[i]->left->vol+=get_vol(*temp[i]);
                temp[i]->right=new glass();
                temp[i]->right->vol=get_vol(*temp[i]);
                int n=temp[i]->left->vol;
                global_max_poured=max(global_max_poured,n);
            }
            
        }
        int yyyy=1;
        return 0;
    }
private:

};


class Solution2 {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(1,vector<double>(1,0));
        
        int layer=1;
        dp[0][0]=poured;
        while(layer<=query_row){
            int start=0;
            int end=layer;
            dp.push_back(vector<double>(layer+1,0));
            dp[layer][start]=dp[layer-1][start]>1?(dp[layer-1][start]-1)/2:0;
            dp[layer][end]=dp[layer-1][end-1]>1?(dp[layer-1][end-1]-1)/2:0;
            for(int i=start+1;i<end;i++){
                dp[layer][i]+=dp[layer-1][i-1]>1?(dp[layer-1][i-1]-1)/2:0;
                dp[layer][i]+=dp[layer-1][i]>1?(dp[layer-1][i]-1)/2:0;
            }
            layer++;
        }
        return dp[query_row][query_glass]>1?1:dp[query_row][query_glass];
    }

};

int main(){
    Solution mysolu;
    int poured=25;
    int query_row=6;
    int query_glass=1;
    
    double res=mysolu.champagneTower(poured, query_row, query_glass);
    
    return 0;
}
