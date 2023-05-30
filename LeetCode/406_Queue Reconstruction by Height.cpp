//
//  406_Queue Reconstruction by Height.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/3/29.
//

#include <stdio.h>

#include<vector>
#include<algorithm>

using namespace std;

struct que_element{
    que_element* front;
    que_element* next;
    int high;
    int numFront;
    que_element(int h,int n):high(h),numFront(n),front(nullptr),next(nullptr){};
};

bool cmp(vector<int> &p1,vector<int>& p2){
    return p1[0]==p2[0]?p1[1]<p2[1]:p1[0]>p2[0];
    
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> que;
        que_element* root=new que_element(0,0);
        sort(people.begin(),people.end(),cmp);
        for(int i=0;i<people.size();i++){
            que_element* tmp=root;
            int cout=people[i][1];
            while(tmp&&cout){tmp=tmp->next;cout--;}
            que_element* tmpnext=tmp->next;
            tmp->next=new que_element(people[i][0],people[i][1]);
            tmp->next->next=tmpnext;
        }
        que_element* tmp2=root;
        while(tmp2->next){
            tmp2=tmp2->next;
            que.push_back(vector<int>{tmp2->high,tmp2->numFront});
        }
        return que;
    }
};

int main(){
    vector<vector<int>> people={{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution mysolu;
    vector<vector<int>> res=mysolu.reconstructQueue(people);
    return 0;
}
